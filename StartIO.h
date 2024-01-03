//-----------------------------------------
// NAME		: Devam Patel 
// STUDENT NUMBER	: 7859163
// COURSE		: COMP 2150
// INSTRUCTOR	: Mike
// ASSIGNMENT	: assignment # 2
// 
// REMARKS: The purpose of this program is to process a IOburst and schedule a completeIOburst Event
//			is a child class of Event
//-----------------------------------------
#pragma once
#include "Event.h"
#include "CompleteIO.h"

class StartIO : public Event
{

public:
	StartIO(Process*, int, Simulation*); //COntructor
	virtual void handleEvent(); //processes current IO Burst and schedules a CompleteIO Event
	~StartIO(); //destructor


};