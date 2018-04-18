#ifndef QUICK_H

template <class Type>
void partition(vector<Type> &b, Type partition_value, vector<Type> &L, vector<Type> &E, vector <Type> &G){
    //std::cout << "Partition is: " << partition_value << endl;
    while(b.size() > 0){
        if(b.at(0) == partition_value){
            E.push_back(b[0]);
            //std::cout << "E: Pushing " << b.at(0) << " to array" << endl;
            b.erase(b.begin());
        }
        else {
            if (b.at(0) > partition_value){
                G.push_back(b.at(0));
                //std::cout << "G: Pushing " << b.at(0) << " to array" << endl;
                b.erase(b.begin());
            }
            else {
                L.push_back(b.at(0));
                //std::cout << "L: Pushing " << b.at(0) << " to array" << endl;
                b.erase(b.begin());
            }
        }
    }
}
template <class Type>
void QuickSort(vector<Type> &a){
    // Make sure we sort vectors with elements
    if (a.size() > 0){
        vector<Type> L;
        vector<Type> E;
        vector<Type> G;
        Type partition_value = a.at(a.size()/2); // partition with the median
        // Partiton and separate
        partition(a,partition_value, L, E, G);
        // Sort Less than side
        QuickSort(L);
        // Sort Greater than side
        QuickSort(G);
        // Combine everything back together
        a.insert(a.end(), L.begin(), L.end());
        a.insert(a.end(), E.begin(), E.end());
        a.insert(a.end(), G.begin(), G.end());
    }
}
#define QUICK_H
#endif
