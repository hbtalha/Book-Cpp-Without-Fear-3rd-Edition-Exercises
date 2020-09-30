// Write an add function for the Point class introduced earlier.
// The function should add the x values to get the new value of x, and it should add the y values to get the new value of y.

#include <iostream>

using namespace std;

class Point
{
    int x, y;

public:
    void set(int x, int y) {this->x = x; this->y = y;}
    int get_x() {return x;}
    int get_y() {return y;}

    Point add(Point other);

};

Point Point::add(Point other)
{
    Point p;

    p.set(x + other.x, y + other.y);

    return p;
}

int main()
{
    Point p1, p2, p3;

    p1.set(3, 5);
    p2.set(6, 2);

    p3 = p1.add(p2);

    cout << "x = " << p3.get_x() <<  "  y = " << p3.get_y() << endl;

    return 0;
}
