#include <iostream>
#include <fstream>
#include "doubleHash.h"

using namespace std;


DoubleHash::DoubleHash(int A){
	tableSize=100;
	collisions=0;
	a=A;
	enteries=0;
	hashTable= new string[tableSize];
}


void DoubleHash::Load(char* file){
	ifstream open_file;
	open_file.open(file);

	if (open_file.fail())
	{
		cout<<"NO FILE"<<endl;
		return;
	}
	char get_line[30];

	while(!open_file.eof()){
		open_file.getline(get_line,30);
		insertItem(get_line);
	}
	open_file.close();

}


long DoubleHash::getSize(){
	return tableSize;
}


void DoubleHash::resize(){
	enteries=0;
	collisions=0;
	tableSize=tableSize*2;
	hashTable=new string[tableSize];
}


void DoubleHash::insertItem(string Word){
	if (loadfactor() >= 80)
	{
		int x=tableSize*0.8;
		vector<string> arraystoring;
		for (int i=0; i<tableSize; i++) {
			while (hashTable[i]=="\0" && i<tableSize) {
				i++;
			}
			arraystoring.push_back(hashTable[i]);
		}

		resize();

		for (int i=0; i<x; i++) {
			insertItem(arraystoring[i]);
		}

	}

	int get_hash=hash(Word);


	if (hashTable[get_hash]=="\0")
	{
		hashTable[get_hash]=Word;
		enteries++;
		return;
	}
	else if (hashTable[get_hash]!="")
	{
		while (hashTable[get_hash]!=""){
			collisions++;
			if (get_hash==tableSize-1)
			{
				get_hash=-1;
			}
			get_hash++;
		}

		hashTable[get_hash]=Word;
		enteries++;

		return;
	}
}   // Takes a hash of 'Word' and inserts it into hashTable accordingly
long DoubleHash::hash1(string x){
	int lengthstr=x.length();
	unsigned long findhash=0;
	for (int i=0; i<lengthstr; i++) {
		findhash ^= (findhash<<5)+(findhash>>2)+x[i];
	}
	return (findhash % tableSize);
}

long DoubleHash::hash(string word){
	return ((((tableSize-30)*hash1(word)+(tableSize-60))%tableSize-1)+(((tableSize-30)*hash2(word)+(tableSize-60))%tableSize-1)) % (tableSize);
}

long DoubleHash::hash2(string x){
	int lengthstr = x.length();
	unsigned long find_hash=0;
	for (int i = 0; i < lengthstr; ++i)
	{
		find_hash=find_hash + (x[lengthstr-i-1]*(pow(a,i)));
	}
	return (find_hash % tableSize);
}


int DoubleHash::loadfactor(){
	return (enteries*100)/tableSize;
}


string DoubleHash::lookUp(string Word){
	int get_hash=hash(Word);

	if (hashTable[get_hash]==Word)
	{
		return hashTable[get_hash];
	}
	else if (hashTable[get_hash]!=Word)
	{
		while (hashTable[get_hash]!=Word){
			if (get_hash==tableSize-1)
			{
				get_hash=-1;
			}
			get_hash++;
		}
		return hashTable[get_hash];
	}
	return NULL;
}   // Looks for 'Word' and if found, returns it
int DoubleHash::Collisions(){
	return collisions;
} // Return number of collisions in hashTable.