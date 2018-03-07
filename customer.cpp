//	File Name: customer.cpp
//	Programmer: Tabitha Roemish & Prathyusha Pillari
//	Date: March 2, 2018
//	File contains: customer class definitions

#include "customer.h"
#include <iostream>

//default constructor
Customer::Customer()
{
	CustomerID = 0;
	CustomerName = "";
}

//constructor
Customer::Customer(int ID, std::string nm)
{
	CustomerID = ID;
	CustomerName = nm;
}

//adds command (borrow or return) to command history
//this tracks the customers borrow and return history
void Customer::addCommand(Command* cmd)
{
	commandHistory.push(cmd);
}

//adds movie to movie queue which represents customers current rented media
void Customer::addMovie(Movie* mv)
{
	movieList.push_back(mv);
}

//mutator - sets customerID
void Customer::setID(int ID)
{
	CustomerID = ID;
}

//mutator - sets customer name
void Customer::setName(std::string nm)
{
	CustomerName = nm;
}

//accessor - get private member, customer ID
int Customer::getID()
{
	return CustomerID;
}

//accessor - gets private member, customer name
std::string Customer::getName()
{
	return CustomerName;
}

//prints command history for command child class History
void Customer::printCommandHistory()
{
	std::queue<Command *> temp;

	while (!commandHistory.empty())
	{
		std::cout << commandHistory.front();
		temp.push(commandHistory.front());
		commandHistory.pop();
	}
	commandHistory = temp;
}

//checks movie queue for parameter movie, returns true if in list
//used in Return command to make sure movie has been rented before returning
bool Customer::movieRented(Movie* mv)
{
	if (std::find(movieList.begin(), movieList.end(), mv) != movieList.end())
		return true;
	else
		return false;
}

//removes movie from customer movie list
void Customer::returnMovie(Movie* mv)
{
	auto it = std::find(movieList.begin(), movieList.end(), mv);
	if (it != movieList.end())
		movieList.erase(it);
}
