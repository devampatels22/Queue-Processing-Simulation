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
#pragma once

class Event;
class Node;

class PriorityQueue
{
private:
	Node* top; //storing Top refrence
	int size; //Storing size of the priority queue
public:
	PriorityQueue();//constructor
	Event* getTop();//returns top of the priorityqueue
	Event* deleteTop(); //delets the top of the priority queue
	void insert(Event*); //insert event in priority queue accoridng to each events priority
	bool isEmpty(); //returns boolean if is emepty or not
	int getSize(); //returns size of the queue
	~PriorityQueue(); //destructor
};//Class PriorityQueue
