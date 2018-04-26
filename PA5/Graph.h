#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <iostream>
#include "LocatorHeap.h"
using namespace std;

class Edge;

class Vertex
{
public:
	int data;
	bool marked;
	vector<Edge *> edges;
	float d;
	Vertex *parent;
	Heap<Vertex>::Locator locator;

	Vertex ( int newData ) : data ( newData ) { }

	bool operator < ( const Vertex &v ) const 
	{ 
        // check weight of the edges
        if(this->d < v.d){
            return true;
        }
        else {
            return false;
        }

	}
};

class Edge
{
public:
	Vertex *v1, *v2;
	float weight;

	Edge ( Vertex *nv1, Vertex *nv2, float newWeight ) : v1 ( nv1 ), v2 ( nv2 ), weight ( newWeight ) { }
};

// you should implement the adjacency list data structure
class Graph
{
protected:
	vector<Vertex *> verts;
	vector<Edge *> edges;

public:
	Graph ( void ) { }

	~Graph ( void )
	{
		// implement me
	}

	Vertex *insertVertex ( int data )
	{
        // create the vertex
        Vertex *vert1 = new Vertex(data);
        verts.push_back(vert1);
        std::cout << "Inserting vertex" << endl;
	}

	void insertEdge ( Vertex *v, Vertex *w, float weight )
	{
        // create the edge
        Edge *edge1 = new Edge(v, w, weight);
        edges.push_back(edge1);
        std::cout << "Inserting edge" << endl;
	}

	vector<Vertex *> shortestPath ( Vertex *start, Vertex *goal )
	{
		// implement me
        vector<Vertex *> path;
        float distance = 0.0;
	}
};

#endif
