#ifndef UNSORTED_PQ_H
#define UNSORTED_PQ_H

#include <exception>
#include <list>
#include <iostream>
#include <iterator>

using namespace std;

class empty_queue_exception{};

/**
 * Note: in order to try to make things easier, the queue below will only have a single type of value
 * in it instead of a (key, value) pair.  You could still store a (key, value) pair, but you would
 * make a priority queue that stored an object with both the key/value in it and a comparison operator
 * that only compared the keys.
 */

template <class Type>
class UnsortedPQ
{
private:
	// data here
    std::list<Type> list_data;

public:
   UnsortedPQ(void){
        list_data = {};
   };

   // Performs an insertion of "n" items from dataArray into the priority queue
   // BONUS: perform a bottomup heap construction for the heap.  Compare the time it takes to perform a
   // bottom up construction to inserting n items in your experimental section of your report.
   UnsortedPQ ( Type *dataArray, int n ){
        for(int i = 0; i < n; i++){
            InsertItem(*dataArray[i]);
        } 
   };

   ~UnsortedPQ(void){};

   bool isEmpty(void){
        return list_data.empty();
   };

   int size(void){
        return list_data.size();
   };

   // inserts a piece of data into the priority queue
   void insertItem ( Type data ){
       list_data.push_back(data); 
   };

   // removes and returns the minimum value in the queue
   // throws an exception if the queue is empty
   Type removeMin ( void ){
       Type min = *(list_data.begin());
       int position = 0;
       typename list<Type>::iterator ptr;
       ptr = list_data.begin();
       if(!isEmpty()){
            for(int i = 0; i < list_data.size(); i++){
                if (*ptr < min){
                    min = *ptr;
                    position = i;
                }
                std::advance(ptr,1);
            }
            ptr = list_data.begin();
            std::advance(ptr,position);
            list_data.erase(ptr);
            return min;
       }
       else {
            throw empty_queue_exception();
       }
   };

   // return the minimum value in the queue without removing it
   // throws an exception if the queue is empty
   Type minValue ( void ){
       Type min = *(list_data.begin());
       typename list<Type>::iterator ptr;
       ptr = list_data.begin();
       if(!isEmpty()){
            for(int i = 0; i < list_data.size(); i++){
                if (*ptr < min){
                    min = *ptr;
                }
                std::advance(ptr,1);
            }
            return min;
       }
       else {
            throw empty_queue_exception();
       }
   };
};

#endif
