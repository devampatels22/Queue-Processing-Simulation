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
#pragma once
#include "Event.h"

class ListItem;

class Arrival : public Event {

private:
	void startCpuEvent(); //creates a startCpu Event
	void startCpuPending(); //adds the procees in the CPUQueue since cpu is busy

public: 
	Arrival(Process*, int, Simulation*); //constructor
	~Arrival(); //destructor
	virtual void handleEvent(); //handleEvent procees arrival accordingly
};