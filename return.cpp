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
	tempStock = 0;
}

// prints the movie pointer
void Return::print()
{
	
	std::cout << "  Returned: " << mvPtr->getGenre() << ", " << tempStock;
	std::cout << ", " << mvPtr->getTitle() << ", " << mvPtr->getDirector();
	std::cout << std::endl;
}

//  execute function
void Return::execute()
{	
	tempStock = 0; //reset stock before execute
	if (custPtr->movieRented(mvPtr))
	{
		// class returnMovie funtion in Customer class
		//removes movie from customer's movie list
		custPtr->returnMovie(mvPtr); 
		//log command in customer's command history
		custPtr->addCommand(this); 
		mvPtr->rtnMovie(); // adds 1 to movie stock
		tempStock = mvPtr->getStock(); //capture stock after return

	}
}
