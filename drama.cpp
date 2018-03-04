//	File Name: drama.cpp
//	Programmer: Tabitha Roemish & Prathyusha Pillari
//	Date: March 2, 2018
//	File contains: drama class definitions

#include "drama.h"
#include <iostream>

Drama::Drama(int stock, std::string director, std::string title, std::string actor, int year)
{
    this->stock = stock;
    this->director = director;
    this->title = title;
    this->releaseYear = year;
    this->key = title + std::to_string (year);
}

void Drama::print()
{
    // D, 10, Steven Spielberg, Schindler's List, 1993
    // print out the movie type, stock, director, title, and
    // release year
    std::cout << "F, " << this->stock << ", " << this->director << ", " <<
    this->title << ", " << this->releaseYear << std::endl;
}
				  
bool Drama::operator>(Drama & dm)
{
    if (this->director > dm.director)
        return true;
    else if (this->director == dm.director)
        if (this->title > dm.title)
            return true;
    return false;
}

bool Drama::operator==(Drama & dm)
{
    if (this->director == dm.director && this->title == dm.title)
        return true;
    else
        return false;
}
