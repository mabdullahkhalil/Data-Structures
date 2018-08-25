#ifndef GRAPH__CPP
#define GRAPH__CPP
#include "Graph.h"

bool operator == (edge a, edge b)
{
}

bool operator < (edge a, edge b)
{
}

bool operator > (edge a, edge b)
{
}
bool operator < (node a, node b)
{
}

bool operator > (node a, node b)
{
}
Graph::Graph(char* file)
{
}
node* Graph::getCity(string s)
{
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
}
vector<node*> Graph::Kruskal()
{
}
vector<string> Graph::Dijkstra(string city, string destination, float &d)
{
}
#endif
