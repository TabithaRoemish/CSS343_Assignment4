//	File Name: store.h
//	Programmer: Tabitha Roemish
//	Date: February 23, 2018
//	File contains: classic class declaration
//      The Store class also contains a HashTable for all the Store’s Customers.
//      Manager for all of the Store’s database which includes all the Movies sorted 
//      by their types, as well as all the Customers of the Store. 
//      It is assumed that all input is correctly formatted according to the 
//      homework specification file.

#ifndef STORE_H
#define STORE_H
#include <string>
#include <map>
#include <vector>
#include <set>
#include "customer.h"
#include "hashtable.h"
#include "binarysearchtree.h"

class HashMap;
class Store
{
public:
	Store() {}; // constructor
	~Store(); // destructor

	friend class Command; //so commands can access movie and customer list

	void readDVDMovies(std::string filename); // reads DVD movies
	void readCustomers(std::string filename); // reads customers 
	void readCommands(std::string filename); // reads commands
	static void printInventory(); // prints the inventory

private:
	// map that stores all the three BST's (Classic, Comedy and Drama BST's)
	static std::map< std::string, std::map<std::string, BinarySearchTree<Movie*>>> collection;
	static HashMap customerList; // hasp map that stores the list of customers
	static std::set<std::string> commandCodes; // codes for commands
	static std::set<std::string> mediaCodes; // codes for media
	static std::set<std::string> movieCodes; // codes for movies 
	
	
};

#endif
