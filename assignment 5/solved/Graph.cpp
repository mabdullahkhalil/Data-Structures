#ifndef GRAPH__CPP
#define GRAPH__CPP
#include <iostream>
#include <fstream>
#include <math.h>
#include <vector>
#include "Graph.h"

using namespace std;

bool operator == (edge a, edge b)
{
    if (a.weight==b.weight) {
        return true;
    }
    return false;
}

bool operator < (edge a, edge b)
{
    if (a.weight<b.weight) {
        return true;
    }
    return false;
}

bool operator > (edge a, edge b)
{
    if (a.weight>b.weight) {
        return true;
    }
    return false;
}
bool operator < (node a, node b)
{
    if (a.dist<b.dist) {
        return true;
    }
    return false;
}

bool operator > (node a, node b)
{
    if (a.dist>b.dist) {
        return true;
    }
    return false;
}

Graph::Graph(char* file)
{
    ifstream inp;
    inp.open(file);
    if (inp.fail())
    {
        cout << "Error reading file!\n";
        exit(1);
    }
    string na;
    float ex,why;
    string rough;
    inp >> rough;
    inp >> na;
    while (!inp.eof()) {
        while (na!="ARCS") {
            inp >> ex;
            inp >> why;
            node* nodes= new node(na,ex,why);
            cities.push_back(nodes);
            inp >> na;
        }
        
        string origi,desti;
        float weighty;
        inp >> origi;
        inp >> desti;
        inp >> weighty;
        if (!desti.empty()){
            node* origin_node = getCity(origi);
            node* dest_node= getCity(desti);
            edge temp_edge_ori(origin_node,dest_node,weighty);
            origin_node->edges.push_back(temp_edge_ori);
            arcs.push_back(temp_edge_ori);
            edge temp_edge_dst(dest_node,origin_node, weighty);
            dest_node->edges.push_back(temp_edge_dst);
        }
    }
}
node* Graph::getCity(string s)
{
    for (int i=0; i<cities.size(); i++) {
        if (cities[i]->name==s) {
            return cities[i];
        }
    }
    return NULL;
}
void Graph::display(node* temp)
{
    if(temp->visit)
        return;
    cout << "AT: " << temp->name;
    temp->visit = 1;
    for(int i=0; i< temp->edges.size(); i++)
    {
        if(!temp->edges[i].Origin->visit || !temp->edges[i].Dest->visit)
            cout << "->" << temp->edges[i].weight << endl;
        display(temp->edges[i].Origin);
        display(temp->edges[i].Dest);
    }
}
vector<node*> Graph::Prims()
{
    vector<node *> f;
    return f;
}


vector<node*> Graph::Kruskal()
{
    pqueue<edge> pheap(arcs,arcs.size());
    
    tree thistree;
    vector<set<node*> > graphnodes;
    vector<edge> selectededges;
    vector<node* > returning;
    
    for (int i=0; i<cities.size(); i++) {
        set<node*> temporary;
        temporary.insert(cities[i]);
        graphnodes.push_back(temporary);
    }
    while (pheap.getsize()>1) {
        edge testing=pheap.ExtractMin();
        int start=find(testing.Origin,graphnodes);
        int end=find(testing.Dest,graphnodes);
        if (start!=end) {
            selectededges.push_back(testing);
            graphnodes[start].insert(graphnodes[end].begin(), graphnodes[end].end());
            graphnodes.erase(graphnodes.begin() + end);
            
        }
        else{
            continue;
        }
        
    }
   	for (int i = 0; i < selectededges.size(); i++)
    {   node* origin;
        node* dest;
        vector<node*> array;
        int des=0;
        int ori=0;
        if (returning.empty()) {
            origin=new node(selectededges[i].Origin->name);
            dest=new node(selectededges[i].Dest->name);
        }
        if (!returning.empty()) {
            for (int j=0; j<returning.size()-1; j=j+2) {
                if (ori==0){
                    if (returning[j]->name==selectededges[i].Origin->name) {
                        origin=returning[j];
                        array.push_back(origin);
                        ori=1;
                    }
                    else if(returning[j+1]->name==selectededges[i].Origin->name){
                        origin=returning[j+1];
                        array.push_back(origin);
                        ori=1;
                    }
                    else{
                        origin=new node(selectededges[i].Origin->name);
                    }
                }
                if(des==0){
                    if (returning[j]->name==selectededges[i].Dest->name) {
                        dest=returning[j];
                        array.push_back(dest);
                        des=1;
                    }
                    else if(returning[j+1]->name==selectededges[i].Dest->name){
                        dest=returning[j+1];
                        array.push_back(dest);
                        des=1;
                    }
                    else{
                        dest=new node(selectededges[i].Dest->name);
                    }
                }
            }
        }
        
        if (des==1 && ori==0) {
            dest=array[0];
        }
        else  if (des==0 && ori==1) {
            origin=array[0];
        }
        else  if (des==1 && ori==1) {
            dest=array[0];
            origin=array[1];
        }
        edge temp_edge_ori(origin,dest,selectededges[i].weight);
        origin->edges.push_back(temp_edge_ori);
        edge temp_edge_dst(dest,origin, selectededges[i].weight);
        dest->edges.push_back(temp_edge_dst);
        returning.push_back(origin);
        returning.push_back(dest);
    }
    return returning;
}



vector<string> Graph::Dijkstra(string city, string destination, float &d)
{
    int cost=0;
    vector<node*> cityy;
    for (int i=0; i<cities.size(); i++) {
        if (cities[i]->name==city) {
            cities[i]->dist=d;
            cityy.push_back(cities[i]);
            continue;
        }
        cities[i]->dist=1000000000;
        cityy.push_back(cities[i]);
    }
    vector<string> returning;
    node* extract = nullptr;
    vector<node* > came=InsertionSort(cityy);
    while (!came.empty()) {
        extract=came[0];
        cost=cost+extract->dist;
        came.erase(came.begin());
        returning.push_back(extract->name);
        
        for (int i=0; i<extract->edges.size(); i++) {
            if (extract->dist + extract->edges[i].weight < extract->edges[i].Dest->dist && !inreturning(extract->edges[i].Dest->name, returning)) {
                extract->edges[i].Dest->dist=extract->dist + extract->edges[i].weight;
            }
        }
        vector<node*> came1;
        for (int i=0; i<came.size()+1; i++) {
            if (cityy[i]->name==extract->name) {
                cityy.erase(cityy.begin()+i);
                continue;
            }
            came1.push_back(cityy[i]);
        }
        came=InsertionSort(came1);
    }
    node* getf=getCity(destination);
    cout<<"The length of the Shortest Distance to the destination, "<<destination<<", from "<<city<<" is: "<<getf->dist<<endl;
    return returning;
}
#endif
