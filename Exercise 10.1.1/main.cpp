// Revise the set function so that it establishes an upper limit of 100 for values of x and y; if a value greater than 100 is entered, it is reduced to 100.
// Revise main to test this behavior.

#include <iostream>

using namespace std;

class Point
{
    int x, y;

public:
    void set_values();
    int get_x();
    int get_y();
};

void Point::set_values()
{
    x = new_x;
    y = new_y;
}

int Point::get_x()
{
    return x;
}

int Point::get_y()
{
    return y;
}

int main()
{
    Point p;
    int x, y;

    cout << "Enter x: ";
    cin >> x;

    cout << "Enter y: ";
    cin >> y;

    if (x > 100)
    {
        x = 100;
    }

    if (y > 100)
    {
        y = 100;
    }

    p.set_values(x, y);

    cout << "\nx = " << p.get_x() << " \ny = " << p.get_y() << endl;

    return 0;
}
