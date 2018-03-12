//	File Name: command.cpp
//	Programmer: Tabitha Roemish & Prathyusha Pillari
//	Date: March 4, 2018
//	File contains: command abstract class definitions
//      Parent class to Borrow, Return, Inventory & History classes. 
//      This is an abstract class where the child classes 
//      must implement the methods within it. 

#include "command.h"
#include "borrow.h"
#include "return.h"
#include "inventory.h"
#include "history.h"
#include "store.h"
#include <iostream>
#include <sstream>

#include <string>


//B 1234 D C 9 1938 Katherine Hepburn 
//B 1234 D F Pirates of the Caribbean, 2003 
//R 1234 D C 9 1938 Katherine Hepburn 
//B 1234 D D Steven Spielberg, Schindler's List, 
//S 
//H 1234

// create command

Command * Command::create(std::string identifier)
{
	int custNum = 0; 
	char actionCode = ' ';
	std::string movieCode ="";
	std::string mediaCode ="";
	int month = 0;
	int year = 0;
	std::string title = "";
	std::string actor = "";
	std::string actFirst = "";
	std::string actLast = "";
	std::string director = "";
	std::stringstream ss(identifier);
	std::map< std::string, std::map<std::string, BinarySearchTree<Movie*>>>
		::iterator it = Store::collection.begin();
	Command * cmd = nullptr;
	
	ss >> actionCode;

	//if inventory
	if (actionCode == 'I')
		return make(actionCode, nullptr, nullptr);

	//check customer
	ss >> custNum;
	Customer * customer = Store::customerList.search(custNum);
	if (customer == nullptr)
	{
		std::cerr << "Customer ID: " << custNum << " is not valid" 
			<< std::endl;
		return nullptr; //return error if customer does not exist
	}

	//if history
	if (actionCode == 'H')
	{
		return make(actionCode, customer, nullptr);
	}

	//if return or borrow 
	if (actionCode == 'B' || actionCode == 'R')
	{
		ss >> mediaCode; //check mediaType exists
		if (Store::mediaCodes.count(mediaCode) == 1)
		{
			ss >> movieCode; 
			ss.get(); //get space after movieCode
			if (movieCode == "C")
			{
				ss >> month >> year;
				ss.get(); //get space after year
				std::getline(ss, actFirst, ' ');
				std::getline(ss, actLast, '\r');
				ss.get(); //get carrige return
				actor = actFirst + " " + actLast;
				std::string yr = std::to_string(year);

				Movie * test = Store::collection[mediaCode][movieCode].returnItemWithString(yr + actor);
				if(test != nullptr)
					cmd = make(actionCode, customer, test);
				else
				{
					std::cerr << "The movie, " << actor;
		std::cerr << ", " << yr << " does not exist" << std::endl;
				}
			}
			else if (movieCode == "D")
			{
				std::getline(ss, director, ',');
				ss.get(); // remove comma from ss
				std::getline(ss, title, ',');

				Movie * mv = Store::collection[mediaCode][movieCode].returnItemWithString(director + title);
				if (mv != nullptr)
					cmd = make(actionCode, customer, mv);
				else
				{
		std::cerr << "The movie, " << movieCode << ": " << title;
		std::cerr << " " << director << " does not exist" << std::endl;
				}
			}
			else if (movieCode == "F")
			{
				std::getline(ss, title, ',');
				ss >> year;
				std::string yr = std::to_string(year);

				Movie * mv = Store::collection[mediaCode][movieCode].returnItemWithString(title + yr);
				if (mv != nullptr)
					cmd = make(actionCode, customer, mv);
				else
				{
		std::cerr << "The movie, " << movieCode << ": " << title;
		std::cerr << " " << yr << " does not exist" << std::endl;
				}
			}
			else
	std::cerr << movieCode << " is an invalid video code" << std::endl;
		}
		else
	std::cerr << mediaCode << " is an invalid media code" << std::endl;
	}
	else
	std::cerr << actionCode << "is an invalid command code" << std::endl;

	return cmd;
}

// make method
Command * Command::make(char actionType,  Customer * cust, Movie * mv)
{
	// command obbject pointer to return
	Command * cmd = nullptr;
	// switch statement to see the type of command
	switch (actionType) {
	case 'B':
	{
		// creates obbject
		cmd = new Borrow(cust, mv);
		cmd->execute();
		break;
	}
	case 'R':
	{
		// creates obbject
		cmd = new Return(cust, mv);
		cmd->execute();
		break;
	}
	case 'I':
	{	
		// creates obbject
		cmd = new Inventory();
		cmd->execute();
		break;
	}
	case 'H':
	{
		// creates obbject
		cmd = new History(cust);
		cmd->execute();
		break;
	}
	default : 
		std::cout << "Invalid Action Code" << std::endl;
	}

	// returns the command object
	return cmd;
}



