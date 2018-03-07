//	File Name: store.cpp
//	Programmer: Tabitha Roemish & Prathyusha Pillari
//	Date: March 2, 2018
//	File contains: store class definitions

#include "store.h"
#include <fstream>
#include <iostream>
#include <sstream>

std::set<std::string> Store::commandCodes = { "B", "R", "I", "H" };
std::set<std::string> Store::mediaCodes = { "D" };
std::set<std::string> Store::movieCodes = { "C", "D", "F" };

Store::~Store()
{
	//iterate through customer list, delete customers
	//iterate through movie list, delete movies
}
void Store::readDVDMovies(std::string filename)
{
  /*F, 10, Nora Ephron, You've Got Mail, 1998       
	D, 10, Steven Spielberg, Schindler's List, 1993       
	C, 10, George Cukor, Holiday, Katherine Hepburn 9 1938       
	C, 10, George Cukor, Holiday, Cary Grant 9 1938       
	Z, 10, Hal Ashby, Harold and Maude, Ruth Gordon 2 1971       
	D, 10, Phillippe De Broca, King of Hearts, 1967*/

	std::ifstream toRead(filename);

	std::string input;

	if (toRead.is_open())

	{
		std::getline(toRead, input);
		while (std::getline(toRead, input))
		{
			Movie * mvPtr = nullptr; //Movie::create(input);
			if (mvPtr != nullptr)
			{
				std::string code = input.substr(1, 1);
				/*collection["D"][code][mvPtr->getKey()] = mvPtr;*/
			}
		}
	}
	else
		std::cerr << "Could not open file: " << filename;

	toRead.close();
	
}

void Store::readCustomers(std::string filename)
{
	//1111 Mouse Mickey 
	//1000 Mouse Minnie
	std::ifstream toRead(filename);
	std::string input;
	std::stringstream ss;
	int custId = 0;
	std::string custName = "";
	
	if (toRead.is_open())
	{
		while (std::getline(toRead, input))
		{

			ss << input;
			ss >> custId >> custName;
			Customer * cust = new Customer(custId, custName);
			/*customerList.insert(custId, cust);*/
		}
	}
	else
		std::cerr << "Could not open file: " << filename;
	toRead.close();
}

void Store::readCommands(std::string filename)
{
	std::ifstream toRead(filename);
	std::string input;

	if (toRead.is_open())
	{
		while (std::getline(toRead, input))
			/*Command * cmd = Command::create(input);*/
			;
	}
	else
		std::cerr << "Could not open file: " << filename;
	toRead.close();
}


void Store::printInventory()
{

	//for (std::map<std::string, std::map<std::string, std::map<std::string, Movie*>>>
	//	::iterator it = collection.begin(); it != collection.end(); it++)
	//{
	//	std::cout << it->first;
	//	std::cout << " ";
	//	//need to finish this
	//}

}