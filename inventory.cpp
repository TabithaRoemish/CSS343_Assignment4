//	File Name: inventory.cpp
//	Programmer: Tabitha Roemish & Prathyusha Pillari
//	Date: March 3, 2018
//	File contains: Inventory class definition
//      Inherits from the Command class. The Inventory class has 
//      one method, getInventory, which prints the inventory of the Store.

#include "inventory.h"
#include <iostream>

// constructor
Inventory::Inventory() {}

// print method
void Inventory::print()
{
	std::cout << "Inventory: ";
}

// execute method that calls the print inventory
void Inventory::execute()
{
	Store::printInventory();
}
