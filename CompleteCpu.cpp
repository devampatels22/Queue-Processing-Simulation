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
#include <iostream>
#include "CompleteCpu.h"
#include "Simulation.h"
#include "StartIO.h"
#include "StartCpu.h"
#include "Exit.h"
#include "Process.h"

//be sure to checkif process are waiting their turn to execute on the CPU and scedule
//first one to the start execution on the queue
CompleteCpu::CompleteCpu(Process* p, int t, Simulation* sim) : Event(t, p, sim)
{}

//handleEvent
void CompleteCpu::handleEvent()
{
	sim->setSimulationTime(getArrivalTime());
	getProcess()->setCurCPUBurst(0);
	sim->setCpuBusy(false);
	if (getProcess()->getCurIOBurst() != 0) {
		decisionIO();
	}
	else //exit the cpu (assumed no other bursts exist)
	{
		decisionExit();
	}

	if (!sim->isCpuQueueEmpty() && !sim->isCpuBusy())
	{
		Process* p = sim->dequeueProcCpuQueue(); //dequeue from cpuQueue
		StartCpu* sCpu = new StartCpu(p, sim->getSimulationTime(), sim);
		sim->addEvent(sCpu);
	}
}

//decisionIo
void CompleteCpu::decisionIO()
{
	cout << "Time " << sim->getSimulationTime() << ": Process " << getProcess()->getProcessNum() << " completes CPU burst. Queueing for I/O." << endl;
	if (!sim->isIoBusy() )
	{
		StartIO* si = new StartIO(getProcess(), sim->getSimulationTime(), sim);
		sim->addEvent(si);
	}
	else 
	{
		sim->addIO(getProcess());
	}

}

//decisionExit
void CompleteCpu::decisionExit()
{
	cout << "Time " << sim->getSimulationTime() << ": Process " << getProcess()->getProcessNum() << " completes CPU burst. Now Exiting" << endl;
	Exit* ext = new Exit(getProcess(), sim->getSimulationTime(), sim);
	sim->addEvent(ext);
}

//destructor
CompleteCpu::~CompleteCpu() {}