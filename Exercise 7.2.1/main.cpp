// Write a program to call a function triple_it that takes the address of an int and triples the value pointed to.
// Test it by passing an argument n, which is initialized to 15. Print out the value of n before and after the function is called.
// (Hint: The function should look similar to double_it in Example 7.1. Remember to pass &n.)

#include <iostream>

using namespace std;

int triple_it( int *n)
{
    return *n = *n * 3;
}

int main()
{
    int n = 15;

    cout << "n before the function is called: " << n;

    triple_it(&n) ;

    cout << endl << endl << "n after the function is called: " << n << endl;

    triple_it(&n);

    cout << endl << "n after the function is called: " << n << endl;

    return 0;
}
