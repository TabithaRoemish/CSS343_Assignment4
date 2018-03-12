//	File Name: customer.h
//	Programmer: Tabitha Roemish & Prathyusha Pillari
//	Date: March 2, 2018
//	File contains: customer class delcaration
//      Contains information related to each individual Store Customer.


#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include "movie.h"
#include "command.h"

class Command;

class Customer
{
public:
	Customer();
	Customer(int ID, std::string);
	void setID(int ID);
	void setName(std::string nm);
	std::string getName();
	int getID();
	void addCommand(Command* cmd); // adds commands 
	void addMovie(Movie* mv); // adds movies
	bool movieRented(Movie* mv); // checks if movie is rented
	void returnMovie(Movie* mv); // returns movie
	
	void printCommandHistory(); // prints the command history 
	void clearCommandHistory(); // clears command history
	void clearMovieList(); // clears movie list
	// << override using friend class
	friend std::ostream& operator<<(std::ostream& out, const Customer & cust);
private:
	int CustomerID; // customer ID
	std::string CustomerName; // customer name
	std::vector<Movie*> movieList; // movie list
	std::queue<Command*> commandHistory; // command history 
	
};

#endif
