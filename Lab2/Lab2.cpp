#include "std_lib_facilities_4.h"


template<typename T, int n> 
class Point {
    private:
    T dims[n];
    public:
    Point(T arr[n]) {
        for (int counter = 0; counter < n; counter++){
            dims[counter] = arr[counter];
        }
    }
    T distance(Point<T,n> second){
        T total = 0;
        for (int counter = 0; counter < n; counter++){
            total = total + pow((dims[counter] - second.dims[counter]),2);
        }
        return sqrt(total);
    }

};

int main(){
    double array_1[] = {1.0, 2.0, 3.0};
    double array_2[] = {1.1, 2.1, 3.1};
    int array_3[] = {1,2};
    int array_4[] = {2,3};
    Point<double, 3> a(array_1);
    Point<double, 3> b(array_2);
    cout << a.distance(b) << endl;

    Point<int, 2> c(array_3);
    Point<int, 2> d(array_4);
    cout << c.distance(d) << endl;
}
