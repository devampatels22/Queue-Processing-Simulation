//-----------------------------------------
// NAME		: Devam Patel 
// STUDENT NUMBER	: 7859163
// COURSE		: COMP 2150
// INSTRUCTOR	: Mike
// ASSIGNMENT	: assignment # 2
// 
// REMARKS: The purpose of this program is to start a Cpu Burst
//			will proceed according to if the cpu burst is less than Max CPu Burst create CompleteCPU event
//			else it will create a timeOut event because it was not able to complete the burst
//			
//-----------------------------------------
#include <iostream>
#include "StartCpu.h"
#include "CompleteCpu.h"
#include "Timeout.h"
#include "Simulation.h"
#include "Process.h"

//StratCpu Constructor
StartCpu :: StartCpu(Process* p, int t, Simulation* sim ) : Event(t, p, sim) , timeAvail(sim->getMaxCpuBurst()) , cpuBurst(getProcess()->getCurCPUBurst())
{}

void StartCpu::handleEvent() {
	sim->setSimulationTime(getArrivalTime());
	sim->setCpuBusy(true);
	Process* p = getProcess();
	if (cpuBurst > timeAvail) 
	{
		cout << "Time " << sim->getSimulationTime() << ": Process " << getProcess()->getProcessNum() << " begins Cpu burst (will time out; " << cpuBurst << " units total)" << endl;
		decisionTimeOut();
	} 
	else
	{
		cout << "Time " << sim->getSimulationTime() << ": Process " << getProcess()->getProcessNum() << " begins Cpu burst (will complete all; " << cpuBurst << " remaining units)" << endl;
		decisionCompCpu();
	}
}

//decisionComCPu
void StartCpu::decisionCompCpu()
{
	CompleteCpu* cCpu = new CompleteCpu(getProcess(), (sim->getSimulationTime() + cpuBurst), sim);
	
	sim->addEvent(cCpu);
	
}

//decisionTimeOut
void StartCpu::decisionTimeOut() 
{
	
	Timeout* tOut = new Timeout(getProcess(),( sim->getSimulationTime() + timeAvail), sim);
	
	sim->addEvent(tOut);
	
}

//destructor
StartCpu::~StartCpu() {}

