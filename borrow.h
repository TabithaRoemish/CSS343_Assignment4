//	File Name: borrow.h
//	Programmer: Tabitha Roemish & Prathyusha Pillari
//	Date: February 23, 2018
//	File contains: borrow class declaration
//      Inherits from the Command class. Using the action string and 
//      virtual execute function we Borrow the desired Movie by searching 
//      our BST for it, and updating the stock -1. Assumes we have enough stock to Borrow. 


#ifndef BORROW_H
#define BORROW_H
#include "command.h"

class Borrow : public Command
{
public:
        // constructor
	Borrow(Customer *custPtr, Movie* mvPtr); 
	~Borrow() {}; // destructor
	virtual void print();
	virtual void execute();

private:
	Movie * mvPtr; // pointer for movie
	Customer * custPtr; // pointer for customer
	int tempStock; // to capture stock at time of borrow
};

#endif
