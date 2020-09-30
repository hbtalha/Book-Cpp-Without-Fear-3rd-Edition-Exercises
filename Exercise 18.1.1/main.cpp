// Write a test to see how many times the default constructor and the copy constructor are called.
// (Hint: Insert statements that send output to cout; you can span multiple lines if needed, as long
// as the function definitions are syntactically correct.) Then, run the program with and without the reference arguments
// (const Point &) changed back to ordinary arguments (Point). How much more efficient is the former approach?

// - Not sure it is correct

#include <iostream>

using namespace std;

int constructor_call_times = 0;

class Point
{
    int x, y;

public:
    Point()
    {
        ++constructor_call_times;

        set(0,0);
    }

    Point(int new_x, int new_y)
    {
        set(new_x,new_y);
    }

    Point (const Point &src)
    {
        set(src.x, src.y);
    }

    Point add( Point &pt) const;
    Point sub( Point &pt) const;

    Point operator+( Point &pt) const
    {
        return add(pt);
    }

    Point operator-( Point &pt) const
    {
        return add(pt);
    }

    void set(int new_x, int new_y);

    int get_x()
    {
        return x;
    }

    int get_y()
    {
        return y;
    }

};

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

int main()
{
    Point point1{17,98};
    Point point2{26,27};
    Point point3{13,19};
    Point point4 = point1 + point2 + point3;

    cout << "Point4(" << point4.get_x() << "," <<point4.get_y() << ")" << endl;
    cout << endl << constructor_call_times << endl;

    return 0;
}

Point Point::add( Point &pt) const
{
    Point new_pt;

    new_pt.x = x + pt.x;
    new_pt.y = y + pt.y;

    return new_pt;
}

Point Point::sub( Point &pt) const
{
    Point new_pt;

    new_pt.x = x - pt.x;
    new_pt.y = y - pt.y;

    return new_pt;
}

