#ifndef __TREE_CPP
#define __LIST_CPP
#include "tree.h"
#include <fstream>
#include <iostream>
#include <stdlib.h>

Tree::Tree()
{
    head=NULL;
}

Tree::Tree(string file)
{
    head==NULL;
    ifstream inp;
    inp.open(file);
    
    char line[50];
    
    while (!inp.eof() ){
        string x=getline(inp,line,'/');
        cout<<x<<endl;
        cout<<line<<endl;
        insert(line);
        
    }
    
    
    
}
Tree::~Tree()
{
    delete head;
}

void Tree::insert(string item)
{
    
    
    
}
/*
 vector<string> Tree::Locate(string qry)
 {
 }
 
 string Tree::LComAc(string a, string b)
 {
 }*/

TreeItem* Tree::getHead()
{
    return head;
}
/*
 int Tree::countFiles()
 {
 }*/

#endif
