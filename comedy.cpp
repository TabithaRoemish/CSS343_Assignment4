//	File Name: comedy.cpp
//	Programmer: Tabitha Roemish & Prathyusha Pillari
//	Date: March 2, 2018
//	File contains: comedy class definitions

#include "comedy.h"
#include <iostream>

Comedy::Comedy(int stock, std::string director, std::string title, int year)
{
    this->stock = stock;
    this->director = director;
    this->title = title;
    this->releaseYear = year;
    this->key = title + std::to_string (year);
	this->genre = "Comedy";
}

void Comedy::print()
{
    // F, 10, Nora Ephron, You've Got Mail, 1998
    // print out the movie type, stock, director, title, and
    // release year
    std::cout << "F, " << this->stock << ", " << this->director << ", " <<
    this->title << ", " << this->releaseYear << std::endl;
}

bool Comedy::operator>(Comedy & cm)
{
    if (this->title > cm.title){
        return true;
    }
    else if(this->title == cm.title){
        if (this->releaseYear > cm.releaseYear){
            return true;
        }
    }
    return false;
}

bool Comedy::operator==(Comedy & cm)
{
    if (this->title == cm.title && this->releaseYear == cm.releaseYear){
        return true;
    }
    else{
        return false;
    }
}

bool Comedy::operator>(Movie & mv)
{
	Comedy * ptr = dynamic_cast<Comedy*>(&mv);
	return *this > *ptr;
}

bool Comedy::operator<(Movie & mv)
{
	Comedy * ptr = dynamic_cast<Comedy*>(&mv);
	return *ptr > *this;
}

bool Comedy::operator==(Movie & mv)
{
	Comedy * ptr = dynamic_cast<Comedy*>(&mv);
	return *this == *ptr;
}

std::string Comedy::getKey() const
{
	return key;
}
int Comedy::getStock() const
{
	return stock;
}
void Comedy::brwMovie()
{
	if (stock > 0)
		stock--;
}
void Comedy::rtnMovie()
{
	stock++;
}

std::string Comedy::getTitle() const
{
	return title;
}
std::string Comedy::getGenre() const
{
	return genre;
}
std::string Comedy::getDirector() const
{
	return director;
}
