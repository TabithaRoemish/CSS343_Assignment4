//	File Name: borrow.cpp
//	Programmer: Tabitha Roemish & Prathyusha Pillari
//	Date: March 3, 2018
//	File contains: borrow class definition

#include "borrow.h"


Borrow::Borrow(Customer *cust, Movie* mv)
{
	mvPtr = mv;
	custPtr = cust;
}

void Borrow::execute()
{
	custPtr->addCommand(this);
	custPtr->addMovie(mvPtr);
	//remove one from stock of movie
}