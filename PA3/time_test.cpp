#include "UnsortedPQ.h"
#include "SortedPQ.h"
#include "HeapPQ.h"
#include <iostream>
#include "Timer.cpp"

#define MAX_ELEMENTS 10000

int main() {
    Timer time_test = Timer();
    UnsortedPQ<int> Unsort;
    SortedPQ<int> Sort;
    HeapPQ<int> Heap;
    srand(time(NULL)); // seed the random number generator
    
    time_test.start();
    for(int i = 0; i < MAX_ELEMENTS; i++){
        // UnsortedPQ
        Unsort.insertItem(rand()%10); // Generate random number between 0-9
    }
    for(int a = 0; a < MAX_ELEMENTS; a++){
        Unsort.removeMin();
    }
    time_test.stop();
    std::cout << "Time take for Unsorted: " << time_test.ms() << " ms" << endl;
    
    time_test.start();
    for(int j = 0; j < MAX_ELEMENTS; j++){
        // SortedPQ
        Sort.insertItem(rand()%10); // Generate random number between 0-9
    }
    for(int b = 0; b < MAX_ELEMENTS; b++){
        Sort.removeMin();
    }
    time_test.stop();
    std::cout << "Time taken for Sorted: " << time_test.ms() << " ms" << endl;

    time_test.start();
    for(int k = 0; k < MAX_ELEMENTS; k++){
        // HeapPQ
        Heap.insertItem(rand()%10); // Generate random number between 0-9
    }
    for(int c = 0; c < MAX_ELEMENTS; c++){
        Heap.removeMin();
    }
    time_test.stop();
    std::cout << "Time taken for Heap: " << time_test.ms() << " ms" << endl;

}
