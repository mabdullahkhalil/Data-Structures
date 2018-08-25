#include <iostream>
#include <fstream>
#include "openAddress.h"

using namespace std;

OpenAddress::OpenAddress(int A){

	tableSize=100;
	collisions=0;
	a=A;
	enteries=0;
	hashTable= new string[tableSize];
}

void OpenAddress::Load(char* file){
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

long OpenAddress::hash(string x){
	int lengthstr = x.length();
	unsigned long find_hash=0;
	for (int i = 0; i < lengthstr; ++i)
	{
		find_hash=find_hash + (x[lengthstr-i-1]*(pow(a,i)));
	}
	return (find_hash % tableSize);
}

long OpenAddress::getSize(){
	return tableSize;
}

int OpenAddress::loadfactor(){
	return (enteries*100)/tableSize;
}

void OpenAddress::resize(){

	enteries=0;
	collisions=0;
	tableSize=tableSize*2;
	hashTable=new string[tableSize];
}

void OpenAddress::insertItem(string Word){
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


	long get_hash=hash(Word);


	if (hashTable[get_hash].empty())
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
}


string OpenAddress::lookUp(string Word){
	long get_hash=hash(Word);

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
}  

int OpenAddress::Collisions(){
	return collisions;
}




