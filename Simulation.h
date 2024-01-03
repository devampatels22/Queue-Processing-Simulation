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

#pragma once

#include <fstream>
using namespace std;

class PriorityQueue;
class Queue;
class Event;
class Process;

class Simulation {
private:
	// you will need to add fields
    // including: Queues for CPU and IO, and priority queues for Events 


	fstream infile; // input file to read.
	int simulationTime; //current simulation Time 
	PriorityQueue* eventList; 
	Queue* processQueue; //holds the processes to print the summary
	Queue* cpuQueue; //holds the cpuQueue
	Queue* ioQueue; //holds the ioQueue
	int maxCpuBurst; //gets the maxCPUBurst allowed in the file
	bool cpuBusy; //cpu status
	bool iOBusy; //io status
	int procNum; //process number
	


public:

	Simulation();
	// runSimulation -- start the simulation with the given filename.
	// Called by main.
	void runSimulation(char* fileName);

	// summary -- print a summary of all the processes, as shown in the
	// assignment.  Called by main.
	void summary();

	// you may need to add more methods
	void addEvent(Event* e);

	//CPU Queue and IO Queue Enquing, dequing and checking isEmpty()
	void addCpu(Process* p);
	void addIO(Process* p);
	Process* dequeueProcCpuQueue();
	Process* dequeueProcIOQueue();
	bool isCpuQueueEmpty();
	bool isIoQueueEmpty();

	//getters and setters CPU and IO Status
	bool isCpuBusy();
	void setCpuBusy(bool);
	bool isIoBusy();
	void setIoBusy(bool);

	void getNextArrival(); //read next arrival from the file and add it to the event queue.
	int getSimulationTime(); //return current simulation time
	void setSimulationTime(int); //set current simulation time
	int getMaxCpuBurst(); // return max cpu burst allowed
	void addProcess(Process* p); //add process in the Queue for print summary

};// class Simulation
