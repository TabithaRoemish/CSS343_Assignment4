//	File Name: return.cpp
//	Programmer: Tabitha Roemish & Prathyusha Pillari
//	Date: March 3, 2018
//	File contains: Return class definition

#include "return.h"
#include "movie.h"
#include "customer.h"

Return(Customer * cust, Movie * mv)
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
	if (custPtr->movieRented(Movie* mv))
	{
		custPtr->returnMovie(mv);
		custPtr->addCommand(this);
		//add 1 to movie stock mv->addStock();
	}
}