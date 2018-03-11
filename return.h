//	File Name: return.h
//	Programmer: Tabitha Roemish & Prathyusha Pillari
//	Date: February 23, 2018
//	File contains: return class delcaration
//      Inherits from the Command class. Using the provided action 
//      string for the and virtual execute function we Return the 
//      desired Movie by searching our BST for it, and updating the stock +1.


#ifndef RETURN_H
#define RETURN_H
#include "command.h"

class Return : public Command
{
public:
        // constructor
	Return(Customer *custPtr, Movie* mvPtr);
	~Return() {}; // destructor
	virtual void print(); // print function for retuning
	virtual void execute(); // excecute function

private:
        // pointer to movie
	Movie * mvPtr;
	// pointer to customer
	Customer * custPtr;
};

#endif
