#ifndef HEAP_PQ_H
#define HEAP_PQ_H

#include <exception>

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

public:
   HeapPQ(void);

   // Performs an insertion of "n" items from dataArray into the priority queue
   // BONUS: perform a bottomup heap construction for the heap.  Compare the time it takes to perform a
   // bottom up construction to inserting n items in your experimental section of your report.
   HeapPQ ( Type *dataArray, int n );

   ~HeapPQ(void);

   bool isEmpty(void);

   int size(void);

   // inserts a piece of data into the priority queue
   void insertItem ( Type data );

   // removes and returns the minimum value in the queue
   // throws an exception if the queue is empty
   Type removeMin ( void );

   // return the minimum value in the queue without removing it
   // throws an exception if the queue is empty
   Type minValue ( void );
};

#endif
