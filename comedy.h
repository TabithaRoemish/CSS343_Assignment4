//	File Name: comedy.h
//	Programmer: Tabitha Roemish & Prathyusha Pillari
//	Date: February 23, 2018
//	File contains: comedy class declaration
//      Inherits from the Movie class. Holds a single Comedy movie type’s attributes.

#ifndef COMEDY_H
#define COMEDY_H
#include <string>
#include "movie.h"

class Comedy : public Movie
{

public:
	// store movie in map<std::string titleDirector, movie *> F
	Comedy(int stock, std::string director, std::string title, int year); 
	virtual ~Comedy() {}; // destructor
	
	virtual void print(); // F, 10, Nora Ephron, You've Got Mail, 1998
	virtual std::string getKey() const;
	virtual int getStock()const;
	virtual std::string getTitle() const;
	virtual std::string getGenre() const;
	virtual std::string getDirector() const;
	virtual int getReleaseYear() const;
	virtual void brwMovie();
	virtual void rtnMovie();

	// sort by title then year
	// overloads
	virtual bool operator>(Comedy & cm);
	virtual bool operator==(Comedy & cm);

	virtual bool operator<(Movie & mv);
	virtual bool operator>(Movie & mv);
	virtual bool operator==(Movie & mv);

private:
	int stock;
	std::string director;
	std::string title;
	int releaseYear;
	// Title + year to store in BST and we can check key 
        // match rather than check random properties
	std::string key; 
	std::string genre;

};

#endif
