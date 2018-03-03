//	File Name: classic.h
//	Programmer: Tabitha Roemish & Prathyusha Pillari
//	Date: February 23, 2018
//	File contains: classic class declaration

#ifndef CLASSIC_H
#define CLASSIC_H
#include <string>
#include "movie.h"



class Classic : public Movie
{
public:
	Classic(int stock, std::string director, std::string title, std::string actor, int month, int year);
	virtual ~Classic() {};
	virtual void print(); //C, 10, George Cukor, Holiday, Cary Grant 9 1938

	//sort by Release date then major actor
	virtual bool operator>(Classic & cm);
	virtual bool operator==(Classic & cm);

private:
	int stock;
	std::string director;
	std::string title;
	std::string actor;
	int releaseMonth;
	int releaseYear;


};


#endif
