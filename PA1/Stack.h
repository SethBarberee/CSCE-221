#ifndef ABSTRACT_STACK_H
#define ABSTRACT_STACK_H

class EmptyStackException{};

template <class Type>
class AbstractStack
{
private:
    // data goes here
    int max_size; // stack capacity
    Type *S; // Stack array
    int t; // top of stack

public:
   AbstractStack(int nums) {
       max_size = nums;
       S = new Type[max_size];
       t = -1;
   }

   ~AbstractStack(void) { delete[] S; }

   bool isEmpty(void) { return t < 0; }

   bool isFull(void) { return t==max_size; }

   int size(void) {return t;}

   Type top() { return S[t]; }

   Type pop() {
       if(isEmpty())
           throw EmptyStackException();
       return S[t--];
   }
   
   virtual void push ( Type e ) = 0;

};

#endif
