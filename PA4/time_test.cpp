#include "Bubble.h"
#include "HeapPQ.h"
#include "Merge.h"
#include "Quick.h"
#include <iostream>
#include "Timer.cpp"

#define MAX_ELEMENTS 25000

int main() {
    Timer time_test = Timer();
    HeapPQ<int> Heap;
    vector<int> vec;
    srand(time(NULL)); // seed the random number generator
   
    // Random Input
    //for(int i = 0; i < MAX_ELEMENTS; i++){
    //    vec.push_back(rand()%10); 
    //}
    
    // Sorted Input
    //for(int j = 0; j < MAX_ELEMENTS; j++){
    //    vec.push_back(j);
    //}

    // Reverse Sorted Input
    for(int h = MAX_ELEMENTS; h > 0; h--){
        vec.push_back(h);
    }

    time_test.start();
    BubbleSort(vec);
    time_test.stop();
    std::cout << "Time take for Bubble: " << time_test.ms() << " ms" << endl;
    
    time_test.start();
    MergeSort(vec);
    time_test.stop();
    std::cout << "Time taken for Merge: " << time_test.ms() << " ms" << endl;

    time_test.start();
    QuickSort(vec);
    time_test.stop();
    std::cout << "Time taken for QuickSort: " << time_test.ms() << " ms" << endl;

    for(int k = MAX_ELEMENTS; k > 0; k--){
        // HeapPQ
        Heap.insertItem(k); // Generate random number between 0-9
    }
    time_test.start();
    for(int c = 0; c < MAX_ELEMENTS; c++){
        Heap.removeMin();
    }
    time_test.stop();
    std::cout << "Time taken for Heap: " << time_test.ms() << " ms" << endl;

}
