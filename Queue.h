//-----------------------------------------
// NAME		: Devam Patel 
// STUDENT NUMBER	: 7859163
// COURSE		: COMP 2150
// INSTRUCTOR	: Mike
// ASSIGNMENT	: assignment # 2
// 
// REMARKS: This program holds objects ListItem as a linkedlist it serve first in first out purpose
//-----------------------------------------
#pragma once

class Node;
class ListItem;

class Queue {
private:
	Node *front;
	Node *back;
	int size;
public:
	Queue();
	int getSize();
	bool isEmpty();
	void enqueue(ListItem *item);
	ListItem *getFront();
	ListItem *dequeue();
}; // class Queue
