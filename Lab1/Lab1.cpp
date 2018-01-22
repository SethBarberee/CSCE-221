#include "std_lib_facilities_4.h"

struct Point {
    int x,y;
    Point(int x, int y);
    Point& operator= (Point& a){
        x = a.x;
        y = a.y;
    }
};

Point :: Point(int x1, int y1) : x(x1), y(y1) {}

class Shape {
    protected:
    Point location;
    virtual void Print() = 0;
    int get_x(){return location.x;}
    int get_y(){return location.y;}

    public:
    Shape(int x, int y);
};

Shape :: Shape(int x1, int y1) : location(x1,y1){}

class Circle : public Shape {
    private:
    double radius;
    public:
    double get_radius(){return radius;}
    void Print(){
        cout << "Circle at position " << get_x() << "," << get_y() << " with radius " << get_radius() << endl;
    }
    Circle(int x, int y, double radius);
};

Circle :: Circle(int x1, int y1, double rad) : Shape(x1, y1), radius(rad){}

class Square : public Shape {
    private:
    double side_length;
    public:
    double get_side_length(){return side_length;}
    void Print(){
        cout << "Square at position " << get_x() << "," << get_y() << " with side length " << get_side_length() << endl;
    }
    Square(int x, int y, double radius);
};

Square :: Square(int x1, int y1, double side) : Shape(x1, y1), side_length(side){}

int main() {
    Circle* circle = new Circle(1,2,3.1);
    circle->Print();
    Square* square = new Square(2,3,4.1);
    square->Print();
}
