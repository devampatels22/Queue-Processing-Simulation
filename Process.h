//-----------------------------------------
// NAME		: Devam Patel 
// STUDENT NUMBER	: 7859163
// COURSE		: COMP 2150
// INSTRUCTOR	: Mike
// ASSIGNMENT	: assignment # 2
// 
// REMARKS: This program holds the Process; arrivalTime, processId, cpu and Io bursts, exitTime and waitTime.
//			it holds a queue that stores all cpu and io bursts
//-----------------------------------------
#pragma once
#include "ListItem.h"

class Queue;
class Bursts;
class Process : public ListItem
{
private:
	
	int processNum; //processId
	int arrival; //arrivalTIme
	int waitTime; //waitTIme
	Queue* burstListCpu; //CpuBurst
	Queue* burstListIo; //IoBurst
	int curCPUBurst; //currentCpuBurst
	int curIOBurst; //currIoBurst
	int lastTimeProcessed; //simulation time when last process was done on this process
	int exitTime; //exitTime


public:
	Process(int, int, int); //proceessNumber, arrivalTIme, waitTime

	//getts and setters for the all the varibles declared as private
	int getProcessNum();
	int getArrival();
	int getWaitTime();
	void addWaitTime(int);

	void addBurstsCPU(int);
	void addBurstIO(int);
	int getBurstCpu();//removes burst from the queue and returns it
	int getBurstIO(); //removes Io burst from the queue and returns it

	int getCurCPUBurst();
	void setCurCPUBurst(int);
	int getCurIOBurst();
	void setCurIOBurst(int);
	

	bool isBurstListCpuEmpty();
	bool isBurstListIOEmpty();
	int getLastTimeProcessed();
	void setLastTimeProcessed(int);
	void setExitTime(int);
	int getExitTime();
	
	int compareTo(ListItem* other);


	~Process();
};