#ifndef DEQUE_H
#define DEQUE_H

#include <exception>

using namespace std;

template <class Type>
class Deque
{
private:
	// data here
    Type* head;
    Type* tail;
    int count;

public:
   Deque(void){
        head = nullptr;
        tail = nullptr;
        count = 0;
   };

   ~Deque(void);

   bool isEmpty(void){
        if(count < 1){
            return true;
        }
        else{
            return false;
        }
   };

   int size(void){
        return count;
   };

   Type first(void) throw(exception){
        return *head;
   };

   Type last(void) throw(exception){
        return *tail;
   };

   void insertFirst(Type o);

   void insertLast(Type o);

   Type removeFirst(void) throw(exception);

   Type removeLast(void) throw(exception);
};

#endif
