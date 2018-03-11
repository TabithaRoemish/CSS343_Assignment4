//	File Name: drama.h
//	Programmer: Tabitha Roemish & Prathyusha Pillari
//	Date: February 23, 2018
//	File contains: drama class declaration [D]
//      Inherits from the Movie class. Holds a single Drama movie type’s attributes.

#include "drama.h"
#include <iostream>

// initializes the variables 
Drama::Drama(int stock, std::string director, std::string title, int year)
{
    this->stock = stock;
    this->director = director;
    this->title = title;
    this->releaseYear = year;
    this->key = title + std::to_string (year);
}

// prints the drama string
void Drama::print()
{
    // D, 10, Steven Spielberg, Schindler's List, 1993
    // print out the movie type, stock, director, title, and
    // release year
    std::cout << "D, " << this->stock << ", " << this->director << ", " <<
    this->title << ", " << this->releaseYear << std::endl;
}

// returns true if the this director is > than the object
// if director is same, retuns true if the this title is > than the object
bool Drama::operator>(Drama & dm)
{
    if (this->director > dm.director)
        return true;
    else if (this->director == dm.director)
        if (this->title > dm.title)
            return true;
    return false;
}

// returns true if the director and teh title are same
bool Drama::operator==(Drama & dm)
{
    if (this->director == dm.director && this->title == dm.title)
        return true;
    else
        return false;
}

// uses dynamic cast to comapre movie object and drama object
bool Drama::operator>(Movie & mv)
{
	Drama * ptr = dynamic_cast<Drama*>(&mv);
	return *this > *ptr;
}

// uses dynamic cast to comapre movie object and drama object
bool Drama::operator<(Movie & mv)
{
	Drama * ptr = dynamic_cast<Drama*>(&mv);
	return *ptr > *this;
}

// uses dynamic cast to comapre movie object and drama object
bool Drama::operator==(Movie & mv)
{
	Drama * ptr = dynamic_cast<Drama*>(&mv);
	return *this == *ptr;
}

// returns the key
std::string Drama::getKey()
{
	return key;
}
