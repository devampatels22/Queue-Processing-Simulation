//-----------------------------------------
// NAME		: Devam Patel 
// STUDENT NUMBER	: 7859163
// COURSE		: COMP 2150
// INSTRUCTOR	: Mike
// ASSIGNMENT	: assignment # 2
// 
// REMARKS: This program is a praent class for all the events 
//-----------------------------------------
#pragma once
#include "ListItem.h"
class Process;
class Simulation;
#include <string>
using namespace std;

class Event: public ListItem {
private:
	int eventTime;
	Process *process;
protected:
	Simulation *sim;
public:
	// constructor, with pointer to the process that is being handled, and the simulation.
	Event(int theTime, Process *theProcess, Simulation* sim); 

	// pure virtual method - to handle the current event when it is removed from the queue.
	virtual void handleEvent() = 0; //pure virtual method
	virtual ~Event(); //destructor
	int getArrivalTime(); //returns arrival time of the event
	Process* getProcess(); //returns the process that is stored for this event
	// compareTo - used to order Events. 
	int compareTo(ListItem *other);
	//string title();
};// class Event
