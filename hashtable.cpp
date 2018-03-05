// File Name: hashtable.cpp
// Programmer: Tabitha Roemish
// Date: March 3, 2018
// File includes: hashtable definitions

#include "hashtable.h"
#include <iostream>

HashMap::HashMap()
{
	table = new HashElement *[TABLE_SIZE];
	for (int i = 0; i < TABLE_SIZE; i++)
		table[i] = nullptr;
}
HashMap::~HashMap()
{
	for (int i = 0; i < TABLE_SIZE; i++)
	{
		if (table[i] != nullptr)
			delete table[i];
	}
	delete table;
}
int HashMap::HashFunction(int key)
{
	return key % TABLE_SIZE;
}
void HashMap::insert(int key, Customer * custPtr)
{
	int hash = HashFunction(key);
	while (table[hash] != nullptr && table[hash]->key != key)
		hash = HashFunction(hash + 1);
	if (table[hash] != nullptr)
		delete table[hash];
	table[hash] = new HashElement(key, custPtr);
}

Customer * HashMap::search(int key)
{
	int hash = HashFunction(key);
	while (table[hash] != nullptr && table[hash]->key != key)
		hash = HashFunction(hash + 1);
	if (table[hash] == nullptr)
		return nullptr;
	else
		return table[hash]->customer;
}

void HashMap::remove(int key)
{
	int hash = HashFunction(key);
	while (table[hash] != nullptr)
	{
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
		delete table[hash];
	std::cout << "Element Deleted" << std::endl; 
}