#include <iostream>
#include <fstream>
#include "Chaining.h"
#include "LinkedList.cpp"

using namespace std;

HashC::HashC(int _a){
	tableSize=100;
	collisions=0;
	a=_a;
	hashTable= new LinkedList<string>[tableSize];


}

void HashC::Load(char* file){
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


long HashC::hash(string st){
	int lengthstr = st.length();
	unsigned long find_hash=0;
	for (int i = 0; i < lengthstr; ++i)
	{
		find_hash=find_hash + (st[lengthstr-i-1]*(pow(a,i)));
	}
	return (find_hash % tableSize);

}

void HashC::insert(string word){
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

ListItem<string>* HashC::lookup(string mm){
	int get_hash=hash(mm);
	return hashTable[get_hash].searchFor(mm);

}


		int HashC::Collisions(){
			return collisions;
		} // Return number of c