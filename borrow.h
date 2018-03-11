//	File Name: borrow.h
//	Programmer: Tabitha Roemish & Prathyusha Pillari
//	Date: February 23, 2018
//	File contains: borrow class declaration

#ifndef BORROW_H
#define BORROW_H
#include "command.h"

class Borrow : public Command
{
public:
	Borrow(Customer *custPtr, Movie* mvPtr); 
	~Borrow() {};
	virtual void print();
	virtual void execute();

private:
	Movie * mvPtr;
	Customer * custPtr;
	int tempStock; // to capture stock at time of borrow
};

#endif
