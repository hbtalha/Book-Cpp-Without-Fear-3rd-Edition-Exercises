// Write a program that defines and tests a factorial function. The factorial of a number is the product of all whole numbers from 1 to N.
// For example, the factorial of 5 is 1 * 2 * 3 * 4 * 5 = 120. (Hint: Use a for loop as described in Chapter 3.)

#include <iostream>

using namespace std;

int factorial ( int n)
{
    int fact = 1;
    for ( int i = 1; i <= n; ++i )
    {
        fact *= i;
    }

    return fact;
}

int fact( int n)
{
    if ( n == 1)
    {
        return 1;
    }
    else
        return n * fact(n - 1);
}

int main()
{
    int n;

    cout << "Enter a number: " ;
    cin >> n;

    cout << "\nThe factorial of "<< n << " is " << factorial(n) << endl;;
    return 0;
}
