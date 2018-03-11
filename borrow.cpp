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
}

void Borrow::execute()
{
	if (mvPtr->getStock() > 0) // if stock
	{
		custPtr->addCommand(this); //log cmd in customer's history log
		custPtr->addMovie(mvPtr); //add movie to customer's outstanding movieList
		mvPtr->brwMovie(); //removes 1 from stock
	}
	else
	{
		std::cout << "Movie out of stock: ";
		mvPtr->print();
	}
}

void Borrow::print()
{
	std::cout << "   Borrowed: ";
	mvPtr->print();
}