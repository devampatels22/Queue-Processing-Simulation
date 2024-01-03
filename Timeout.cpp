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

#include "Timeout.h"
#include "StartCpu.h"
#include "Simulation.h"
#include "iostream"
#include "Process.h"

//Timeout
Timeout::Timeout(Process* p, int t, Simulation* sim) :Event(t, p, sim)
{}

//handleEvent
void Timeout::handleEvent()
{
	sim->setSimulationTime(getArrivalTime());
	Process* cp = getProcess();
	getProcess()->setCurCPUBurst(cp->getCurCPUBurst() - sim->getMaxCpuBurst()); //updates to the remaining cpuBurst that are left for this process.
	sim->setCpuBusy(false);
	
	cout << "Time " << sim->getSimulationTime() << ": Process " << cp->getProcessNum() << " times out (needs " << (cp->getCurCPUBurst()) << " units more)" << endl;
	sim->addCpu(cp);//adding process in the queue again

	//waits for another turn in the cpu.
	// checking the queue of waiting processes to see if another process needs to start execution.
	if (!sim->isCpuQueueEmpty() && !sim->isCpuBusy()) {

		Process* p = sim->dequeueProcCpuQueue(); //dequeue from cpuQueue
		StartCpu* sCpu = new StartCpu(p, sim->getSimulationTime(), sim);
		sim->addEvent(sCpu);
		//sim->setCpuBusy(true);

	}
}
//destructor
Timeout::~Timeout()
{}