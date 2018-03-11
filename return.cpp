//	File Name: return.cpp
//	Programmer: Tabitha Roemish & Prathyusha Pillari
//	Date: March 3, 2018
//	File contains: Return class definition

#include "return.h"
#include <iostream>

Return::Return(Customer * cust, Movie * mv)
{
	mvPtr = mv;
	custPtr = cust;
}
void Return::print()
{
	std::cout << "   Returned: ";
	mvPtr->print();
}
void Return::execute()
{
	if (custPtr->movieRented(mvPtr))
	{
		custPtr->returnMovie(mvPtr); //removes movie from customer's movie list
		custPtr->addCommand(this); //log command in customer's command history
		mvPtr->rtnMovie(); // adds 1 to movie stock
	}
}