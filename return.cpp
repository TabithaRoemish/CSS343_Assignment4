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
	std::cout << "Returned: ";
	mvPtr->print();
}
void Return::execute()
{
	if (custPtr->movieRented(mvPtr))
	{
		custPtr->returnMovie(mvPtr);
		custPtr->addCommand(this);
		//add 1 to movie stock mv->addStock();
	}
}