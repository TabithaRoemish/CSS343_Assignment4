
#include "movie.h"
#include <iostream>
#include <string>
#include <sstream>
#include "comedy.h"
#include "drama.h"
#include "classic.h"



Movie* Movie::create(std::string identifier)
{
    Movie* mov = NULL;
    char movieType = identifier[0];
    
    switch (movieType)
    {
        case 'C': {
            // create new Classic object & insert into BSTree
            // if exists already add new stock to existing stock
            
            // C, 10, George Cukor, Holiday, Cary Grant 9 1938
            // print out the movie type, stock, director, title, major
            // actor, release month, and release year
           
            std::string sC = identifier;
            std::stringstream ss(identifier);
            int stock = 0;
			std::string junk = "";
			std::getline(ss, junk, ' ');
			ss >> stock;
			std::getline(ss, junk, ' ');
            std::string director = "";
            std::getline(ss, director, ',');
            std::string title = "";
            std::getline(ss, title, ',');
			std::getline(ss, junk, ' ');
            std::string actorF = "";
			std::string actorL = "";
			std::string actorFullName = "";
            std::getline(ss, actorF, ' ');
			std::getline(ss, actorL, ' ');
			actorFullName = actorF + " " + actorL;
            int month = 0;
            ss >> month;
            int year = 0;
            ss >> year;
            
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
    return mov;
}
