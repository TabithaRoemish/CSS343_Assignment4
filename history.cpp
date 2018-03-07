//	File Name: history.cpp
//	Programmer: Tabitha Roemish & Prathyusha Pillari
//	Date: March 3, 2018
//	File contains: history class definition 
//		Child class of Command class. 

#include "history.h"
#include <iostream>

History::History(Customer * cust)
{
	custPtr = cust;
}

void History::print()
{
	std::cout << "History: " << custPtr->getName();
}

void History::execute()
{
	custPtr->printCommandHistory();
}