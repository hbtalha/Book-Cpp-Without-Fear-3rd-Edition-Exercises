// Revise the example so that it creates an array of seven Point objects.
// Set up a loop that prompts for values for each of the seven objects and another loop to print out all the values.
// (Hint: you can use a class name to declare an array, just as you can with any other type.)

#include <iostream>

using namespace std;

class Point
{
    int x;

public:
    void set_x(int new_x);
    int get_x();
};

void Point::set_x(int new_x)
{
    x = new_x;
}

int Point::get_x()
{
    return x;
}

int main()
{
    Point arr[7];

    for (int i = 0; i < 7; ++i)
    {
        int n;

        cout << "Enter number" << i + 1 << ": ";
        cin >> n;

        arr[i].set_x(n);
    }

    cout << endl;

     for (int i = 0; i < 7; ++i)
     {
         cout << "Number" << i + 1 << ": " << arr[i].get_x() << endl;
     }

    return 0;
}
