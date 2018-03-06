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
	custPtr->addCommand(this);
	custPtr->addMovie(mvPtr);
	//check if stock available
	// if yes, remove one from stock of movie
	// else std::cout << "Movie is out of stock" << std::endl;
}

void Borrow::print()
{
	std::cout << "Borrowed: ";
	mvPtr->print();
}