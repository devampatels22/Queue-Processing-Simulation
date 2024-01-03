//-----------------------------------------
// NAME		: Devam Patel 
// STUDENT NUMBER	: 7859163
// COURSE		: COMP 2150
// INSTRUCTOR	: Mike
// ASSIGNMENT	: assignment # 2
// 
// REMARKS: This program holds items for a queue 
//-----------------------------------------
#include "Node.h"
#include "ListItem.h"

/**** Node implementation */
//constructor 1
Node::Node() : item(nullptr), next(nullptr)  {}

//Node Constructor 2
Node::Node(ListItem *i, Node *n) : item(i), next(n) {}

//getNext
Node *Node::getNext() {
	return next;
}
//setNext
void Node::setNext(Node *n) {
	next=n;
}

//getItem
ListItem *Node::getItem() {
	return item;
}
