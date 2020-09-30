// Write and test an expanded Point class that supports multiplication of a Point object by an integer.
// Use global functions, aided by friend declarations, as described in the previous section.

// - Couldn't solve a problem

#include <iostream>

using namespace std;

class Point
{

private:

    int x, y;

public:
    Point ()
    {
        set(0,0);
    }

    Point (int new_x, int new_y)
    {
        set(new_x, new_y);
    }

    Point(const Point &p)
    {
        set(p.x, p.y);
    }

    // Operations

    Point add(const Point &p) const;
    Point sub(const Point &p) const;
    Point operator+(const Point &p) {return add(p); };
    Point operator-(const Point &p) {return sub(p); }

     void set(int new_x, int new_y);

     int get_x()
     {
         return x;
     }

     int get_y()
     {
         return y;
     }

     friend Point operator*(int n, const Point &p);

};

int main()
{
    Point point1(17,98);
    Point point2(26,27);
    Point point3(13,19);
    Point point4= 3 * point2;
    Point p;

    cout << "Point4(" << point4.get_x() << "," <<point4.get_y() << ")" << endl;

    return 0;
}

void Point::set(int new_x, int new_y)
{
    if (new_x < 0)
    {
        new_x *= -1;
    }

    if (new_y < 0)
    {
        new_y *= -1;
    }

    x = new_x;
    y = new_y;
}

Point Point::add(const Point &p) const
{
    Point new_p;

    new_p.x = x + p.x;

    new_p.y = y + p.y;

    return new_p;
}

Point Point::sub(const Point &p) const
{
    Point new_p;

    new_p.x = x - p.x;

    new_p.y = y - p.y;

    return new_p;
}

 Point Point::operator*(int n, const Point &p)
{
    Point new_p;

    new_p.x = n * x;
    new_p.y = n * y;

    return new_p;
}




































