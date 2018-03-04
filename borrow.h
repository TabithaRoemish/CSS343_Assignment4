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
	//needs to check customer exists, media type is D, movie exists (use movie code to pull correct map, check map)
	Borrow(Customer *custPtr, Movie* mvPtr); 
	~Borrow() {};
	virtual void execute(); 
private:
	Customer * customerPtr;
	Movie * moviePtr;
};

#endif
