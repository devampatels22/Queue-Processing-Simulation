//-----------------------------------------
// NAME		: Devam Patel 
// STUDENT NUMBER	: 7859163
// COURSE		: COMP 2150
// INSTRUCTOR	: Mike
// ASSIGNMENT	: assignment # 2
// 
// REMARKS: This program is a Exit event class it sets the exit time of the porcess
//-----------------------------------------
#pragma once
#include "Event.h"

class Exit : public Event
{

public:
	Exit(Process*, int, Simulation*); //constructor
	virtual void handleEvent();//sets exit time for that process
	~Exit(); //destructor
};