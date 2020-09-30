// Revise the example so it implements the bubble-sort algorithm, which is potentially faster than the selection-sort algorithm.
// Bubble sort compares each element to its neighbor and swaps if they are not in order.
// After this is done for the whole array, the highest value in the array “bubbles up” to the highest array position.
// After the whole array is processed, then the first n − 1 elements are processed, then the first n − 2 elements, and so on,
// each time putting the highest element remaining into the rightmost position.
// The advantage of the algorithm is that if the array is sorted at any point, it can quit early. Here is the pseudo-code for the bubble sort of Exercise 7.3.3:

#include <iostream>

#define MAX 5

using namespace std;

int a[MAX];

void swap_(int *p1,int *p2)
{
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

void sorter (int n)
{
    for (int i = n - 1; i > 0; --i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (a[ j+1 ] < a[ j ] )
            {
                swap_( &a[ j+1 ], &a[ j ] );
            }
        }
    }
}

int main()
{
    for (int i = 0; i < MAX; ++i)
    {
        cout << "Enter Number" <<i + 1 << ":";
        cin >> a[i];
    }

    sorter(MAX);

    cout << endl;

    for (int i = 0; i < MAX; ++i)
    {
        cout << a[i] << "  ";
    }

    cout << endl;

    return 0;
}
