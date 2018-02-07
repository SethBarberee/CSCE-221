#include "Stack.h"

// push algorithm
// test if we are at max size, if we are increase size by a constant factor
// then move +1, and push new element
// Runtime of O(n^2)
// Amortized time of push is O(n)
// O(n^2)/n
template <class Type>

class ArrayStack : public AbstractStack<Type> {
    ArrayStack(int nums){
        AbstractStack<Type>(int num);
    };
    ~ArrayStack(void) {~AbstractStack<Type>();}

    void push(Type e) {
        //if(isFull()){
            // TODO create new Stack with bigger size of size + C (some constant)
        //}
        //else {
        //    // Push new object
        //}
    }
};

int main(){
    return 0;
}
