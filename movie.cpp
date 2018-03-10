#include <stdio.h>
#include "movie.h"
#include <iostream>
#include <string.h>



Movie* Movie::create(std::string identifier)
{
    Movie* mov = NULL;
    char movieType = identifier[0];
    
    switch (movieType)
    {
        case 'C': {// create new Classic object & insert into BSTree
            // if exists already add new stock to existing stock
            size_t pos = 0;
            std::string sC = identifier;
            std::string delimiter = ",";
            //C, 10, George Cukor, Holiday, Cary Grant 9 1938
            // print out the movie type, stock, director, title, major
            // actor, release month, and release year
            // int stock
            std::string tokenC = sC.substr(1, pos);
            int stockC = stoi (tokenC);
            sC.erase(0, pos + delimiter.length());
            
            // string director
            std::string directorC = sC.substr(1, pos);
            sC.erase(0, pos + delimiter.length());
            
            // string title
            std::string titleC = sC.substr(1, pos);
            sC.erase(0, pos + delimiter.length());
            
            // string actor
            std::string actor = sC.substr(1, pos);
            sC.erase(0, pos + delimiter.length());
            
            // int releaseMont
            std::string rmC = sC.substr(1, pos);
            int monthC = stoi (rmC);
            sC.erase(0, pos + delimiter.length());
            
            // int releaseYear
            std::string ryC = sC.substr(1, pos);
            int yearC = stoi (ryC);
            sC.erase(0, pos + delimiter.length());
            mov = new Classic(stockC, directorC, titleC, actor, monthC, yearC);
            break;
        }
        case 'D': { // create new Drama object & insert into BSTree
            // if exists already add new stock to existing stock
            // if exists already add new stock to existing stock
            std::string sD = identifier;
            size_t pos = 0;
            std::string delimiter = ",";
            // D, 10, Steven Spielberg, Schindler's List, 1993
            // print out the movie type, stock, director, title, and
            // release year
            
            // int stock
            std::string tokenD = sD.substr(1, pos);
            int stockD = stoi (tokenD);
            sD.erase(0, pos + delimiter.length());
            
            // string director
            std::string directorD = sD.substr(1, pos);
            sD.erase(0, pos + delimiter.length());
            
            // string title
            std::string titleD = sD.substr(1, pos);
            sD.erase(0, pos + delimiter.length());
            
            // int releaseYear
            std::string ryD = sD.substr(1, pos);
            int yearD = stoi (ryD);
            sD.erase(0, pos + delimiter.length());
            mov = new Drama(stockD, directorD, titleD, yearD);
            break;
        }
        case 'F': { // create new Comedy object & insert into BSTree
            // if exists already add new stock to existing stock
            std::string sF = identifier;
            // F, 10, Nora Ephron, You've Got Mail, 1998
            // F, 10, Joel Coen, Fargo, 1996
            // print out the movie type, stock, director, title, and
            // release year
            size_t pos = 0;
            std::string delimiter = ",";
            
            // int stock
            std::string tokenF = sF.substr(1, pos);
            int stockF = stoi (tokenF);
            sF.erase(0, pos + delimiter.length());
            
            // string director
            std::string directorF = sF.substr(1, pos);
            sF.erase(0, pos + delimiter.length());
            
            // string title
            std::string titleF = sF.substr(1, pos);
            sF.erase(0, pos + delimiter.length());
            
            // int releaseYear
            std::string ryF = sF.substr(1, pos);
            int yearF = stoi (ryF);
            sF.erase(0, pos + delimiter.length());
            mov = new Comedy(stockF, directorF, titleF, yearF);
            break;
        }
        default:  // print that movie type does not exist
            return mov;
    }
    return mov;
}
