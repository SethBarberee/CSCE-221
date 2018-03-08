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
    
    int max_size;
    int num_nodes;
    Type* S;

public:
   HeapPQ(void){
        num_nodes = 0;
        max_size = 1;
        S = new Type[max_size];
   };

   // Performs an insertion of "n" items from dataArray into the priority queue
   // BONUS: perform a bottomup heap construction for the heap.  Compare the time it takes to perform a
   // bottom up construction to inserting n items in your experimental section of your report.
   HeapPQ ( Type *dataArray, int n );

   ~HeapPQ(void){
        delete[] S;
   };

    void resize(int new_size){
        Type* new_Array = new Type[new_size];
        for(int i = 0; i <= num_nodes; i++){
            new_Array[i] = S[i];
        }
        max_size = new_size;
        delete[] S;
        S = new_Array;
    }

   bool isEmpty(void){
        return (num_nodes < 0);
   };

   int size(void){
        return num_nodes;
   };

   // inserts a piece of data into the priority queue
   void insertItem ( Type data ){
       // TODO: acutally insert into the array
        num_nodes++;
        if(num_nodes > max_size){
            std::cout << "Resizing to size of ";
            std::cout << max_size*2 << endl;
            resize(max_size*2);
        }
        S[num_nodes] = data;
   };

   // removes and returns the minimum value in the queue
   // throws an exception if the queue is empty
   Type removeMin ( void ){
       if(!isEmpty()){
            Type root = S[0];
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
            Type root = S[0];
            return root;
        }
        else {
            throw empty_queue_exception();
        }
   };
};

#endif
