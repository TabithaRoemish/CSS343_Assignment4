//	File Name: history.h
//	Programmer: Tabitha Roemish & Prathyusha Pillari
//	Date: February 23, 2018
//	File contains: history class declaration

#ifndef HISTORY_H
#define HISTORY_H
#include "commands.h"
#include <string>

class History
{
public:
	History(Customer * custptr);

private:
	Customer * customerPtr;

};

#endif
