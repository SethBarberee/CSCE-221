#include "HeapPQ.h"
#include "Bubble.h"
#include "Merge.h"
#include "Quick.h"
#include <iostream>
#include <fstream>

int main(){

    // import a file named numbers.txt
    // First number will be which sort to use
    // 1 = Bubble Sort
    // 2 = Heap Sort
    // 3 = Merge Sort
    // 4 = Quick Sort
    //
    // Second number is the number of numbers to insert
    // TODO for overkill move importing into vector at start (will require changing HeapSort

    ifstream ist {"numbers.txt"};
    int sort_type, amount, number;
    int count = 0;

    if(!ist) {
        std::cout << "Can't open input file!";
        return 1;
    }
    ist >> sort_type >> amount;
    std::cout << "Sort is of type: " << sort_type << " and amount: " << amount << endl;
    switch(sort_type){
        case 1: {
                    std::cout << "Bubble Sort" << endl;
                    vector<int> vec;
                    while(count < amount){
                        ist >> number;
                        // Insert into vector
                        vec.push_back(number);
                        count++;
                    }

                    // Call BubbleSort with vector
                    BubbleSort(vec);

                    for(int j = 0; j < vec.size(); j++){
                        std::cout << vec[j] << endl;
                    }

                    break;
                }
        case 2: {
                    std::cout << "Heap Sort" << endl; 
                    HeapPQ<int> Heap;
                    while(count < amount){
                        ist >> number;
                        Heap.insertItem(number);
                        count++;
                    }

                    while(!Heap.isEmpty()){
                        std::cout << Heap.removeMin() << endl;
                    }

                    break;
                }
        case 3: {
                    std::cout << "Merge Sort" << endl;
                    vector<int> vec;
                    while(count < amount){
                        ist >> number;
                        // Insert into vector
                        vec.push_back(number);
                        count++;
                    }

                    MergeSort(vec);

                    for(int j = 0; j < vec.size(); j++){
                        std::cout << vec[j] << endl;
                    }

                    break;
                }
        case 4: {
                    std::cout << "Quick Sort" << endl;
                    vector<int> vec;
                    while(count < amount){
                        ist >> number;
                        // Insert into vector
                        vec.push_back(number);
                        count++;
                    }
                        
                    QuickSort(vec);

                    for(int j = 0; j < vec.size(); j++){
                        std::cout << vec[j] << endl;
                    }

                    break;
                }
    }
}
