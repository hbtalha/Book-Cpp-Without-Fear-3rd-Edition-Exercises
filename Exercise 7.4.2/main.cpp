// Write and test a copy_array function that copies the contents of one int array to another array of the same size.
// The function should take two pointer arguments.

#include <iostream>

using namespace std;

int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int b[10];

void copy_array(int *p, int *c)
{
    while (p < a + 10)
    {
        *c++ = *p++;
    }
}

int main()
{
    cout << "Array a:" << endl;
    for (int i = 0; i < 10; ++i)
    {
        cout << a[i] << "  ";
    }

    copy_array(a, b);

    cout << endl << endl << "Array b:" << endl;
    for (int i = 0; i < 10; ++i)
    {
        cout << a[i] << "  ";
    }

    cout << endl;

    return 0;
}
