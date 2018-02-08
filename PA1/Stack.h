#ifndef ABSTRACT_STACK_H
#define ABSTRACT_STACK_H

class EmptyStackException{};

template <class Type>
class AbstractStack
{
private:
    // data goes here

public:
   AbstractStack(int nums) {
       max_size = nums;
   }

   ~AbstractStack(void) { }

   bool isEmpty(void) {}

   bool isFull(void) {}

   int get_max_size(void) {return max_size;}

   int get_size(void) {}

   Type top() {}

   Type pop() {}


};

#endif
