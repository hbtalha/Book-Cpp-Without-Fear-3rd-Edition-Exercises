// If you have a C++11 or later compiler, use individual member initialization (described a few sections earlier) to create a default value of 0 for both x and y.
// Then, write a default constructor that does nothing and a constructor that assigns a value to x but not to y.
// Finally, test the combinations. You should find that 0 is an effective default for x and y, but that one or both can be overridden in the constructors.

#include <iostream>

using namespace std;

class Point
{
    int x = 0, y = 0;

public:
    Point (){}

    Point(int nx, int ny)
    {
        //cout << endl << "Using constructor." << endl;

        set(nx, ny);
    }

    void set(int n, int d);
    int get_x ();
    int get_y ();
};

void Point::set(int n, int d)
{
    if(n < 0)
        n *= -1;

    if (d < 0)
        d *= -1;

    x = n;
    y = d;
}

int Point::get_x ()
{
    return x;
}

int Point::get_y()
{
    return y;
}

int main()
{
    Point a, b(2,5);

    cout << b.get_x();

    return 0;
}
