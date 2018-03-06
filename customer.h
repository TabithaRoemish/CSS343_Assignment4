//	File Name: customer.h
//	Programmer: Tabitha Roemish & Prathyusha Pillari
//	Date: March 2, 2018
//	File contains: customer class delcaration

#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
#include <vector>
#include <queue>
#include "movie.h"
#include "command.h"
class Command;
class Customer
{
public:
	Customer(int ID, std::string);
	void addCommand(Command* cmd);
	void addMovie(Movie* mv);
	bool movieRented(Movie* mv);
	void returnMovie(Movie* mv);
	std::string getName();
	void printCommandHistory();
	
	//add clear commands,
	// add clear movie list;
private:
	int CustomerID;
	std::string CustomerName;
	std::vector<Movie*> movieList;
	std::queue<Command*> commandHistory;
	
};

#endif