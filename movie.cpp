//	File Name: ass4.cpp
//	Programmer: Tabitha Roemish, Prathyusha Pillari 
//	Date: February 23, 2018
//	File contains: Movie class declaration
//		movie class is abstract class for movie types (Comedy[F], Drama[D], Classic[C])
//     The parent class to Comedy, Drama and Classics classes.
//     This is an abstract class where the child classes must implement the methods within it.

#include "movie.h"
#include <iostream>
#include <string>
#include <sstream>
#include "comedy.h"
#include "drama.h"
#include "classic.h"

// create function for the movie class
Movie* Movie::create(std::string identifier)
{
    // movie object to return
    Movie* mov = NULL;
    // gets the movie type (C, F or D)
    char movieType = identifier[0];
    
    // switch statement to create the movie object of correct type
    switch (movieType)
    {
        case 'C': {
            // create new Classic object & insert into BSTree
            // if exists already add new stock to existing stock
            
            // C, 10, George Cukor, Holiday, Cary Grant 9 1938
            // print out the movie type, stock, director, title, major
            // actor, release month, and release year
           
	    // uses string stream to read in from the string
            std::stringstream ss(identifier);
            int stock = 0;
	    // junk gets rid of the extra space when we 
	    // parse using a space deliminator
	    std::string junk = "";
	    std::getline(ss, junk, ' ');
	    // reads in the stock number and stores it
	    ss >> stock;
	    std::getline(ss, junk, ' ');
	    // reads in the director and stores it
            std::string director = "";
            std::getline(ss, director, ',');
			ss.get(); //get space before title
	    // reads in the title and stores it
            std::string title = "";
            std::getline(ss, title, ',');
			std::getline(ss, junk, ' ');
	    // reads in the actor's full name and stores it
            std::string actorF = "";
			std::string actorL = "";
			std::string actorFullName = "";
            std::getline(ss, actorF, ' ');
			std::getline(ss, actorL, ' ');
			actorFullName = actorF + " " + actorL;
            // reads in the month and year and stores it
	    int month = 0;
            ss >> month;
            int year = 0;
            ss >> year;
            
            // creates the movie obbject of type classic
            mov = new Classic(stock, director, title, actorFullName, month, year);
            break;
        }
        case 'D': {
            // create new Drama object & insert into BSTree
            // if exists already add new stock to existing stock
            // if exists already add new stock to existing stock
            
            // D, 10, Steven Spielberg, Schindler's List, 1993
            // print out the movie type, stock, director, title, and
            // release year
            
            std::string s = identifier;
            std::stringstream ss(identifier);
            int stock = 0;
			std::string junk = "";
			std::getline(ss, junk, ' ');
			ss >> stock;
			std::getline(ss, junk, ' ');
			std::string director = "";
			std::getline(ss, director, ',');
			ss.get();//get space before title
			std::string title = "";
			std::getline(ss, title, ',');
			std::getline(ss, junk, ' ');
            int year = 0;
            ss >> year;
            
            mov = new Drama(stock, director, title, year);
            break;
        }
        case 'F': { 
            // create new Comedy object & insert into BSTree
            // if exists already add new stock to existing stock

            // F, 10, Nora Ephron, You've Got Mail, 1998
            // F, 10, Joel Coen, Fargo, 1996
            // print out the movie type, stock, director, title, and
            
            std::string s = identifier;
            std::stringstream ss(identifier);
			int stock = 0;
			std::string junk = "";
			std::getline(ss, junk, ' ');
			ss >> stock;
			std::getline(ss, junk, ' ');
			std::string director = "";
			std::getline(ss, director, ',');
			ss.get(); //get space before title
			std::string title = "";
			std::getline(ss, title, ',');
			std::getline(ss, junk, ' ');
			int year = 0;
			ss >> year;
            
            mov = new Comedy(stock, director, title, year);
            break;
        }
        default:  // print that movie type does not exist
            return mov;
    }
    return mov; // returns the movie pointer
}


