//	File Name: borrow.cpp
//	Programmer: Tabitha Roemish & Prathyusha Pillari
//	Date: March 3, 2018
//	File contains: borrow class definition

#include "borrow.h"


Borrow::Borrow(Customer *custPtr, Movie* mvPtr)
{
	custPtr->commandHistory.push(*this);
	mvPtr->
}