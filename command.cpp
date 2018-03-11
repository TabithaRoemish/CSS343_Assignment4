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
#include <sstream>
#include <string>

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
		std::cout << "Customer ID: " << custNum << " is not valid" << std::endl;
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
				std::getline(ss, actor);
				std::string yr = std::to_string(year);
				std::string find(yr + actor);
				if (isMovie(mediaCode, movieCode, find))
					cout << "movie found " << find;
				if (Store::collection[mediaCode][movieCode].findWithString(find) == 1)
				{
					Movie * movie = Store::collection[mediaCode][movieCode].
						returnItemWithString(find);
					cmd = make(actionCode, customer, movie);
				}
				else
				{
					std::cout << "The movie, " << actor;
					std::cout << ", " << yr << " does not exist" << std::endl;
				}
			}
			else if (movieCode == "D")
			{
				std::getline(ss, director, ',');
				ss.get(); // remove comma from ss
				std::getline(ss, title, ',');
				if (Store::collection[mediaCode][movieCode].
					findWithString(director + title) == 1)
				{
					Movie * movie = Store::collection[mediaCode][movieCode].
						returnItemWithString(director + title);
					cmd = make(actionCode, customer, movie);
				}
				else
				{
					std::cout << "The movie, " << movieCode << ": " << title;
					std::cout << " " << director << " does not exist" << std::endl;
				}
			}
			else if (movieCode == "F")
			{
				std::getline(ss, title, ',');
				ss >> year;
				std::string yr = std::to_string(year);
				if (Store::collection[mediaCode][movieCode].findWithString(title + yr) == 1)
				{
					Movie * movie = Store::collection[mediaCode][movieCode].returnItemWithString(title + yr);
					cmd = make(actionCode, customer, movie);
				}
				else
				{
					std::cout << "The movie, " << movieCode << ": " << title;
					std::cout << " " << yr << " does not exist" << std::endl;
				}
			}
			else
				std::cout << movieCode << " is an invalid video code" << std::endl;
		}
		else
			std::cout << mediaCode << " is an invalid media code" << std::endl;
	}
	else
		std::cout << actionCode << "is an invalid command code" << std::endl;

	return cmd;
}

Command * Command::make(char actionType,  Customer * cust, Movie * mv)
{
	Command * cmd = nullptr;
	switch (actionType) {
	case 'B':
	{
		cmd = new Borrow(cust, mv);
		cmd->execute();
		break;
	}
	case 'R':
	{
		cmd = new Return(cust, mv);
		cmd->execute();
		break;
	}
	case 'I':
	{
		cmd = new Inventory();
		cmd->execute();
		break;
	}
	case 'H':
	{
		cmd = new History(cust);
		cmd->execute();
		break;
	}
	default : 
		std::cout << "Invalid Action Code" << std::endl;
	}

	return cmd;
}

bool Command::isMovie(std::string media, std::string movC, std::string key)
{
	bool answer = false;
	if (Store::collection[media][movC].findWithString(key) == 1)
		answer = true;
	return answer;
}

