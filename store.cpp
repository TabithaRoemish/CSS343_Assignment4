//	File Name: store.cpp
//	Programmer: Tabitha Roemish & Prathyusha Pillari
//	Date: March 2, 2018
//	File contains: store class definitions

#include "store.h"
#include <fstream>
#include <iostream>

Store::~Store()
{
	//iterate through customer list, delete customers
	//iterate through movie list, delete movies
}
void Store::readDVDMovies(std::string filename)
{
	std::ifstream toRead(filename);

	std::string input;
	//while file not empty
	/*Movie * mvPtr = Movie::create(input);*/
		//if mvPtr!= nullptr
			/*collection["D"].at("F")->add(mvPtr);*/

	if (toRead.is_open())

	{
		std::getline(toRead, parse);
		while (std::getline(toRead, parse))
		{
			ss << parse;
			ss >> startVertex >> endVertex >> weight;

			add(startVertex, endVertex, weight);

			//reset
			startVertex = " ";
			endVertex = " ";
			parse = " ";
			ss.clear();
		}

	}
	else

		std::cerr << "Could not open file: " << filename;

	toRead.close();
	
}

void Store::readCustomers(std::string filename)
{
	std::string input;
	//while file not empty
		//get int, get string
		//create customer
		//add customer to customer list
}

void Store::readCommands(std::string filename)
{
	std::string input;
	//while file not empty
		//get string
		//create(string input)
}

Movie * Store::findMovie(std::string mediaType, std::string genreCode, std::string stringKey)
{
	Movie * found = nullptr;
	//check collection
	//Collection[mediaType].at(genreCode)->contains(
	return found;
}

Customer * Store::findCustomer(int custID)
{
	Customer * found = nullptr;
	//check customer hashmap
	return found;
}

void Store::printInventory()
{

}