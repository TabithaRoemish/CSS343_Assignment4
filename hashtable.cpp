//      File Name: hashtable.cpp
//      Programmer: Tabitha Roemish
//      Date: March 3, 2018
//      File includes: hashtable definitions
//      Hash table to the customer information
//      Has HashElement and HashMap classes

#include "hashtable.h"
#include <iostream> 

// constructor which creates the table 
HashMap::HashMap()
{
	table = new HashElement *[TABLE_SIZE];
	for (int i = 0; i < TABLE_SIZE; i++)
		table[i] = nullptr;
}

// destroys the hash map to clear memory 
// uses helper method clear
HashMap::~HashMap()
{
	clear();
}

// destroys the hash map to clear memory 
void HashMap::clear()
{
	for (int i = 0; i < TABLE_SIZE; i++)
	{
		// deletes the objects
		if (table[i] != nullptr)
		{
			delete table[i]->customer; // release customer space
			delete table[i];
		}
	}
	delete[] table;
}

// creates the hash function 
int HashMap::HashFunction(int key)
{
	int modNumber = TABLE_SIZE - 1;
	return key % modNumber;
}

// insert into the hash map
void HashMap::insert(int key, Customer * custPtr)
{
	int hash = HashFunction(key);
	// adds it into the hash table
	while (table[hash] != nullptr && table[hash]->key != key)
		hash = HashFunction(hash + 1);
	if (table[hash] != nullptr)
		delete table[hash];
	table[hash] = new HashElement(key, custPtr);
}

// searchs the hash map using the key and returns the customer object
Customer * HashMap::search(int key)
{
	int hash = HashFunction(key);
	// searches for teh object using key
	while (table[hash] != nullptr && table[hash]->key != key)
		hash = HashFunction(hash + 1);
	if (table[hash] == nullptr)
		return nullptr;
	else
		return table[hash]->customer;
}

// prints the hash table
void HashMap::print()
{
	// iterates through the table and prints the objects
	for (int i = 0; i < TABLE_SIZE; i++)
	{
		if (table[i] != nullptr)
			std::cout << *table[i]->customer << std::endl;
	}
}

// removes the object from the table bbased on key 
void HashMap::remove(int key)
{
	int hash = HashFunction(key);
	while (table[hash] != nullptr)
	{
		// stores into hash
		if (table[hash]->key == key)
			break;
		hash = HashFunction(hash + 1);
	}
	if (table[hash] == nullptr)
	{
		std::cerr << "No Element found at key: " << key << std::endl;
		return;
	}
	else
		// deletes the object
		delete table[hash];
	std::cout << "Element Deleted" << std::endl; 
}
