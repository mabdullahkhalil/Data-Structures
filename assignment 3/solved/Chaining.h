#ifndef CHAINING__H
#define CHAINING__H
#include <iostream>
#include "LinkedList.cpp" // Your Own Implementation
#include <cstring>
#include <fstream>
#include "math.h"

using namespace std;
class HashC
{
protected:
	long tableSize;
	int collisions; 
	int a; 
	LinkedList<string>* hashTable;
	
public:
	HashC(int _a);

	void Load(char* file);


		// Load a file of Strings into your Hash table


		long hash(string st);




		// Given a String, return its hash

	 // Takes a hash of 'word' and inserts it into hashTable accordingly

		void insert(string word);
		ListItem<string>* lookup(string mm);


		int Collisions(); 
	};
#endif
