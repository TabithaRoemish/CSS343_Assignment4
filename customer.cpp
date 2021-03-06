//	File Name: customer.cpp
//	Programmer: Tabitha Roemish & Prathyusha Pillari
//	Date: March 2, 2018
//	File contains: customer class definitions
//      Contains information related to each individual Store Customer.

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
	std::cout << *this << std::endl;
	std::queue<Command *> temp;
	while (!commandHistory.empty())
	{
		commandHistory.front()->print();
		temp.push(commandHistory.front());
		commandHistory.pop();
	}
	std::cout << endl;
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

// clears the command history
void Customer::clearCommandHistory()
{
 //no mem alloc for queue so pop all members should not leak
	while (!commandHistory.empty())
		commandHistory.pop();

}

// clears the movie list
void Customer::clearMovieList()
{
	//no memalloc so clear should not result in mem leak
	movieList.clear();
}

// << overload using friend class
std::ostream&  operator<<(std::ostream& out, const Customer & cust)
{
	out << cust.CustomerID  << " " << cust.CustomerName;
	return out;
}
