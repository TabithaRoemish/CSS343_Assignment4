//	File Name: command.cpp
//	Programmer: Tabitha Roemish & Prathyusha Pillari
//	Date: March 4, 2018
//	File contains: command abstract class definitions

#include "command.h"
#include "store.h"
#include <iostream>

//B 1234 D C 9 1938 Katherine Hepburn 
//B 1234 D F Pirates of the Caribbean, 2003 
//R 1234 D C 9 1938 Katherine Hepburn 
//B 1234 D D Steven Spielberg, Schindler's List, 
//S 
//H 1234
Command * Command::create(std::string identifier)
{
	int custNum; 
	std::string movieCode;
	std::string mediaCode;
	int month = 0;
	int year = 0;
	std::string title = "";
	std::string actor = "";
	
	//check command code exists
	if (Store::commandCodes.count(identifier.substr(1, 1)) == 1)
	{
		std::cin >> custNum; // check customer exists
		Customer * customer = Store::customerList.search(custNum);
		if (customer != nullptr)
		{
			std::cin >> mediaCode; //check mediaType exists
			if (Store::mediaCodes.count(mediaCode) == 1)
			{
				std::cin >> movieCode; //check movie code exists
				if (movieCode == "C")
				{
					std::cin >> month >> year;
					std::cin >> actor;
					Movie * movie = Store::collection[movieCode][movieCode].at()
					

				}
				else if (movieCode == "D")
				{

				}
				else if (movieCode == "F")
				{

				}
				else
					std::cerr << "Invalid Video Code" << std::endl;
			}
			else
				std::cerr << "Invalid Media Code" << std::endl;
		}
		else
			std::cerr << "Customer not found" << std::endl;
	}
	else
		std::cerr << "invalid action code" << std::endl;
}