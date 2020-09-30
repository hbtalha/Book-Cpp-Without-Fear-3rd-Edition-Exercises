// Add code to the two constructors of the Point class to report their use.
// The default constructor should print ¡°Using default constructor,¡±
// and the other should print ¡°Using (int, int) constructor.¡±
// (Tip: If you want to keep these functions inline, you can have the function definitions span multiple lines if you need to do so.)

#include <iostream>

using namespace std;

class Point
{
    int x, y;

public:
    Point ()
    {
        cout << endl << "Using default constructor." << endl;

        x = 0;
        y = 0;
    }

    Point(int nx, int ny)
    {
        cout << endl << "Using constructor." << endl;

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

    return 0;
}
