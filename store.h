//	File Name: store.h
//	Programmer: Tabitha Roemish
//	Date: February 23, 2018
//	File contains: classic class declaration

#ifndef STORE_H
#define STORE_H
#include <string>
#include <map>
#include "movie.h"
#include "customer.h"
#include "binarysearchtree.h" //for movie maps

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
	//first map is for media type (DVD) to add to collection DVDcollection["DVD"].at(Genre(F,C,D))->add(*mv)]
	//each binary tree needs to have it's own key (smash up of properties)
	//classic - year + actor
	//Comedy = Title + year
	//Drama = director + title
	std::map< std::string, std::map<std::string, BinarySearchTree<Movie*>*>> collection; 
	//customer hash 
	
	Movie * findMovie(std::string mediaType, std::string genreCode, std::string stringKey); // return nullPtr if not found
	Customer* findCustomer(int custID); // return nullPtr if not found
	void printInventory();
};

#endif
