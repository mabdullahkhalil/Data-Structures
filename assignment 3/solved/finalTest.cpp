#ifndef MAIN
#define MAIN

#include "final.cpp"
#include "time.h"
#include "assert.h"

int main()
{
    ofstream fout;
    fout.open("col.txt");
    char buf[256];
    Final c(37);
    string* qs = new string[20000];
    
    c.Load("dict.txt");

    ifstream ifin;
    ifin.open("queries.txt");
    int n=0;
    
    while(!ifin.eof())
    {
        ifin.getline(buf,256,'\n');
        string str = buf;
        qs[n++] = str;
    }
    
   
    string search;
    cout<<"search: "; cin>>search;
    startTimer();
    if (c.lookup(search))
    {
        cout<<"the time to search "<<search<<" is ";
        stopTimer();
    }
    else {
        cout<<"there is no such word"<<endl;
    }
    cout << "Passed" << endl;
}

#endif
