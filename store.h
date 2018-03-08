//	File Name: store.h
//	Programmer: Tabitha Roemish
//	Date: February 23, 2018
//	File contains: classic class declaration

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
	Store() {};
	~Store();

	friend class Command; //so commands can access movie and customer list

	void readDVDMovies(std::string filename);
	void readCustomers(std::string filename);
	void readCommands(std::string filename);
	static void printInventory();

private:
	static std::map< std::string, std::map<std::string, BinarySearchTree<Movie*>>> collection;
	static HashMap customerList;
	static std::set<std::string> commandCodes;
	static std::set<std::string> mediaCodes;
	static std::set<std::string> movieCodes;
	
	
};

#endif
