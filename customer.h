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



class Customer
{
public:
	Customer();
	Customer(int ID, std::string);
	void setID(int ID);
	void setName(std::string nm);
	std::string getName();
	int getID();
	void addCommand(Command* cmd);
	void addMovie(Movie* mv);
	bool movieRented(Movie* mv);
	void returnMovie(Movie* mv);
	
	void printCommandHistory();
	void clearCommandHistory();
	void clearMovieList();
	
private:
	int CustomerID;
	std::string CustomerName;
	std::vector<Movie*> movieList;
	std::queue<Command*> commandHistory;
	
};

#endif