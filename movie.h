//	File Name: ass4.cpp
//	Programmer: Tabitha Roemish
//	Date: February 23, 2018
//	File contains: Movie class declaration
//		movie class is abstract class for movie types (Comedy[F], Drama[D], Classic[C])

#ifndef MOVIE_H
#define MOVIE_H
#include <vector>
#include <string>

class Movie
{
public:
	Movie() {};
	virtual ~Movie() {};
	static Movie * create(std::string identifier); //return nullptr if error in string

	virtual void print() = 0;
	virtual bool operator>(Movie & mv) = 0;
	virtual bool operator<(Movie & mv) = 0;
	virtual bool operator==(Movie & mv) = 0;

	virtual std::string  getKey() const = 0;
	virtual int getStock() const = 0;
	virtual std::string getTitle() const = 0;
	virtual std::string getGenre() const = 0;
	virtual std::string getDirector() const = 0;
	virtual void brwMovie() = 0;
	virtual void rtnMovie() = 0;

};

//ex file)
/*	F, 10, Nora Ephron, You've Got Mail, 1998
	D, 10, Steven Spielberg, Schindler's List, 1993
	C, 10, George Cukor, Holiday, Katherine Hepburn 9 1938
	C, 10, George Cukor, Holiday, Cary Grant 9 1938
	Z, 10, Hal Ashby, Harold and Maude, Ruth Gordon 2 1971
	D, 10, Phillippe De Broca, King of Hearts, 1967*/

#endif
