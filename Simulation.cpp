
//-----------------------------------------
// NAME		: Devam Patel 
// STUDENT NUMBER	: 7859163
// COURSE		: COMP 2150
// INSTRUCTOR	: Mike
// ASSIGNMENT	: assignment # 2
// 
// REMARKS: The purpose of this program is to run the simulation
//			that is being called in the main class.
//			This class keeps track for Process Queue, IOQueue and CPUQueue.
//			It handles all the events that are created and added in the priorityQueue EventList.
//-----------------------------------------
#include "Simulation.h"
#include "PriorityQueue.h"
#include "Process.h"
#include "Arrival.h"
#include "Queue.h"
#include "Process.h"

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

//Constructor
Simulation::Simulation()
{
	simulationTime = 0;
	eventList = new PriorityQueue;
	processQueue = new Queue;
	cpuQueue = new Queue;
	ioQueue = new Queue;
	
	setCpuBusy(false);
	setIoBusy(false);
	procNum = 0;
}

//runs the simulation of whatever file is being passed in the parameter
void Simulation::runSimulation(char* fileName)
{
	infile.open(fileName);

	//get input for the maximum cpuBurst
	infile >> maxCpuBurst;
	string line;
	getline(infile, line);
	getNextArrival();

	//running until no events are left
	while (!eventList->isEmpty())
	{
		Event* e = eventList->deleteTop();
		e->handleEvent();
		delete(e);//delete event needs to occur only when the event has been completed
	}
	infile.close();
}

//prints the summary for all the processes stored in the processQueue
void Simulation::summary()
{
	//Print the Summary here.
	//Printe the final summary of all processQueue with arrival time exit time and wait time per process.
	cout << "\n*******All Processes completed. FINAL SUMMARY:********\n" << endl;
	cout << "\n    Process      Arrival      Exit      Wait" << endl;
	cout << "\n          #         Time      Time      Time" << endl;
	cout << "\n--------------------------------------------------------" << endl;
	while (!processQueue->isEmpty())
	{
		Process* fp = dynamic_cast<Process*>(processQueue->dequeue());
		cout << "\n          " << fp->getProcessNum() << "         " << fp->getArrival()<<"       "<<fp->getExitTime()<<"        " << fp->getWaitTime()<< endl;
		delete(fp);
	}
}

//adds Event in the PriorityQueue EventList
void Simulation::addEvent(Event* e)
{
	eventList->insert(e);
}

//adds Process in the ProcessQueue 
void Simulation::addProcess(Process* p)
{
	processQueue->enqueue(p);
}

//adds Process that are pending to start in CPUQueue
void Simulation::addCpu(Process* p)
{
	p->setLastTimeProcessed(getSimulationTime()); //recording time before p was added in the queue
	cpuQueue->enqueue(p);
}

//adds Process that are pending to start i IOQueue 
void Simulation::addIO(Process* p)
{
	p->setLastTimeProcessed(getSimulationTime()); //recording time beofore p was added in the queue
	ioQueue->enqueue(p);
}

//gets next process that is stored in the line
void Simulation::getNextArrival()
{
	string line;

	if (getline(infile, line)) {
		
		istringstream iss(line);
		int stuff;
		procNum++;
		int count = 0;
		int arrTime = 0;
		Process* pro = nullptr;
		while (iss >> stuff) {
			if (count == 0) {
				//cout << stuff << endl;
				arrTime = stuff;
				pro = new Process(procNum, stuff, 0);//creating process with arrival time and pNUm
				
			}
			else if (count % 2 == 1){
				//cout << cpuB << endl;
				pro->addBurstsCPU(stuff);
			}
			else if (count % 2 == 0)
			{
				//cout << ioB << endl;
				pro->addBurstIO(-stuff);
			}
			count++;
		}
		addProcess(pro);
		Arrival* arr = new Arrival(pro, arrTime, this);
		addEvent(arr);
	}
}

//returns the simulation time that the simulation is currently on
int Simulation::getSimulationTime()
{
	return simulationTime;
}

//sets current simulation to what is being passed in the parameter
void Simulation::setSimulationTime(int time)
{
	simulationTime = time;
}

//returns Maximum CPu Burst that is available
int Simulation::getMaxCpuBurst()
{
	return maxCpuBurst;
}

//dequeues process from Cpu Queue and returns it
Process* Simulation::dequeueProcCpuQueue()
{
	Process* p = dynamic_cast<Process*>(cpuQueue->dequeue());
	p->addWaitTime(getSimulationTime() - p->getLastTimeProcessed()); //adding waitTime to the process
	return p;
}

//returns process from IO queue and returns it
Process* Simulation::dequeueProcIOQueue()
{
	Process* p = dynamic_cast<Process*>(ioQueue->dequeue());
	p->addWaitTime(getSimulationTime() - p->getLastTimeProcessed()); //adding wait time to the process
	return p;
}

//returns boolean according to if the CPUQueue is empty 
bool Simulation::isCpuQueueEmpty()
{
	return cpuQueue->isEmpty();
}
//returns boolean if hte IOqueue is empty
bool Simulation::isIoQueueEmpty()
{
	return ioQueue->isEmpty();
}

//Getters and setters regarding the status of cpu and IO 
//if they are busy or not
bool Simulation::isCpuBusy()
{
	return cpuBusy;
}
void Simulation::setCpuBusy(bool b)
{
	cpuBusy = b;
}
bool Simulation::isIoBusy() 
{
	return iOBusy;
}
void Simulation::setIoBusy(bool b)
{
	iOBusy = b;
}