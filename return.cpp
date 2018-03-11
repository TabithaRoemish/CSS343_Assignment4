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
	tempStock = 0;
}
void Return::print()
{
	std::cout << "  Returned: " << mvPtr->getGenre() << ", " << tempStock;
	std::cout << ", " << mvPtr->getTitle() << ", " << mvPtr->getDirector();
	std::cout << std::endl;
}
void Return::execute()
{	
	tempStock = 0; //reset stock before execute
	if (custPtr->movieRented(mvPtr))
	{
		custPtr->returnMovie(mvPtr); //removes movie from customer's movie list
		custPtr->addCommand(this); //log command in customer's command history
		mvPtr->rtnMovie(); // adds 1 to movie stock
		tempStock = mvPtr->getStock(); //capture stock after return
	}
}