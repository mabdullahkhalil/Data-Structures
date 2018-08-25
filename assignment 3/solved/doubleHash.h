#include <string.h>
#include <fstream>
#include <vector>
#include <string>
#include <math.h>
#include <iostream>
using namespace std;

class DoubleHash
{
private:
    long tableSize;
    string *hashTable;              // Include your linked list class for this!
    int a;                          // input to the hash function
    int collisions;
    int enteries;
public:
    
    
    DoubleHash(int A);
    
    
    void Load(char* file);
    
    long getSize();
    
    
    void resize();
    
    
    void insertItem(string Word);
    long hash1(string x);
    
    long hash(string word);
    
    long hash2(string x);
    
    int loadfactor();
    
    
    string lookUp(string Word); // Looks for 'Word' and if found, returns it
    int Collisions();// Return number of collisions in hashTable.
};