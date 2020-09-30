// Write a program that calculates triangle numbers by using a recursive function.
// A triangle number is the sum of all whole numbers from 1 to n, in which n is the number specified. For example, triangle(5) = 5 + 4 + 3 + 2 + 1.

#include <iostream>

using namespace std;

int triangle_number ( int n)
{
    for (int i = 1; i <= n; ++i)
    {
        if ( n == 1)
        {
            return 1;
        }
        else
        return (n + triangle_number(n - 1));
    }
}

int main()
{
    int n;

    cout << "Enter a number: ";
    cin >> n;

    cout << "\nThe triangle number of " << n << " is " << triangle_number(n) << endl;
    return 0;
}
