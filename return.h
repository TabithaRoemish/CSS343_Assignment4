//	File Name: return.h
//	Programmer: Tabitha Roemish & Prathyusha Pillari
//	Date: February 23, 2018
//	File contains: return class delcaration

#ifndef RETURN_H
#define RETURN_H
#include "command.h"
#include "movie.h"
#include "Customer.h"

class Return : public Command
{
public:
	Return(Customer * custPtr, Movie * mvPtr);
	~Return();
	virtual void print();
	virtual void execute();

private:
	Movie * mvPtr;
	Customer * custPtr;
};

#endif
