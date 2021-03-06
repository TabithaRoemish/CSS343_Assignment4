//	File Name: command.h
//	Programmer: Tabitha Roemish & Prathyusha Pillari
//	Date: February 23, 2018
//	File contains: Command class declaration
//		command class is abstract class for movie types 
//              (Borrow[B], Return[R], Inventory[I], History[H])
//      Parent class to Borrow, Return, Inventory & History classes. 
//      This is an abstract class where the child classes 
//      must implement the methods within it.

#ifndef COMMAND_H
#define COMMAND_H
#include <string>
#include "movie.h"

#include <set>
#include "store.h"

class Customer;

class Command
{
public:

	// frineds the store class to access it
	friend class Store; 
	Command() {};
	virtual ~Command() {}; // destructor
	virtual void print() = 0; 
	virtual void execute() = 0;
	// command create function
	static Command * create(std::string identifier);

private:
	// make function 
	static Command * make(char actionType, Customer * cust, Movie * mv);
};


#endif
