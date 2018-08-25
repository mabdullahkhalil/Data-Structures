#include <iostream>
#include <fstream>
#include "final.h"
#include "LinkedList.cpp"

using namespace std;

Final::Final(int _a){
	tableSize=100;
	collisions=0;
	a=_a;
	hashTable= new LinkedList<string>[tableSize];


}

void Final::Load(char* file){
	ifstream open_file;
	open_file.open(file);

	if (open_file.fail())
	{
		cout<<"NO FILE"<<endl;
	}
	char get_line[30];

	while(!open_file.eof()){
		open_file.getline(get_line,30);
		insert(get_line);

	}
	open_file.close();


} 


long Final::hash(string x){
	int lengthstr=x.length();
	unsigned long findhash=0;
	for (int i=0; i<lengthstr; i++) {
		findhash ^= (findhash<<5)+(findhash>>2)+x[i];
	}
	return (findhash % tableSize);

}

void Final::insert(string word){
	int get_hash=hash(word);
	if (get_hash<0)
	{
	}
	if (hashTable[get_hash].getHead()!=NULL)
	{
		hashTable[get_hash].insertAtHead(word);
		collisions++;
	}
	else if (hashTable[get_hash].getHead()==NULL)
	{
		hashTable[get_hash].insertAtHead(word);

	}


}

bool Final::lookup(string mm){
	int get_hash=hash(mm);
	ListItem<string>* word= hashTable[get_hash].searchFor(mm);
	if (word->value==mm)
	{
		return true;
	}
	return false;

}


int Final::Collisions(){
	return collisions;
} // Return number of c