#include <string.h>
#include <fstream>
#include <vector>
#include <math.h>
#include <iostream>
#include <string>
using namespace std;

class OpenAddress
{
private:
    long tableSize;
    string *hashTable;              // Include your linked list class for this!
    int a;                          // input to the hash function
    unsigned long collisions;
    int enteries;
public:
    OpenAddress(int A);                     // constructor
    void Load(char* file);                 // enters/loads values in the hash table
    long hash(string x);                  // calculates hash
    long getSize();                      // return the size of the table 
    int loadfactor();                   // returns the loadfactor of the hashtbale according to the enteries entered.
    void resize();                     // resizes the hashtable whent he values of the 80% of the table are filled
    void insertItem(string Word);     // Takes a hash of 'Word' and inserts it into hashTable accordingl
    string lookUp(string Word);      // Looks for 'Word' and if found, returns it
    int Collisions();               // Return number of collisions in hashTable.
};
