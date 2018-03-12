//	File Name: history.cpp
//	Programmer: Tabitha Roemish & Prathyusha Pillari
//	Date: March 3, 2018
//	File contains: history class definition 
//	Child class of Command class. 
//      Inherits from the Command class. The History class has one 
//      function, getHistory, that prints the Customer history
//      of Commands of the passed customerID.

#include "history.h"
#include <iostream>

// constructor to initialize the object pointer
History::History(Customer * cust)
{
	custPtr = cust;
}

// print the customer history
void History::print()
{
	std::cout << "History: " << custPtr->getName();
}

// execute function to call printCommandHistory
void History::execute()
{
	custPtr->printCommandHistory();
}
