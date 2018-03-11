//	File Name: return.cpp
//	Programmer: Tabitha Roemish & Prathyusha Pillari
//	Date: March 3, 2018
//	File contains: Return class definition
//      Inherits from the Command class. Using the provided action 
//      string for the and virtual execute function we Return the 
//      desired Movie by searching our BST for it, and updating the stock +1.

#include "return.h"
#include <iostream>

// constructor to initialize pointers 
Return::Return(Customer * cust, Movie * mv)
{
	mvPtr = mv;
	custPtr = cust;
}

// prints the movie pointer
void Return::print()
{
	std::cout << "Returned: ";
	// prints the movie class's print
	mvPtr->print();
}

//  execute function
void Return::execute()
{
	if (custPtr->movieRented(mvPtr))
	{
		// class returnMovie funtion in Customer class
		custPtr->returnMovie(mvPtr);
		custPtr->addCommand(this);
		// add 1 to movie stock mv->addStock();
	}
}
