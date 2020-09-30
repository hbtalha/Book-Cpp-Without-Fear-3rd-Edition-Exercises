// Write a function named print_out that prints all the whole numbers from 1 to N.
// Test the function by placing it in a program that passes a number n to print_out, where this number is entered from the keyboard.
// The print_out function should have type void; it does not return a value.

#include <iostream>

using namespace std;

void print_out( int n)
{
    for (int i = 1; i <= n; ++i)
    {
        cout << i << " ";
    }
    cout << endl;
}

int main()
{
    int n;

    cout << "Enter a number: ";
    cin >> n;

    print_out(n);

    return 0;
}
