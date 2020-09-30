// Rewrite the program to use a direct-pointer reference for the loop that prints out the values of the array.
// Declare a pointer p and initialize it to start the array. The loop condition should be p < a + 10.

#include <iostream>

using namespace std;

int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

void zero_out_array(int *p)
{
    while (p < a + 10)
    {
        *p++ = 0;
    }
}

int main()
{
    for (int i = 0; i < 10; ++i)
    {
        cout << a[i] << "  ";
    }

    zero_out_array(a);

    cout << endl;

    for (int i = 0; i < 10; ++i)
    {
        cout << a[i] << "  ";
    }

    return 0;
}
