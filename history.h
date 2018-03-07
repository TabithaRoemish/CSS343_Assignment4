//	File Name: history.h
//	Programmer: Tabitha Roemish & Prathyusha Pillari
//	Date: February 23, 2018
//	File contains: history class declaration

#ifndef HISTORY_H
#define HISTORY_H
#include "command.h"


class History : public Command
{
public:
	History(Customer * custPtr);
	~History() {};
	virtual void print();
	virtual void execute();

private:
	Customer * custPtr;
};

#endif
