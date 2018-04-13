#ifndef BUBBLE_H
#define BUBBLE_H

#include <exception>
#include <vector>
#include <iostream>

using namespace std;

template <class Type>
void swap(Type *a, Type *b){
    Type temp = *a;
    *a = *b;
    *b = temp;
};

template <class Type>
void BubbleSort(vector<Type> &a){
    for(int i = 0; i < a.size() - 1; i++){
        for(int j = 0; j < a.size() - i - 1; j++){
            if(a.at(j) > a.at(j+1)){
                swap(&a[j] , &a[j+1]);
            }
        }
    }
};

#endif
