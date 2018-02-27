//	File Name: comedy.h
//	Programmer: Tabitha Roemish
//	Date: February 23, 2018
//	File contains: comedy class declaration

#ifndef COMEDY_H
#define COMEDY_H
#include <string>
#include "movie.h"



class Comedy : public Movie
{

public:
	// store movie in map<std::string titleDirector, movie *> F
	Comedy(int stock, std::string director, std::string title, std::string actor, int year); 
	virtual ~Comedy();
	virtual void print(); // F, 10, Nora Ephron, You've Got Mail, 1998

	//sort by title then year
	virtual bool operator>(Comedy & cm);
	virtual bool operator==(Comedy & cm);

private:
	int stock;
	std::string director;
	std::string title;
	int releaseYear;
		

};

#endif
