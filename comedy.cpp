//	File Name: comedy.cpp
//	Programmer: Tabitha Roemish & Prathyusha Pillari
//	Date: March 2, 2018
//	File contains: comedy class definitions
//      Inherits from the Movie class. Holds a single Comedy movie type’s attributes.

#include "comedy.h"
#include <iostream>

// constructor stores in map
Comedy::Comedy(int stock, std::string director, std::string title, int year)
{
    this->stock = stock;
    this->director = director;
    this->title = title;
    this->releaseYear = year;
    this->key = title + std::to_string (year);
	this->genre = "Comedy";
}

// prints the object
void Comedy::print()
{
    // F, 10, Nora Ephron, You've Got Mail, 1998
    // print out the movie type, stock, director, title, and
    // release year
    std::cout << "F, " << this->stock << ", " << this->director << ", " <<
    this->title << ", " << this->releaseYear << std::endl;
}

// returns true if the this title is > than the object's
// if title is same, retuns true if the this releaseYear is > than the object's 
bool Comedy::operator>(Comedy & cm)
{
	// compares the titles
    if (this->title > cm.title){
        return true;
    }
	// if title is =,compares the releaseYears 
    else if(this->title == cm.title){
        if (this->releaseYear > cm.releaseYear){
            return true;
        }
    }
    return false;
}

// returns true if the title and the releaseYear are same
bool Comedy::operator==(Comedy & cm)
{
	// comapres the titles and releaseYears
    if (this->title == cm.title && this->releaseYear == cm.releaseYear){
        return true;
    }
    else{
        return false;
    }
}

// uses dynamic cast to comapre movie object and drama object
bool Comedy::operator>(Movie & mv)
{
	// returns true if this is > movie object
	Comedy * ptr = dynamic_cast<Comedy*>(&mv);
	return *this > *ptr;
}

// uses dynamic cast to comapre movie object and drama object
bool Comedy::operator<(Movie & mv)
{
	// returns true if this is < movie object
	Comedy * ptr = dynamic_cast<Comedy*>(&mv);
	return *ptr > *this;
}

// uses dynamic cast to comapre movie object and drama object
bool Comedy::operator==(Movie & mv)
{
	// returns true if this is = movie object
	Comedy * ptr = dynamic_cast<Comedy*>(&mv);
	return *this == *ptr;
}

// gets the key
std::string Comedy::getKey() const
{
	return key;
}

// gets the stock
int Comedy::getStock() const
{
	return stock;
}

// borrows the movie by decrementing the stock
void Comedy::brwMovie()
{
	if (stock > 0)
		stock--;
}

// returns the movie by incrementing the stock
void Comedy::rtnMovie()
{
	stock++;
}

// returns teh title
std::string Comedy::getTitle() const
{
	return title;
}

// returns the genre
std::string Comedy::getGenre() const
{
	return genre;
}

// returns teh director
std::string Comedy::getDirector() const
{
	return director;
}

// returns the release year
int Comedy::getReleaseYear() const
{
	return releaseYear;
}
