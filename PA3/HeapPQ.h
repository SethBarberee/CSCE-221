#ifndef HEAP_PQ_H
#define HEAP_PQ_H

#include <exception>
#include <iostream>

using namespace std;

/**
 * Note: in order to try to make things easier, the queue below will only have a single type of value
 * in it instead of a (key, value) pair.  You could still store a (key, value) pair, but you would
 * make a priority queue that stored an object with both the key/value in it and a comparison operator
 * that only compared the keys.
 */

template <class Type>
class HeapPQ
{
private:
	// data here
    // Treat like a tree and put it into an array
    // need to be resizable (kinda like PA1)
    // root is the first index
    
    int num_nodes;
    vector<Type> S;

public:
   HeapPQ(void){
        S = vector<Type>(0);
   };

   // Performs an insertion of "n" items from dataArray into the priority queue
   // BONUS: perform a bottomup heap construction for the heap.  Compare the time it takes to perform a
   // bottom up construction to inserting n items in your experimental section of your report.
   HeapPQ ( Type *dataArray, int n );

   ~HeapPQ(void){};

   void reheap(int i){
       // TODO: Fix the recursion to go to the root of the tree
        if(S.size() > 2){
            Type node = S.at(i);
            int parent_location = (i-1)/2;
            Type parent = S.at(parent_location);
            if(node < parent){
                std::cout << "Switching" << endl;
                Type temp = node;
                node = parent;
                parent = temp;
            }
        }
    };

   bool isEmpty(void){
        return (S.size()< 0);
   };

   int size(void){
        return S.size();
   };

   // inserts a piece of data into the priority queue
   void insertItem ( Type data ){
       // TODO: acutally insert into the array
       S.push_back(data);
       reheap(S.size()-1);
   };

   // removes and returns the minimum value in the queue
   // throws an exception if the queue is empty
   Type removeMin ( void ){
       if(!isEmpty()){
            Type root = S.at(0);
            // TODO: Delete root and re-heap
            return root;
       }
       else {
            throw empty_queue_exception();
       }
   };

   // return the minimum value in the queue without removing it
   // throws an exception if the queue is empty
   Type minValue ( void ){
        if(!isEmpty()){
            Type root = S.at(0);
            return root;
        }
        else {
            throw empty_queue_exception();
        }
   };
};

#endif
