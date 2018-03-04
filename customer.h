//	File Name: customer.h
//	Programmer: Tabitha Roemish & Prathyusha Pillari
//	Date: March 2, 2018
//	File contains: customer class delcaration

#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
#include <queue>

class Customer
{
public:
	Customer(int ID, std::string);
private:
	int CustomerID;
	std::string CustomerName;
	std::queue<Movie*> movieList;
	std::queue<Command*> commandHistory;
};

#endif