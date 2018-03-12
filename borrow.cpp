//	File Name: borrow.cpp
//	Programmer: Tabitha Roemish & Prathyusha Pillari
//	Date: March 3, 2018
//	File contains: borrow class definition
//      Inherits from the Command class. Using the action string and 
//      virtual execute function we Borrow the desired Movie by searching 
//      our BST for it, and updating the stock -1. 
//      Assumes we have enough stock to Borrow.

////////////////////////////////////////////////////////////////////////////////
// This is 80 characters - Keep all lines under 80 characters                 //
////////////////////////////////////////////////////////////////////////////////

#include "borrow.h"
#include <iostream>

// constructor to initialize 
Borrow::Borrow(Customer *cust, Movie* mv)
{
	mvPtr = mv;
	custPtr = cust;
	tempStock = 0;
}

// execute method
void Borrow::execute()
{
	tempStock = 0; // reset temp stock before execute
	if (mvPtr->getStock() > 0) // if stock
	{
		//log cmd in customer's history log
		custPtr->addCommand(this); 
		//add movie to customer's outstanding movieList
		custPtr->addMovie(mvPtr); 
		mvPtr->brwMovie(); //removes 1 from stock
		tempStock = mvPtr->getStock(); //capture stock after borrow
	}
	else
	{
		std::cout << "Movie out of stock: ";
		mvPtr->print();
	}
}

// prints the borrowed items
void Borrow::print()
{
	std::cout<< "  Borrowed: " << mvPtr->getGenre() 
		<< ", " << tempStock;
	std::cout<< ", " << mvPtr->getTitle() << ", " 
		<< mvPtr->getDirector();
	std::cout << std::endl;
}
