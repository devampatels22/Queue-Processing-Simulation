//Devam Patel 7859163
//COMP 2150 A2
//Tests - the test cases for the program

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "PriorityQueue.h"
#include "Arrival.h"
#include "Simulation.h"
#include "Process.h"
#include "StartCpu.h"

TEST_CASE("Priority Queue functions", "[priorityQueue]")
{
	PriorityQueue* pq = new PriorityQueue;

	//check empty priority Queue
	SECTION("Initial size should be zero and should be empty, and top should be nullptr.")
	{
		REQUIRE(pq->getSize() == 0);
		REQUIRE(pq->isEmpty() == true);
		REQUIRE(pq->getTop() == nullptr);
	}

	Simulation* sim = new Simulation;
	Process* p = new Process(1,2,0);
	Arrival* arr = new Arrival(p, 2, sim);
	Process* p2 = new Process(2, 3, 0);
	StartCpu* sp = new StartCpu(p2,3,sim);
	Process* p3 = new Process(3, 0, 0);
	Arrival* arr3 = new Arrival(p3, 0, sim);
	Process* p4 = new Process(4, 7, 0);
	Arrival* arr4 = new Arrival(p4, 7, sim);
	PriorityQueue* pq2 = new PriorityQueue();
	Process* p5 = new Process(5, 2, 0);
	Arrival* arr1 = new Arrival(p5, 2, sim);
	Process* p6 = new Process(6, 4, 0);
	Arrival* arr2 = new Arrival(p6, 4, sim);

	//check priority queue after one event is added
	SECTION("The priority Queue should not be empty and size should change. ")
	{
		pq->insert(arr);
		REQUIRE(pq->isEmpty() == false);
		REQUIRE(pq->getSize() == 1);
	}

	//check the getTop function
	SECTION("The priority Queue should return the arrival event as the top one.")
	{
		pq->insert(arr);
		Arrival* a = dynamic_cast<Arrival*>(pq->getTop());
		REQUIRE(a != nullptr);
		REQUIRE(a->compareTo(arr) == +1);
	}

	//Check insert of different event types in the same priority queue
	SECTION("Priority Queue should allow multiple types of events to be inserted the queue.")
	{
		pq->insert(arr);
		pq->insert(sp);
		REQUIRE(pq->getSize() == 2);
	}

	//Check that it inserts in the correct position
	SECTION("Priority Queue should insert at the very front if the time is earlier than all other events.")
	{
		pq->insert(arr);
		pq->insert(sp);
		pq->insert(arr3);
		REQUIRE(pq->getTop()->compareTo(arr3) == +1);
	}

	//Check that it inserts in the correct position
	SECTION("The top event should still be the arrival of p3 at time 0, if we add an event that happens later.")
	{
		pq->insert(arr);
		pq->insert(sp);
		pq->insert(arr3);
		pq->insert(arr4);
		REQUIRE(pq->getTop()->compareTo(arr3) == +1);
	}

	//Checking if priority queue is correctly emptied after all items are deleted
	SECTION("Deleting the last item and check that top is nullptr, size is 0 and queue is empty.")
	{
		pq2->insert(arr1);
		pq2->insert(arr2);
		pq2->deleteTop();
		pq2->deleteTop();
		REQUIRE(pq2->getTop() == nullptr);
		REQUIRE(pq2->getSize() == 0);
		REQUIRE(pq2->isEmpty() == true);
	}

	//checking the size of the pd2 after inserting bunch of items
	SECTION("Check the size of the Priority Queue it should be 2.")
	{
		pq2->insert(arr1);
		pq2->insert(arr2);
		pq2->deleteTop();
		pq2->insert(arr4);
		REQUIRE(pq2->getSize() == 2);
	}
}