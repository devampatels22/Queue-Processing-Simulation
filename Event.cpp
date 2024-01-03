//-----------------------------------------
// NAME		: Devam Patel 
// STUDENT NUMBER	: 7859163
// COURSE		: COMP 2150
// INSTRUCTOR	: Mike
// ASSIGNMENT	: assignment # 2
// 
// REMARKS: This program is a praent class for all the events 
//-----------------------------------------
#include "Event.h"
#include "Arrival.h"
#include "Timeout.h"

/**** Event implementation */
Event::Event(int theTime, Process* theProcess, Simulation* sim)
	:eventTime(theTime), process(theProcess), sim(sim) {}

Event::~Event() {}

int Event::getArrivalTime() { return eventTime; }

Process* Event::getProcess() { return process; }

int Event::compareTo(ListItem* other) {
	Event* e = dynamic_cast<Event*>(other);
	if (((this->eventTime - e->eventTime) < 0) || ((this->eventTime - e->eventTime) > 0)) {
		return this->eventTime - e->eventTime;
	}
	else if ((this->eventTime - e->eventTime) == 0)
	{
		if ((dynamic_cast<Arrival*>(this) != nullptr) && (dynamic_cast<Timeout*>(e) != nullptr))
		{
			return -1;
		}
		else if ((dynamic_cast<Timeout*>(this) != nullptr) && (dynamic_cast<Arrival*>(e) != nullptr))
		{
			return +1;
		}
		else
		{
			return +1;
		}
	}
	return 0;
	//might need to change this in the future for compareTO work properly.
}

