//	File Name: inventory.h
//	Programmer: Tabitha Roemish & Prathyusha Pillari
//	Date: February 23, 2018
//	File contains: inventory class declaration

#ifndef INVENTORY_H
#define INVENTORY_H
#include "command.h"


class Inventory : public Command
{
public:
	Inventory();
	virtual ~Inventory() {};
	virtual void print();
	virtual void execute();
};

#endif