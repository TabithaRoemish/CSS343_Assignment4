//	File Name: hashtable.h
//	Programmer: Tabitha Roemish
//	Date: March 3, 2018
//	File contains: hashtable class declaration 

#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "customer.h"
#define TABLE_SIZE 100
class Customer;
class HashElement
{
public:

	int key;
	Customer * customer;
	HashElement(int ky, Customer* cust) {
		key = ky;
		customer = cust;
	}

};

class HashMap
{
public:
	HashMap();
	~HashMap();
	int HashFunction(int key);
	void insert(int key, Customer * custPtr);
	Customer * search(int key);
	void remove(int key);
	void print();
	void clear();

private:
	HashElement **table;
};

#endif