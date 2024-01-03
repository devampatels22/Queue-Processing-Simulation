//-----------------------------------------
// NAME		: Devam Patel 
// STUDENT NUMBER	: 7859163
// COURSE		: COMP 2150
// INSTRUCTOR	: Mike
// ASSIGNMENT	: assignment # 2
// 
// REMARKS: This program holds the Process; arrivalTime, processId, cpu and Io bursts, exitTime and waitTime.
//			it holds a queue that stores all cpu and io bursts
//-----------------------------------------
#include "Process.h"
#include "Queue.h"
#include "Bursts.h"

//constructor
Process::Process(int pNum, int a, int w) :processNum(pNum), arrival(a), waitTime(w) 
{
	burstListCpu = new Queue;
	burstListIo = new Queue;
	curCPUBurst = 0;
	curIOBurst = 0;
	lastTimeProcessed = 0;
	exitTime = 0;
}

//getProcessNum
int Process::getProcessNum() {
	return processNum;
}
//getArrival
int Process::getArrival() {
	return arrival;
}

//getWaitTime
int Process::getWaitTime(){
	return waitTime;
}

//addWaitTime
void Process::addWaitTime(int w){
	waitTime = waitTime + w;
}

//addBurstsCPU
void Process::addBurstsCPU(int c)
{
	Bursts* b = new Bursts(c);
	burstListCpu->enqueue(b);
}

//addBurstIO
void Process::addBurstIO(int i)
{
	Bursts* b = new Bursts(i);
	burstListIo->enqueue(b);
}

//getBurstCpu
int Process::getBurstCpu()
{
	if (!burstListCpu->isEmpty())
	{
		Bursts* b = dynamic_cast<Bursts*>(burstListCpu->dequeue());
		return (b->getBurst());
	}
	else
	{
		return 0;
	}
}

//getBurstIO
int Process::getBurstIO() 
{
	if (!burstListIo->isEmpty())
	{
		Bursts* b = dynamic_cast<Bursts*>(burstListIo->dequeue());
		return (b->getBurst());
	}
	else
	{
		return 0;
	}
}

//getCurCPUBurst
int Process::getCurCPUBurst()
{
	return curCPUBurst;
}

//setCurCPUBurst
void Process::setCurCPUBurst(int c)
{
	curCPUBurst = c;
}

//getCurIOBurst
int Process::getCurIOBurst()
{
	return curIOBurst;
}

//setCurIOBurst
void Process::setCurIOBurst(int i)
{
	curIOBurst = i;
}

//isBurstListCpuEmpty 
bool Process::isBurstListCpuEmpty()
{
	return burstListCpu->isEmpty();
}

//isBurstListIOEmpty
bool Process::isBurstListIOEmpty()
{
	return burstListIo->isEmpty();
}

//getLastTimeProcessed
int Process::getLastTimeProcessed()
{
	return lastTimeProcessed;
}

//setLastTimeProcessed
void Process::setLastTimeProcessed(int r)
{
	lastTimeProcessed = r;
}

//setExitTime
void Process::setExitTime(int x)
{
	exitTime = x;
}

//getExitTime
int Process::getExitTime()
{
	return exitTime;
}

//compareTo
int Process::compareTo(ListItem* other)
{
	return -1;
}
//destructor
Process::~Process()
{}
