#include <iostream>
#include "Timer.cpp"

class EmptyStackException{};

// push algorithm
// test if we are at max size, if we are increase size by a constant factor
// then move +1, and push new element
// Runtime of O(n^2)
// Amortized time of push is O(n)
// O(n^2)/n
template <class Type>

class ArrayStack {
    private:
        int max_size;
        Type* S;
        int t;

    public:
    ArrayStack<Type>(int sz){
        max_size = sz;
        t = -1;
        S = new Type[sz];
    };

    ~ArrayStack<Type>(){
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
        if ((max_size-1) == t){ 
            return true;
        }
        else{
            return false;
        };
    }

    void resize(int new_size){
        Type* new_Array = new Type[new_size];
        for(int i = 0; i <= t; i++){
            new_Array[i] = S[i];
        }
        max_size = new_size;
        delete[] S;
        S = new_Array;
    }

    void push(Type e) {
        if(isFull()){
            // Should just call resize
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
    ArrayStack<int>* newStack = new ArrayStack<int>(5);
    for(int i = 0; i < 100000; i++){
        newStack->push(i);
    }
    Timer_program.stop();

    std::cout << "Time taken was " << Timer_program.ms() << " ms" << "\n";
}
