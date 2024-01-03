//-----------------------------------------
// NAME		: Devam Patel 
// STUDENT NUMBER	: 7859163
// COURSE		: COMP 2150
// INSTRUCTOR	: Mike
// ASSIGNMENT	: assignment # 2
// 
// REMARKS: The purpose of this program is process a completeIo event
//			if next cpuBurst exist call startCpu event or add to cpuQueue if busy
//			if no Burst exist than create a Exit event
//-----------------------------------------
#pragma once
#include "Event.h"

class CompleteIO : public Event
{

public:
	CompleteIO(Process*, int, Simulation*); //constructor
	virtual void handleEvent(); //handles event accordingly
	~CompleteIO(); //destructor


};