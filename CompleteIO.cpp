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
#include "CompleteIO.h"
#include "Simulation.h"
#include "Exit.h"
#include "Process.h"
#include "StartIO.h"
#include "StartCpu.h"
#include <iostream>

//constructor
CompleteIO::CompleteIO(Process* p, int t, Simulation* sim) :Event(t, p, sim)
{}

//handleEvent
void CompleteIO::handleEvent()
{
	//checking to see if the CPU list burst is not empty and setcurCPUBurst 
	sim->setSimulationTime(getArrivalTime());
	sim->setIoBusy(false);
	if (!getProcess()->isBurstListCpuEmpty()) {
		cout << "Time " << sim->getSimulationTime() << ": Process " << getProcess()->getProcessNum() << " completes I/O burst. Now Starting Cpu Burst" << endl;
		getProcess()->setCurCPUBurst(getProcess()->getBurstCpu());
		sim->addCpu(getProcess()); //adding process into cpuQueue for waiting.
	}
	else //create a exit even because there is no cpuBurst (assumed no Io burst)
	{
		cout << "Time " << sim->getSimulationTime() << ": Process " << getProcess()->getProcessNum() << " completes I/O burst. Now Exiting" << endl;
		Exit* ext = new Exit(getProcess(), sim->getSimulationTime(), sim);
		sim->addEvent(ext);
	}

	//checking to see if process has another io burst in ioBurstQueue
	if (!getProcess()->isBurstListIOEmpty())
	{
		getProcess()->setCurIOBurst(getProcess()->getBurstIO());
	}

	//checking if cpuQueue is not empty and cpu is not busy;
	//than dequeue the following process
	if (!sim->isCpuQueueEmpty() && !sim->isCpuBusy()) {
		Process* p = sim->dequeueProcCpuQueue(); //dequeue from cpuQueue
		StartCpu* sCpu = new StartCpu(p, sim->getSimulationTime(), sim);
		sim->addEvent(sCpu);
		
	}

	


	if (!sim->isIoQueueEmpty() && !sim->isIoBusy())
	{
		Process* p = sim->dequeueProcIOQueue(); //dequeue from IOQueue
		StartIO* sIo = new StartIO(p, sim->getSimulationTime(), sim);
		sim->addEvent(sIo);
		
	}
}


//destructor
CompleteIO::~CompleteIO() {}
