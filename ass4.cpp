//	File Name: ass4.cpp
//	Programmer: Tabitha Roemish & Prathyusha Pillari
//	Date: February 23, 2018
//	File contains: main()
//      This class runs the main method that is used to run the
//      "Movie Rental Store"

#include<iostream>
#include "store.h"
using namespace std;

#include "binarysearchtree.h"

int main()
{
	Store st;
	st.readCustomers("data4customers.txt");
	st.readDVDMovies("data4movies.txt");
	st.readCommands("data4commands.txt");

	return 0;
}

