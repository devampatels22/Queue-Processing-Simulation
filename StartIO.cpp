//-----------------------------------------
// NAME		: Devam Patel 
// STUDENT NUMBER	: 7859163
// COURSE		: COMP 2150
// INSTRUCTOR	: Mike
// ASSIGNMENT	: assignment # 2
// 
// REMARKS: The purpose of this program is to process a IOburst and schedule a completeIOburst Event
//-----------------------------------------
#include "StartIO.h"
#include "Simulation.h"
#include "CompleteIO.h"
#include "Process.h"
#include "iostream"

//StartIO constructor
StartIO::StartIO(Process* p, int t, Simulation* sim):Event(t, p, sim)
{}

//handle Event
void StartIO::handleEvent()
{
	sim->setSimulationTime(getArrivalTime());
	sim->setIoBusy(true);
	cout << "Time " << sim->getSimulationTime() << ": Process " << getProcess()->getProcessNum() << " begins I/O burst of length " << getProcess()->getCurIOBurst()<< "." << endl;
	CompleteIO* cio = new CompleteIO(getProcess(), getArrivalTime() + (getProcess()->getCurIOBurst()), sim);
	getProcess()->setCurIOBurst(0); 
	sim->addEvent(cio);
	//starts the io operation
	//not time shared completes in one instance.
	//always need to schedule a completeIO burst because it will always complete.
}

//destructor
StartIO::~StartIO()
{}