//	File Name: history.h
//	Programmer: Tabitha Roemish & Prathyusha Pillari
//	Date: February 23, 2018
//	File contains: history class declaration
//      Inherits from the Command class. The History class has one 
//      function, getHistory, that prints the Customer history
//      of Commands of the passed customerID.

#ifndef HISTORY_H
#define HISTORY_H
#include "command.h"


class History : public Command
{
public:
	History(Customer * custPtr); // constructor 
	~History() {}; // destructor
	virtual void print(); // print function 
	virtual void execute(); // execute function

private:
	Customer * custPtr; // pointer to object
};

#endif
