//-----------------------------------------
// NAME		: Devam Patel 
// STUDENT NUMBER	: 7859163
// COURSE		: COMP 2150
// INSTRUCTOR	: Mike
// ASSIGNMENT	: assignment # 2
// 
// REMARKS: This program is a Exit event class it sets the exit time of the porcess
//-----------------------------------------
#include "Exit.h"
#include "Process.h"
#include "Simulation.h"

//constructor
Exit::Exit(Process* p, int t, Simulation* sim) :Event(t, p, sim)
{}

//handleEvent
void Exit::handleEvent()
{
	sim->setSimulationTime(getArrivalTime());
	 getProcess()->setExitTime(sim->getSimulationTime());
	//sim->addProcess(p);

}

//destructor
Exit::~Exit()
{}