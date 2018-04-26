#include "Graph.h"
#include "LocatorHeap.h"
#include <iostream>
#include <fstream>

int main() {
    Graph *Graph1 = new Graph();
    ifstream ist {"graph.txt"};
    int num_vert, num_edges, start, end;

    if(!ist){
        std::cout << "Can't open input file!";
        return 1;
    }
    ist >> num_vert >> num_edges;
    std::cout << "Number of vertices: " << num_vert << " and number of edges: " << num_edges << endl;
    for(int i = 0; i < num_edges; i++){
        int vert1, vert2;
        float weight;
        ist >> vert1 >> vert2 >> weight;
        std::cout << "Vertex number: " << vert1 << " and " << vert2 << " with weight: " << weight << endl;
        Graph1->insertVertex(vert1);
        Graph1->insertVertex(vert2);
        Vertex *Vertex1 = new Vertex(vert1);
        Vertex *Vertex2 = new Vertex(vert2);
        Graph1->insertEdge(Vertex1, Vertex2, weight);
    }
    Vertex *Start = new Vertex(start);
    Vertex *End = new Vertex(end);
    //Graph1->shortestPath(Start, End);
}
