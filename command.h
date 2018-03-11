//	File Name: command.h
//	Programmer: Tabitha Roemish & Prathyusha Pillari
//	Date: February 23, 2018
//	File contains: Command class declaration
//		command class is abstract class for movie types (Borrow[B], Return[R], Inventory[I], History[H])

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
	friend class Store;
	Command() {};
	virtual ~Command() {};
	virtual void print() = 0;
	virtual void execute() = 0;
	static Command * create(std::string identifier);

private:
	static Command * make(char actionType, Customer * cust, Movie * mv);
};


#endif
