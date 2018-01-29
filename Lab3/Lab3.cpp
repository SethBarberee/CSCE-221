#include "std_lib_facilities_4.h"

class Point {
    private:
        int x,y;
    public:
        void print(){
            cout << "X: " << x << " " << "Y: " << y << endl;
        }
        Point(int x, int y);
        Point();
        ~Point(){
            cout << "Point deleted" << endl;
        }
};

Point :: Point(int x1, int y1) : x(x1), y(y1){}
Point :: Point() : x(1), y(2){}

int main(){
    // Stack
    Point points[] = {Point(1,1), Point(2,1), Point(3,4), Point(4,5), Point(6,7), Point(4,8), Point(3,5), Point(10,3), Point(1,2)}; // declared on the stack
    for (auto x : points){
        x.print();
    }
    // Heap
    int num = 10; // size of the point array to make
    Point *ps = new Point[num]; // declared on the heap
    for (int i = 0; i < num; i++){
        ps[i].print();
    }
    delete[] ps; // memory collection

}
