#include "Stack.h"

// push algorithm
// test if we are at max
// if we are, make new stack with double stack and double the length
// then move +1 and push the new element
// Runtime of O(n)
// Amortized time of push operation is O(1)
// O(n)/n

template <class Type>

class DoubleArrayStack : public AbstractStack<Type> {
    DoubleArrayStack(int nums){AbstractStack<Type>(nums);}
    ~DoubleArrayStack(void) {~AbstractStack<Type>();}

    void push(Type e) {
        if(isFull()){
            // TODO create new Stack with bigger size of size * 2
            // DoubleArrayStack((size() * 2));
        }
        else {
            // Push new object
        }
    }
};

int main(){
    return 0;
}
