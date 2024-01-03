//-----------------------------------------
// NAME		: Devam Patel 
// STUDENT NUMBER	: 7859163
// COURSE		: COMP 2150
// INSTRUCTOR	: Mike
// ASSIGNMENT	: assignment # 2
// 
// REMARKS: The purpose of this program is to start a Cpu Burst
//			will proceed according to if the cpu burst is less than Max CPu Burst create CompleteCPU event
//			else it will create a timeOut event because it was not able to complete the burst
//			
//-----------------------------------------
#pragma once
#include "Event.h"

class StartCpu : public Event
{
private: 
	int timeAvail; //Stores max CpuBurst allwed
	int cpuBurst; //Stores current cpu burst of the process
	void decisionCompCpu(); //proceed to completeCpu Event if cpuBurst was able to finish
	void decisionTimeOut(); //proceed to decisionTimeout if the cpuburt was not able to finish

public: 
	StartCpu(Process*, int, Simulation* ); //constructor
	virtual void handleEvent(); //handle event accordingly
	~StartCpu();//destructor
};