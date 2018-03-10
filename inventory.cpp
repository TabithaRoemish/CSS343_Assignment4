//	File Name: inventory.cpp
//	Programmer: Tabitha Roemish & Prathyusha Pillari
//	Date: March 3, 2018
//	File contains: Inventory class definition

#include "inventory.h"
#include <iostream>
Inventory::Inventory()
{}

void Inventory::print()
{
	std::cout << "Inventory: ";
}
void Inventory::execute()
{
	Store::printInventory();
}