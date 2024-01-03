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
#include "Bursts.h"

//constructor
Bursts::Bursts( int b)
{
	burst = b;
}

//getBurst
int Bursts::getBurst()
{
	return burst;
}

//setBurst
void Bursts::setBurst(int b)
{
	burst = b;
}

//compareTo
int Bursts::compareTo(ListItem* other)
{
	return 0;
}

//destructor
Bursts::~Bursts()
{}

