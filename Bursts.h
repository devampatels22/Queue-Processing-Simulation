//-----------------------------------------
// NAME		: Devam Patel 
// STUDENT NUMBER	: 7859163
// COURSE		: COMP 2150
// INSTRUCTOR	: Mike
// ASSIGNMENT	: assignment # 2
// 
// REMARKS: The purpose of this program is to store a burst since we have to use 
//			abstract data type listItem.
//-----------------------------------------
#pragma once
#include "ListItem.h"

class Bursts : public ListItem {
private: 
	int burst; //holds burst.

public: 
	Bursts(int); // constructor
	int getBurst(); //returns the int of a burst that the object is holding
	void setBurst(int); //sets current burst to a int parameter
	int compareTo(ListItem* other); 
	~Bursts();//destructor
};

