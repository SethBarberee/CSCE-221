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
	bool marked = false;
	vector<Edge *> edges;
	float d = 999999999999999;
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
        v->edges.push_back(edge1);
        w->edges.push_back(edge1);
	}

	vector<Vertex *> shortestPath ( Vertex *start, Vertex *goal )
	{
		// implement me
        vector<Vertex *> path;
        Vertex *current = start;
        Vertex *next_current;
        Heap<Vertex> vertex_heap;
        vertex_heap.insertElement(start);
        
        current->d = 0;

        // find the shortest distance for each one
        // add it to the path vector
        while((current != goal) && !(vertex_heap.isEmpty())){
            current = vertex_heap.removeMin();
            path.push_back(current);
            std::cout << "Current is at: " << current->data << endl;
            for(int i = 0; i < current->edges.size(); i++){
                if(current->edges[i]->v1 == current){
                // Check those paths
                // Update d with weight of edge
                    if(current->edges[i]->v2->d > (current->edges[i]->weight + current->edges[i]->v1->d)){
                        current->edges[i]->v2->d = current->edges[i]->v1->d + current->edges[i]->weight;
                        current->edges[i]->v2->locator = vertex_heap.insertElement(current->edges[i]->v2);
                    }
                }
                else if (current->edges[i]->v2 == current){
                    if(current->edges[i]->v1->d > (current->edges[i]->weight + current->edges[i]->v2->d)){
                        current->edges[i]->v1->d = current->edges[i]->v2->d + current->edges[i]->weight;
                        current->edges[i]->v1->locator = vertex_heap.insertElement(current->edges[i]->v1);
                    }
                }
            }
        }
        return path;
    }
};

#endif
