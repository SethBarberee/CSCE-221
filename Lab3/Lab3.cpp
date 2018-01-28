#include "std_lib_facilities_4.h"

class Point {
    private:
        int x,y;
    public:
        void print(){
            cout << "X: " << x << endl << "Y: " << y << endl;
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
    Point a = Point(1,1);
    Point b = Point(2,1);
    Point c = Point(3,4);
    Point d = Point(4,5);
    Point e = Point(6,7);
    Point f = Point(4,8);
    Point g = Point(3,5);
    Point h = Point(10,3);
    Point i = Point(1,2);
    Point points[] = {a, b, c, d, e, f, g, h, i}; // declared on the stack
    for (auto x : points){
        x.print();
    }
    Point *ps = new Point[10]; // declared on the heap
    // TODO: Iterate through array and then print
    //for (Point* x : *ps){
    //    x->print();
    //}
}
