//	File Name: inventory.h
//	Programmer: Tabitha Roemish & Prathyusha Pillari
//	Date: February 23, 2018
//	File contains: inventory class declaration
//      Inherits from the Command class. The Inventory class has 
//      one method, getInventory, which prints the inventory of the Store.

#ifndef INVENTORY_H
#define INVENTORY_H
#include "command.h"


class Inventory : public Command
{
public:
	Inventory(); // constructor 
	virtual ~Inventory() {}; // destructor
	virtual void print(); // prints the inventory of the Store.
	virtual void execute(); // virtual execute method 
};

#endif
