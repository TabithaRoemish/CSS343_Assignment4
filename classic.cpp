//	File Name: classic.cpp
//	Programmer: Tabitha Roemish & Prathyusha Pillari
//	Date: March 2, 2018
//	File contains: classic class definitions

#include "classic.h"
#include <iostream>

Classic::Classic(int stock, std::string director, std::string title, std::string actor, int month, int year)
{
    this->stock = stock;
    this->director = director;
    this->title = title;
    this->releaseMonth = month;
    this->releaseYear = year;
    //this->key = title + std::to_string (year);
}

void Classic::print()
{
    //C, 10, George Cukor, Holiday, Cary Grant 9 1938
    // print out the movie type, stock, director, title, major
    // actor, release month, and release year
    std::cout << "C, " << this->stock << ", " << this->director << ", " <<
    this->title << ", " << this->actor << ", " << this->releaseMonth
    << this->releaseYear << std::endl;
}

bool Classic::operator>(Classic & cl)
{
    if (this->releaseYear > cl.releaseYear)
        return true;
    else if (this->releaseYear == cl.releaseYear)
        if (this->releaseMonth > cl.releaseMonth)
            return true;
        else if (this->releaseMonth == cl.releaseMonth)
            if (this->actor > cl.actor)
                return true;
    return false;
}

bool Classic::operator==(Classic & cl)
{
    if (this->releaseYear == cl.releaseYear &&
        this->releaseMonth == cl.releaseMonth &&
        this->actor == cl.actor)
        return true;
    else
        return false;
}
