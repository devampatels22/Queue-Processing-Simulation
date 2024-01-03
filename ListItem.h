//-----------------------------------------
// NAME		: Devam Patel 
// STUDENT NUMBER	: 7859163
// COURSE		: COMP 2150
// INSTRUCTOR	: Mike
// ASSIGNMENT	: assignment # 2
// 
// REMARKS: This program is abstract class to hold items
//-----------------------------------------
//ListItem - abstract class to hold items
#pragma once

class ListItem {
public:
	virtual int compareTo(ListItem *other) = 0;
}; // class ListItem
