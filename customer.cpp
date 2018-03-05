//	File Name: customer.cpp
//	Programmer: Tabitha Roemish & Prathyusha Pillari
//	Date: March 2, 2018
//	File contains: customer class definitions

#include "customer.h"

Customer::Customer(int ID, std::string nm)
{
	CustomerID = ID;
	CustomerName = nm;
}

void Customer::addCommand(Command* cmd)
{
	commandHistory.push(cmd);
}

void Customer::addMovie(Movie* mv)
{
	movieList.push(mv);
}