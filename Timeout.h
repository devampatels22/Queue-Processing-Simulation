//-----------------------------------------
// NAME		: Devam Patel 
// STUDENT NUMBER	: 7859163
// COURSE		: COMP 2150
// INSTRUCTOR	: Mike
// ASSIGNMENT	: assignment # 2
// 
// REMARKS: The purpose of this program is to add the process in the queue 
// 			since cpu could not finish the burst
//-----------------------------------------
#pragma once
#include "Event.h"

class Timeout : public Event
{

public:
	Timeout(Process*, int, Simulation*);//Constructor
	virtual void handleEvent(); //adds process to the cpuQueue if cpuBurst is busy or starts cpu process right away
	~Timeout(); //destructure
};