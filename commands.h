//	File Name: commands.h
//	Programmer: Tabitha Roemish & Prathyusha Pillari
//	Date: February 23, 2018
//	File contains: Command class declaration
//		command class is abstract class for movie types (Borrow[B], Return[R], Inventory[I], History[H])

#ifndef COMMANDS_H
#define COMMANDS_H
#include <string>
#include "movie.h"
#include "customer.h"
#include <vector>

class Command
{
public:
	virtual void print() = 0;
	virtual ~Command();
	virtual void execute();
	static Command * create(std::string identifier);
	std::vector<char> commandCodes{ 'B', 'R', 'I', 'H' };
};

//Command::create(std::string input)
//{ get char, get custId, get mediaType code, get videoCode,
//	check command code is valid else cout << "invalid action code"
//
//	Customer * = findCutomer(custId) 
//	check customer not nullptr else  cout << "incorrect customer ID"
//
//  check genreCode corect else cout << invalid videoCode
//  Movie * mvPtr;
//	switch(char)
//		case D : get director, get title
//		if (mvPtr = Store::findDVDMovie(videoCode, stringKey) != nullptr) / else, cout << "invalid movie"
//			new Command(custPtr, moviePtr);
//		case C: get/check month, get year, get actor
//		if (mvPtr = Store::findDVDMovie(videoCode, stringKey) != nullptr) / else, cout << "invalid movie"
//			new Command(custPtr, moviePtr);
//		case F: get title, get year
//		if (mvPtr = Store::findDVDMovie(videoCode, stringKey) != nullptr) / else, cout << "invalid movie"
//			new Command(custPtr, moviePtr);

#endif
