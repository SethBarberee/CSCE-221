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
	float d = 0;
	Vertex *parent;
	Heap<Vertex>::Locator locator;

	Vertex ( int newData ) : data ( newData ) { }

	bool operator < ( const Vertex &v ) const 
	{ 
        if (this->d < v.d){
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
        // loop through verts and edges and delete pointers
        for(int i = 0; i < verts.size(); i++){
            delete[] verts[i];
        }
        for(int j = 0; j < edges.size(); j++){
            delete[] edges[j];
        }
	}

	Vertex *insertVertex ( int data )
	{
        // check if vertex exists
        bool vert_exists = false;
        for(int i = 0; i < verts.size(); i++){
            if (data == verts[i]->data){
                vert_exists = true;
                return verts[i]; // since it exists, return the existing
            }
        }
        // If it doesn't exist, create it
        if (!vert_exists){
            Vertex *vert1 = new Vertex(data);
            verts.push_back(vert1);
            return vert1; // return the new one
        }
	}

	void insertEdge ( Vertex *v, Vertex *w, float weight )
	{
        // create the edge
        Edge *edge1 = new Edge(v, w, weight);
        edges.push_back(edge1);
	}

	vector<Vertex *> shortestPath ( Vertex *start, Vertex *goal )
	{
		// implement me
        vector<Vertex *> path;
        Vertex *current = start;
        
        path.push_back(start); // we start with the start

        // find the shortest distance for each one
        // add it to the path vector
        for(int i = 0; i < edges.size(); i++){
            Heap<Vertex> vertex_heap;
            if(edges[i]->v1 == current){
                // Check those paths
                // TODO it still picks the first one
                // Update d with weight of edge
                if(edges[i]->v2->d < (edges[i]->weight + edges[i]->v1->d)){
                    edges[i]->v2->d = edges[i]->v1->d + edges[i]->weight;
                }
                edges[i]->v2->locator = vertex_heap.insertElement(edges[i]->v2);
                vertex_heap.update(edges[i]->v2->locator);
                Vertex *next_current = vertex_heap.removeMin();
                current = next_current;
                path.push_back(current);
            }
        }
        return path;
    }
};

#endif
