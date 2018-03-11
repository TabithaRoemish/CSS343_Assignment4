//	File Name: borrow.cpp
//	Programmer: Tabitha Roemish & Prathyusha Pillari
//	Date: March 3, 2018
//	File contains: borrow class definition

#include "borrow.h"
#include <iostream>

Borrow::Borrow(Customer *cust, Movie* mv)
{
	mvPtr = mv;
	custPtr = cust;
	tempStock = 0;
}

void Borrow::execute()
{
	tempStock = 0; // reset temp stock before execute
	if (mvPtr->getStock() > 0) // if stock
	{
		custPtr->addCommand(this); //log cmd in customer's history log
		custPtr->addMovie(mvPtr); //add movie to customer's outstanding movieList
		mvPtr->brwMovie(); //removes 1 from stock
		tempStock = mvPtr->getStock(); //capture stock after borrow
	}
	else
	{
		std::cout << "Movie out of stock: ";
		mvPtr->print();
	}
}

void Borrow::print()
{
	std::cout<< "  Borrowed: " << mvPtr->getGenre() << ", " << tempStock;
	std::cout<< ", " << mvPtr->getTitle() << ", " << mvPtr->getDirector();
	std::cout << std::endl;
}