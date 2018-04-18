#include "Bubble.h"
#include "HeapPQ.h"
#include "Merge.h"
#include "Quick.h"
#include <iostream>
#include "Timer.cpp"

#define MAX_ELEMENTS 1000

int main() {
    Timer time_test = Timer();
    HeapPQ<int> Heap;
    vector<int> vec;
    srand(time(NULL)); // seed the random number generator
   
    for(int i = 0; i < MAX_ELEMENTS; i++){
        vec.push_back(rand()%10); 
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

    for(int k = 0; k < MAX_ELEMENTS; k++){
        // HeapPQ
        Heap.insertItem(rand()%10); // Generate random number between 0-9
    }
    time_test.start();
    for(int c = 0; c < MAX_ELEMENTS; c++){
        Heap.removeMin();
    }
    time_test.stop();
    std::cout << "Time taken for Heap: " << time_test.ms() << " ms" << endl;

}
