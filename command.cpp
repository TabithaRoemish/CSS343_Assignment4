//	File Name: command.cpp
//	Programmer: Tabitha Roemish & Prathyusha Pillari
//	Date: March 4, 2018
//	File contains: command abstract class definitions

#include "command.h"
#include "borrow.h"
#include "return.h"
#include "inventory.h"
#include "history.h"
#include "store.h"
#include <iostream>

//B 1234 D C 9 1938 Katherine Hepburn 
//B 1234 D F Pirates of the Caribbean, 2003 
//R 1234 D C 9 1938 Katherine Hepburn 
//B 1234 D D Steven Spielberg, Schindler's List, 
//S 
//H 1234

std::string readCommaSeparated(); //used for reading input strings

Command * Command::create(std::string identifier)
{
	int custNum = 0; 
	char actionCode = identifier[0];
	std::string movieCode ="";
	std::string mediaCode ="";
	int month = 0;
	int year = 0;
	std::string title = "";
	std::string actor = "";
	std::string director = "";
	std::map< std::string, std::map<std::string, std::map<std::string, Movie*>>>
		::iterator it = Store::collection.begin();

	//if inventory, skip the rest
	if (actionCode == 'I')
		return make(actionCode, nullptr, nullptr);

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
				{//classic - year + actor
				 //B 1234 D C 9 1938 Katherine Hepburn 
					std::cin >> month >> year;
					std::cin >> actor;
					std::string yr = "" + year;
					if (Store::collection[movieCode][movieCode].count(yr + actor) > 1
						|| Store::collection[movieCode][movieCode].count(yr + actor) == 1)
					{
						Movie * movie = Store::collection[movieCode][movieCode].at(yr + actor);
						Command * cmd = make(actionCode, customer, movie);
						cmd->execute();
					}
					else
						std::cerr << "Movie does not exist" << std::endl;
				}
				else if (movieCode == "D")
				{//Drama = director + title
				 //B 1234 D D Steven Spielberg, Schindler's List, 
					director = readCommaSeparated();
					title = readCommaSeparated();
					if (Store::collection[movieCode][movieCode].count(director + title) == 1)
					{
						Movie * movie = Store::collection[movieCode][movieCode].at(director + title);
						Command * cmd = make(actionCode, customer, movie);
						cmd->execute();
					}
					else
						std::cerr << "Movie does not exist" << std::endl;
				}
				else if (movieCode == "F")
				{//Comedy = Title + year
				 //B 1234 D F Pirates of the Caribbean, 2003
					title = readCommaSeparated();
					std::cin >> year;
					std::string yr = "" + year;
					if (Store::collection[movieCode][movieCode].count(title + yr) == 1)
					{
						Movie * movie = Store::collection[movieCode][movieCode].at(title + yr);
						Command * cmd = make(actionCode, customer, movie);
						cmd->execute();
					}
					else
						std::cerr << "Movie does not exist" << std::endl;
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

Command * Command::make(char actionType,  Customer * cust, Movie * mv)
{
	Command * cmd;
	switch (actionType) {
	case 'B':
	{
		cmd = new Borrow(cust, mv);
		break;
	}
	case 'R':
	{
		cmd = new Return(cust, mv);
		break;
	}
	case 'I':
	{
		cmd = new Inventory();
	}
	case 'H':
	{
		cmd = new History(cust);
	}
	default : 
		std::cerr << "Invalid Action Code" << std::endl;
	}

	return cmd;
}

std::string readCommaSeparated()
{
	char stringPart;
	std::string word;
	stringPart = std::getchar();
	while (stringPart != ',')
	{
		word += stringPart;
		stringPart = getchar();
	}
	getchar(); //get rid of ,
	return word;
}