#ifndef GRAPH__H
#define GRAPH__H
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <fstream>
#include <set>
#include <algorithm>
#include "pqueue.h"

using namespace std;
class node;

class edge
{
	public:
    edge(node* l,node* m,float n){
        Origin=l;
        Dest=m;
        weight=n;
    }
    edge(){};
		node* Origin;
		node* Dest;
		float weight;	
		friend bool operator < (edge a, edge b);
		friend bool operator == (edge a, edge b);
		friend bool operator > (edge a, edge b);
};
class node
{
	public:
    node(){
        name="nothing";
        x=0;
        y=0;
    }
    node(string coming){
        name=coming;
    }
    node(string l,float m,float n){
        name=l;
        x=m;
        y=n;
    }
		int visit; // flag to check if the node has been already visited
		float dist;
		string name;
		node* prev;
		
		float x,y; // coordinates of node
		float key; // SHOULD BE USED ONLY IN PRIM'S ALGORITHM ( used to set the priority in your binary heap )
		vector<edge> edges; // edges connected to node
		friend bool operator < (node a, node b);
		friend bool operator == (node a, node b);
		friend bool operator > (node a, node b);
};
class tree
{
	public:
		set<node*> treeS;
};
class Graph
{
	public:
		vector<node*> Mst; // minimum spanning tree
		vector<node*> cities;
		vector<edge> arcs;
		Graph(char*);
		node* getCity(string s);
		void display(node*);// displays the graph

		vector<node*> Prims();
		vector<node*> Kruskal(); //runs kruskal algorithm and returns the Minimum spanning tree
		vector<string> Dijkstra(string, string, float &);
    
    int find(node* a, vector<set<node*> > graphnodes){
        for (int i=0; i<graphnodes.size(); i++) {
            if (graphnodes[i].end()!=graphnodes[i].find(a)) {
                return i;
            }
        }
        return -1;
        
    }
    
    bool inreturning(string x,vector<string> returning){
        for (int i=0; i<returning.size(); i++) {
            if (returning[i]==x) {
                return true;
            }
        }
        return false;
    }
    
    vector<node*> InsertionSort(vector<node*> nums)
    {
        node* array=new node[nums.size()];
        for (int i = 0; i < nums.size(); ++i)
        {
            array[i]=*nums[i];
        }
        for (int i = 0; i < nums.size(); ++i)
        {
            int j=i;
            while (j>0 && array[j]<array[j-1]){
                node temp = array[j];
                array[j]=array[j-1];
                array[j-1]=temp;
                j--;
            }
        }
        vector<node*> sending;
        for (int i = 0; i < nums.size(); ++i)
        {
            sending.push_back(&array[i]);
        }
        return sending;
        
    }
    
    
    
};

#endif

