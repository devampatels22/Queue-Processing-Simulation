//-----------------------------------------
// NAME		: Devam Patel 
// STUDENT NUMBER	: 7859163
// COURSE		: COMP 2150
// INSTRUCTOR	: Mike
// ASSIGNMENT	: assignment # 2
// 
// REMARKS: This program holds nodes in a priority order
//			it makes sure that the objects are added so the can be dequeued 
//			in priority sequence
//-----------------------------------------
#include "PriorityQueue.h"
#include "Node.h"
#include "Event.h"
#include "Arrival.h"
#include "Timeout.h"

//constructor
PriorityQueue::PriorityQueue()
{
	top = nullptr;
	size = 0;
}

//isEmpty
bool PriorityQueue::isEmpty() {
	return top == nullptr;
}

//insert
void PriorityQueue::insert(Event* e)
{
	//id inserting to a empty queue
	if (top == nullptr)
	{
		top = new Node(e, nullptr);
	}
	else //if not an empty queue
	{
		Node* curr = top;
		Node* prev = nullptr;
		Node* next = nullptr;
		bool found = false;
		while (curr != nullptr && !found)
		{
			Event* c = dynamic_cast<Event*>(curr->getItem());
			//found position
			// iterate until c->compareto(e) > 1
			if (c->compareTo(e) >= 0)
			{
				//insert at front
				if (curr == top)
				{
					top = new Node(e, top);
				}
				else //insert after previous
				{
					prev->setNext(new Node(e, curr));
				}
				found = true;
			}
			prev = curr;
			curr = curr->getNext();
		}

		if (!found)
		{
			prev->setNext(new Node(e, curr));
		}
	}
	size++;
}

//getTop
Event* PriorityQueue::getTop()
{
	Event* e = nullptr;

	if (!isEmpty())
	{
		e = dynamic_cast<Event*>(top->getItem());
	}
	return e;
}

//deleteTop
Event* PriorityQueue::deleteTop()
{
	Node* t = top;
	size--;
	Event* e = getTop();
	top = top->getNext();
	delete(t);

	return e;
}

//getSize
int PriorityQueue::getSize()
{
	return size;
}

//destructor
PriorityQueue::~PriorityQueue() {}