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
	virtual void print() = 0;
	virtual ~Movie() {};
	static Movie * create(std::string identifier); //return nullptr if error in string
	virtual bool operator>(Movie & mv) = 0;
	virtual bool operator==(Movie & mv) = 0;
	virtual std::string  getKey() = 0;
	std::vector<char> videoCode{ 'F', 'C', 'D' }; // hardcoded, need to update if new genres added
};

// *Hi Prat, we might need to tweak something in the collection in the store so the movies are sorted correctly
//  map sorts based on the key and our key is a string so we might need to do something so that it's sorting the movies. 

//ex file)
/*	F, 10, Nora Ephron, You've Got Mail, 1998
	D, 10, Steven Spielberg, Schindler's List, 1993
	C, 10, George Cukor, Holiday, Katherine Hepburn 9 1938
	C, 10, George Cukor, Holiday, Cary Grant 9 1938
	Z, 10, Hal Ashby, Harold and Maude, Ruth Gordon 2 1971
	D, 10, Phillippe De Broca, King of Hearts, 1967*/

#endif
