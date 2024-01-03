//-----------------------------------------
// NAME		: Devam Patel 
// STUDENT NUMBER	: 7859163
// COURSE		: COMP 2150
// INSTRUCTOR	: Mike
// ASSIGNMENT	: assignment # 2
// 
// REMARKS: The purpose of this program is process each arrival that take place when 
//			line are being read from the file. if cpuis Busy it will add the processs in the queue
//			if its not busy it will create a startCpu event to procees.
//-----------------------------------------
#include <iostream>
#include "Arrival.h"
#include "StartCpu.h"
#include "Process.h"
#include "Simulation.h"

//Arrival Constructor
Arrival::Arrival(Process* p, int time, Simulation* sim): Event(time, p , sim)
{}

//HandleEvent
void Arrival::handleEvent()
{
	
	sim->setSimulationTime(getArrivalTime());
	if (getProcess()->getCurCPUBurst() == 0)
	{
		getProcess()->setCurCPUBurst(getProcess()->getBurstCpu());
	}
	if (getProcess()->getCurIOBurst() == 0) {
		getProcess()->setCurIOBurst(getProcess()->getBurstIO());
	}
	if (!sim->isCpuBusy()) 
	{
		startCpuEvent();
	} 
	else //if cpu is busy
	{
		startCpuPending();
	}
	sim->getNextArrival();
}

//startCpuEvent
void Arrival::startCpuEvent() 
{	
	
	cout << "Time " << sim->getSimulationTime() << ": Process " << getProcess()->getProcessNum() << " arrives in system: CPU is free (process begins execution)" << endl;
	StartCpu* sCpu = new StartCpu(getProcess(), sim->getSimulationTime(), sim);
	sim->addEvent(sCpu);
	
}

//StartCPuPending
void Arrival::startCpuPending() 
{
	cout << "Time " << sim->getSimulationTime() << ": Process " << getProcess()->getProcessNum() << " arrives in system: CPU is busy (process will be queued)" << endl;
	sim->addCpu(getProcess()); //adding process into cpuQueue for waiting.
}
//destructor
Arrival :: ~Arrival() {}