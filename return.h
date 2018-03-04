//	File Name: return.h
//	Programmer: Tabitha Roemish & Prathyusha Pillari
//	Date: February 23, 2018
//	File contains: return class delcaration

#ifndef RETURN_H
#define RETURN_H
#include "command.h"


class Return : public Command
{
public:
	//needs to check customer exists, media type is D, movie exists in customer borrowed queue
	Return(Customer * custPtr, Movie * mvPtr);
	~Return();
	virtual void print();
	virtual void execute();

};

#endif
