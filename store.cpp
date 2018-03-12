//	File Name: store.cpp
//	Programmer: Tabitha Roemish & Prathyusha Pillari
//	Date: March 2, 2018
//	File contains: store class definitions
//      The Store class also contains a HashTable for all the Store’s Customers.
//      Manager for all of the Store’s database which includes all the Movies sorted 
//      by their types, as well as all the Customers of the Store. 
//      It is assumed that all input is correctly formatted according to the 
//      homework specification file.

#include "store.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include "binarysearchtree.h"
#include "movie.h"


#include "comedy.h"
#include "classic.h"
#include "drama.h"

//initialize static variables in store
std::set<std::string> Store::commandCodes = { "B", "R", "I", "H" };
std::set<std::string> Store::mediaCodes = { "D" };
std::set<std::string> Store::movieCodes = { "C", "D", "F" };
std::queue<Command*> Store::commandPtrs;
HashMap Store::customerList;
std::map< std::string, std::map<std::string, BinarySearchTree<Movie*>>> Store::collection;

//store destructor
Store::~Store()
{
	//hashmap customerList releases space made for hash elements and Customers
	//BST releses Movie space
	//release commands
	while (!commandPtrs.empty())
	{
		delete commandPtrs.front();
		commandPtrs.pop();
	}
}

//reads DVDs specifically because it adds all files to collection["D"]
//reads input string and sends it to movie create function
void Store::readDVDMovies(std::string filename)
{
  /*F, 10, Nora Ephron, You've Got Mail, 1998       
	D, 10, Steven Spielberg, Schindler's List, 1993       
	C, 10, George Cukor, Holiday, Katherine Hepburn 9 1938       
	C, 10, George Cukor, Holiday, Cary Grant 9 1938       
	Z, 10, Hal Ashby, Harold and Maude, Ruth Gordon 2 1971       
	D, 10, Phillippe De Broca, King of Hearts, 1967*/

	std::ifstream toRead(filename);
	std::string input = "";
	if (toRead.is_open())
	{
		while (std::getline(toRead, input))
		{
			// calls the Movie class's create to 
			// create the correct movie obbject and 
			// stores it into a pointer
			Movie * mvPtr = Movie::create(input);
			if (mvPtr != nullptr)
			{
				// add's the movie obbject to the 
				// appropriate BST
				std::string code = input.substr(0, 1);
				collection["D"][code].add(mvPtr);
			}
			input = "";
		}
	}
	else
		std::cerr << "Could not open file: " << filename;

	toRead.close();	
}

// reads customers from file, adds customers to hashtable
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
			// gets the custormer ID
			ss << input;
			ss >> custId;
			ss.get(); // get space before name
			std::getline(ss,custName);
		//check if customer is in list, if not (nullptr returned) then add
			if (customerList.search(custId) == nullptr) 
			{
				Customer * cust = nullptr;
				cust = new Customer(custId, custName);
				customerList.insert(custId, cust);
				input = "";
				custId = 0;
				custName = "";
				ss.clear();
			} // else continue without comment
		}
	}
	else
		std::cerr << "Could not open file: " << filename;
	toRead.close();
}

// reads input string and sends it to command.create to make specific commands
void Store::readCommands(std::string filename)
{
	std::ifstream toRead(filename);
	std::string input;

	if (toRead.is_open())
	{
		while (std::getline(toRead, input))
		{
			Command * cmd = Command::create(input);
			if(cmd != nullptr)
				commandPtrs.push(cmd);
		}
		input = "";
	}
	else
		std::cerr << "Could not open file: " << filename;
	toRead.close();
}

//iterates through collection
//prints string value for mediaType, then string value for Genre type
//then prints contents of BST
//ex
// D:  
//   C:  
//	   Title Year
//	   Title Year
void Store::printInventory()
{
	std::cout << "Inventory: " << std::endl;
	for (std::map<std::string, std::map<std::string, BinarySearchTree<Movie*>>>
		::iterator mediaTypeIt = collection.begin(); mediaTypeIt != collection.end(); mediaTypeIt++)
	{
		// prints the string vlaue for media type
		std::cout << mediaTypeIt->first << ": " << endl;
		
		for (auto genreIt = mediaTypeIt->second.begin(); 
			genreIt != mediaTypeIt->second.end(); genreIt++)
		{
			// prints the genre type
			std::cout << "   " << genreIt->first << ": " << endl;
			genreIt->second.print(); // prints the contents of BST's
		}
	}
	std::cout << endl;
}




