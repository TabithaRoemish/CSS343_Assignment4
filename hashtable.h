//	File Name: hashtable.h
//	Programmer: Tabitha Roemish
//	Date: March 3, 2018
//	File contains: hashtable class declaration 
//      Hash table to the customer information
//      Has HashElement and HashMap classes

#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "customer.h"
#define TABLE_SIZE 300
class Customer;
class HashElement
{
public:
	int key; // key to store in the hash table
	Customer * customer; // pointer to the customer 
	// constructor to initialize customer pointer and key
	HashElement(int ky, Customer* cust) {
		key = ky;
		customer = cust;
	}

};

// Hash map class
class HashMap
{
public:
	HashMap(); // constructor
	~HashMap(); // destructor
	int HashFunction(int key);
	void insert(int key, Customer * custPtr);
	Customer * search(int key); // search function using key
	void remove(int key);
	void print();
	void clear();

private:
	HashElement **table;
};

#endif
