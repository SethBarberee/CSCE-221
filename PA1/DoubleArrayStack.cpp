#include <iostream>
#include "Timer.cpp"

class EmptyStackException{};

// push algorithm
// test if we are at max
// if we are, make new stack with double stack and double the length
// then move +1 and push the new element
// Runtime of O(n)
// Amortized time of push operation is O(1)
// O(n)/n

template <class Type>

class DoubleArrayStack {
    private:
        int max_size;
        Type* S;
        int t;
    public:
    DoubleArrayStack<Type>(int nums){
        max_size = nums;
        t = -1;
        S = new Type[nums];
    };
    ~DoubleArrayStack<Type>(void) {
        delete[] S;
    }

    int get_max_size(){return max_size;}

    bool isEmpty(){
        if(t < 0) {
            return true;
        }
        return false;
    }

    bool isFull(){
        if (max_size == t){ 
            return true;
        }
        else{
            return false;
        }
    }

    void resize(int new_size){
        Type* new_Array = new Type[new_size];
        for(int j = 0; j <= t; j++){
            new_Array[j] = S[j];
        }
        max_size = new_size;
        *S = *new_Array;
    }

    void push(Type e) {
        if(isFull()){
            // Should just call resize
            // TODO create new Stack with bigger size of size * 2
            int new_size = max_size * 2;
            resize(new_size);
            t++;
            S[t] = e;
        }
        else {
            // Push new object
            t++;
            S[t] = e;
        }
    }

    Type pop(){
        if(isEmpty()){
            throw EmptyStackException();
        }
        return S[t--];
    }

    void print_stack(){
        for(int i = 0; i <= t; i++){
            std::cout << S[i] << "\n";
        }
    }

};

int main(){
    Timer Timer_program = Timer();
    Timer_program.start();
    DoubleArrayStack<int>* newStack = new DoubleArrayStack<int>(5);
    for(int i = 0; i < 50000; i++){
        newStack->push(i);
    }
    Timer_program.stop();

    std::cout << "Time taken was " << Timer_program.ms() << " ms" << "\n";
}

