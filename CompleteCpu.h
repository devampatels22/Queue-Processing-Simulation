//-----------------------------------------
// NAME		: Devam Patel 
// STUDENT NUMBER	: 7859163
// COURSE		: COMP 2150
// INSTRUCTOR	: Mike
// ASSIGNMENT	: assignment # 2
// 
// REMARKS: The purpose of this program is to procees CompleteCpu Event
//			if IO burst exist it will create a StartIO event
//			if no Io burst exist than it will create Exit event
//-----------------------------------------
#pragma once

#include "Event.h"

class CompleteCpu : public Event
{
private:
	void decisionExit(); //creating a Exit event
	void decisionIO(); //creating a StartIo event

public:
	CompleteCpu(Process* , int, Simulation*); //constructor
	virtual void handleEvent(); //if IO burst exist it will create startIo event if not it will create Exit event
	~CompleteCpu(); //destructor
};