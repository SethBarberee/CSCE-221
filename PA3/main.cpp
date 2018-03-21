#include "UnsortedPQ.h"
#include "SortedPQ.h"
#include "HeapPQ.h"
#include <iostream>
#include <fstream>

int main(){

    // import a file named numbers.txt
    // First number will be which queue to use
    // 0 = UnsortedPQ
    // 1 = SortedPQ
    // 2 = HeapPQ
    //
    // Second number is the number of numbers to insert

    ifstream ist {"numbers.txt"};
    int queue_type, amount, number, count;

    if(!ist) {
        std::cout << "Can't open input file!";
        return 1;
    }
    ist >> queue_type >> amount;
    std::cout << "Queue is of type: " << queue_type << " and amount: " << amount << endl;
    switch(queue_type){
        case 0: {
                    std::cout << "UnsortedPQ" << endl;
                    UnsortedPQ<int> Unsort;
                    while(count < amount){
                        ist >> number;
                        std::cout << "Inserted ";
                        std::cout << number << endl;
                        Unsort.insertItem(number);
                        count++;
                    }
                    std::cout << "Minimum: ";
                    std::cout << Unsort.minValue() << endl;
                    break;
                }
        case 1: {
                    std::cout << "SortedPQ" << endl;
                    SortedPQ<int> Sort;
                    while(count < amount){
                        ist >> number;
                        std::cout << "Inserted ";
                        std::cout << number << endl;
                        Sort.insertItem(number);
                        count++;
                    }
                    std::cout << "Minimum: ";
                    std::cout << Sort.minValue() << endl;
                    break;
                }
        case 2: {
                    std::cout << "HeapPQ" << endl; 
                    HeapPQ<int> Heap;
                    while(count < amount){
                        ist >> number;
                        std::cout << "Inserted ";
                        std::cout << number << endl;
                        Heap.insertItem(number);
                        count++;
                    }
                    std::cout << "Minimum: ";
                    std::cout << Heap.minValue() << endl;
                    break;
                }
    }
}
