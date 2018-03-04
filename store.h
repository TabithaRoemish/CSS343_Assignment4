//	File Name: store.h
//	Programmer: Tabitha Roemish
//	Date: February 23, 2018
//	File contains: classic class declaration

#ifndef STORE_H
#define STORE_H
#include <string>
#include <map>
#include <vector>
#include "customer.h"
#include "hashtable.h"

class Store
{
public:
	Store() {};
	~Store();

	friend class Command; //so commands can access movie and customer list

	void readDVDMovies(std::string filename);
	void readCustomers(std::string filename);
	void readCommands(std::string filename);
	

private:
	
	//each binary tree needs to have it's own key (smash up of properties)
	//classic - year + actor
	//Comedy = Title + year
	//Drama = director + title
	std::vector<std::string> inventory;
	std::map< std::string, std::map<std::string, std::map<std::string, Movie*>>> collection; //maybe use map instead
	HashMap customerList;
	
	Movie * findMovie(std::string mediaType, std::string genreCode, std::string stringKey); // return nullPtr if not found
	Customer* findCustomer(int custID); // return nullPtr if not found
	void printInventory();
};

#endif
