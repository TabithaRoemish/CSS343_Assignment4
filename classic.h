//	File Name: classic.h
//	Programmer: Tabitha Roemish & Prathyusha Pillari
//	Date: February 23, 2018
//	File contains: classic class declaration
//      Inherits from the Movie class. Holds a single Classic movie type’s attributes.


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
	virtual std::string getKey() const;
	virtual int getStock()const;
	virtual std::string getTitle() const;
	virtual std::string getGenre() const;
	virtual std::string getDirector() const;
	virtual int getReleaseYear() const;
	virtual void brwMovie();
	virtual void rtnMovie();

	virtual bool operator<(Movie & mv);
	virtual bool operator>(Movie & mv);
	virtual bool operator==(Movie & mv);

private:

	int stock;
	std::string genre;
	std::string director;
	std::string title;
	std::string actor;
	int releaseMonth;
	int releaseYear;
	std::string key; //Title + year to store in BST and we can check key match rather than check random properties

};


#endif
