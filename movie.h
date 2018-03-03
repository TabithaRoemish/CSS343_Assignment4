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
	std::vector<char> videoCode{ 'F', 'C', 'D' }; // hardcoded, need to update if new genres added
};

//can we just define create here? do wo have to make another freaking file?

#endif
