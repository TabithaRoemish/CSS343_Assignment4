//	File Name: drama.h
//	Programmer: Tabitha Roemish
//	Date: February 23, 2018
//	File contains: drama class declaration [D]

#ifndef DRAMA_H
#define DRAMA_H
#include <string>
#include "movie.h"

class Drama : public Movie
{
public:
	// store movie in map<std::string titleDirector, movie *> D
	Drama(int stock, std::string director, std::string title, int year);
	virtual ~Drama() {};
	virtual void print(); // D, 10, Steven Spielberg, Schindler's List, 1993
	
	//sort by director then title
	virtual bool operator>(Drama & dm);
	virtual bool operator==(Drama & dm);
	virtual std::string  getKey() const;
	virtual int getStock() const;
	virtual std::string getTitle() const;
	virtual std::string getGenre() const;
	virtual std::string getDirector() const;
	virtual void brwMovie();
	virtual void rtnMovie();

	virtual bool operator<(Movie & mv);
	virtual bool operator>(Movie & mv);
	virtual bool operator==(Movie & mv);

private:
	int stock;
	std::string director;
	std::string title;
	int releaseYear;
	std::string key; //Title + year to store in BST and we can check key match rather than check random properties
	std::string genre;
};

#endif
