#include "Graph.h"
#include "LocatorHeap.h"
#include <iostream>
#include <fstream>

int main() {
    Graph *Graph1 = new Graph();
    ifstream ist {"rand200.txt"};
    int num_vert, num_edges, start, end, distance;

    if(!ist){
        std::cout << "Can't open input file!";
        return 1;
    }
    ist >> num_vert >> num_edges;
    for(int i = 0; i < num_edges; i++){
        int vert1, vert2;
        float weight;
        ist >> vert1 >> vert2 >> weight;
        Vertex *Vertex1 = Graph1->insertVertex(vert1);
        Vertex *Vertex2 = Graph1->insertVertex(vert2);
        Graph1->insertEdge(Vertex1, Vertex2, weight);
    }
    // Now to find the shortest path
    ist >> start >> end;
    std::cout << "Start at " << start << endl;
    std::cout << "End at " << end << endl;
    Vertex *Start = Graph1->insertVertex(start);
    Vertex *End = Graph1->insertVertex(end);
    vector<Vertex *> Path = Graph1->shortestPath(Start, End);
    std::cout << "Path is: ";
    for(int j = 0; j < Path.size(); j++){
        cout << Path[j]->data << " ";
    }
    std::cout << endl;
}
