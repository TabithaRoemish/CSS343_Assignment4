//	File Name: classic.cpp
//	Programmer: Tabitha Roemish & Prathyusha Pillari
//	Date: March 2, 2018
//	File contains: classic class definitions
//      Inherits from the Movie class. Holds a single Classic movie type’s attributes.


#include "classic.h"
#include <iostream>

// constructor adds into the map
Classic::Classic(int stock, std::string director, std::string title, std::string actor, int month, int year)
{
    this->stock = stock;
    this->director = director;
    this->title = title;
	this->actor = actor;
    this->releaseMonth = month;
    this->releaseYear = year;
    this->key = std::to_string(year) + actor;
	this->genre = "Classic";
}

// prints the obbject
void Classic::print()
{
    //C, 10, George Cukor, Holiday, Cary Grant 9 1938
    // print out the movie type, stock, director, title, major
    // actor, release month, and release year
	std::cout << "C, " << this->stock << ", " << this->director << ", " <<
    this->title << ", " << this->actor << ", " << this->releaseMonth << " "
    << this->releaseYear << std::endl;
}

//Classic sorted by release date and then actor
// returns true if the this releaseYear is > than the object
// if releaseYear is same, retuns true if the this releaseMonth is > than the object
bool Classic::operator>(Classic & cl)
{
	// comapres the releaseYears
    if (this->releaseYear > cl.releaseYear)
        return true;
	// comapres the releaseMonths if releaseYear are equal
	else if (this->releaseYear == cl.releaseYear)
	{
		if (this->releaseMonth > cl.releaseMonth)
			return true;
		else if (this->releaseMonth == cl.releaseMonth)
			if (this->actor > cl.actor)
				return true;
	}
    return false;
}

// returns true if the releaseYear and the releaseMonth 
// and the actors are same
bool Classic::operator==(Classic & cl)
{
	// compares releaseYear, releaseMonth and actors
    if (this->releaseYear == cl.releaseYear &&
        this->releaseMonth == cl.releaseMonth &&
        this->actor == cl.actor)
        return true;
    else
        return false;
}

// uses dynamic cast to comapre movie object and drama object
bool Classic::operator>(Movie & mv)
{
	// returns true if this is > movie object
	Classic * ptr = dynamic_cast<Classic*>(&mv);
	return  *this > *ptr;
}

// uses dynamic cast to comapre movie object and drama object
bool Classic::operator<(Movie & mv)
{
	// returns true if this is < movie object
	Classic * ptr = dynamic_cast<Classic*>(&mv);
	return *ptr > *this;
}

// uses dynamic cast to comapre movie object and drama object
bool Classic::operator==(Movie & mv)
{
	// returns true if this is = movie object
	Classic * ptr = dynamic_cast<Classic*>(&mv);
	return *this == *ptr;
}

// returns for teh private variables
std::string Classic::getKey() const
{
	return key;
}

int Classic::getStock() const
{
	return stock;
}

void Classic::brwMovie()
{
	if (stock > 0)
		stock--;
}

void Classic::rtnMovie()
{
	stock++;
}

std::string Classic::getTitle() const
{
	return title;
}

std::string Classic::getGenre() const
{
	return genre;
}

std::string Classic::getDirector() const
{
	return director;
}

int Classic::getReleaseYear() const
{
	return releaseYear;
}

