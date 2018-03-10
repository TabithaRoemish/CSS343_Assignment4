#include <stdio.h>
#include "movie.h"
#include <iostream>
#include <string.h>



//Movie* Movie::create(std::string identifier)
//{
//    Movie* mov = nullptr;
//    if(identifier == ""){
//        return mov;
//    }
//    char movieType = identifier[0];
//    switch (movieType)
//    {
//        case 'C': // create new Classic object & insert into BSTree
//            // if exists already add new stock to existing stock
//            mov = new Classic;
//            break;
//        case 'D': // create new Drama object & insert into BSTree
//            // if exists already add new stock to existing stock
//            mov = new Drama;
//            break;
//        case 'F': // create new Comedy object & insert into BSTree
//            // if exists already add new stock to existing stock
//            mov = new Comedy;
//            break;
//        default:  // print that movie type does not exist
//            return mov;
//    }
//
//}
