#ifndef MERGE_H
#define MERGE_H

template <class Type>
void merge(vector<Type> &result, vector<Type> &i, vector<Type> &j){
    // TOOD merge i and j into result
    int a = 0;
    int b = 0;
    int n = i.size() + j.size();
    while ((a+b) < n) {
        if ((i[a] <= j[b]) && (i[a] != 0 && j[b] != 0)){
            result[(a+b)] = i[a];
            a++;
        }
        else {
                if ((i[a] > j[b]) && (i[a] != 0 && j[b] != 0)) {
                    result[(a+b)] = j[b];
                    b++;
                }
                else {
                    if (i[a] == 0){
                        result[(a+b)] = j[b];
                        b++;
                    }
                    else {
                        result[(a+b)] = i[a];
                        a++;
                    }
                }
        }
    }
}

template <class Type>
void MergeSort(vector<Type> &a){
    if (a.size() > 1){
        // Split the vector into two
        typename std::vector<Type>::iterator middleItr(a.begin() + a.size() / 2);
        std::vector<Type> b = std::vector<Type>(a.begin(), middleItr);
        std::vector<Type> c = std::vector<Type>(middleItr, a.end());
        // MergeSort first half
        MergeSort(b);
        // MergeSort second half
        MergeSort(c);
        // concatenate two halves
        merge(a, b, c);
        std::cout << endl;
    }
}

#endif
