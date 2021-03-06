#ifndef SORTED_PQ_H
#define SORTED_PQ_H

#include <exception>
#include <list>
#include <iostream>
#include <iterator>

using namespace std;

/**
 * Note: in order to try to make things easier, the queue below will only have a single type of value
 * in it instead of a (key, value) pair.  You could still store a (key, value) pair, but you would
 * make a priority queue that stored an object with both the key/value in it and a comparison operator
 * that only compared the keys.
 */

template <class Type>
class SortedPQ
{
private:
	// data here
    std::list<Type> list_data;

public:
   SortedPQ(void){
        list_data = {};
   };

   // Performs an insertion of "n" items from dataArray into the priority queue
   // BONUS: perform a bottomup heap construction for the heap.  Compare the time it takes to perform a
   // bottom up construction to inserting n items in your experimental section of your report.
   SortedPQ ( Type *dataArray, int n ){
        for(int i = 0; i < n; i++){
            InsertItem(*dataArray[i]);
        } 
   };

   ~SortedPQ(void){};

   bool isEmpty(void){
        return list_data.empty();
   };

   int size(void){
        return list_data.size();
   };

   // inserts a piece of data into the priority queue
   void insertItem ( Type data ){
       // Insert the data and then sort the list
       typename list<Type>::iterator before = list_data.begin();
       typename list<Type>::iterator after = list_data.begin();
       int position = 0;
       std::advance(after,1);
       for(int i = 0 ; i < list_data.size(); i++){
           if(data > *before && data < *after){
             position = i; // we found the perfect spot for insertion
           }
           std::advance(before,1);
           std::advance(after,1);
       }
       after = list_data.begin(); // reset the pointer to the start of the list
       std::advance(after,position+1); // move pointer to the correct position for insertion
       list_data.insert(after, data);  // insert the element at the position
   };

   // removes and returns the minimum value in the queue
   // throws an exception if the queue is empty
   Type removeMin ( void ){
        if(!isEmpty()){
            // Get value and store it before we delete it
            Type value = list_data.front();
            list_data.pop_front();
            return value;
        }
        else {
            throw empty_queue_exception();
        }
   };

   // return the minimum value in the queue without removing it
   // throws an exception if the queue is empty
   Type minValue ( void ){
        if(!isEmpty()){
            return list_data.front();
        }
        else {
            throw empty_queue_exception();
        }
   };
};

#endif
