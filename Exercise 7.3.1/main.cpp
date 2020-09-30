// Rewrite the example so that instead of ordering the array from low to high, it sorts the array in reverse order: high to low.
// This is easier than it may look. It¡¯s helpful, for the sake of clarity, if you rename the variable low as ¡°high.¡± Otherwise,
// you need to change only one statement; this statement does the comparison

#include <iostream>

#define MAX 10

using namespace std;

int a[MAX];

void swap_(int *p1, int *p2)
{
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

void sorter ( int n)
{
    int high = 0;

    for (int i = 0; i < n - 1; ++i )
    {
        high = i;

        for (int j = i + 1; j < n; ++j )
        {
            if ( a[j] > a[high]) // if i set the equality sigh to 'less than' it will sort from lowest highest
            {
                high = j;
            }
        }

        if ( high != i )
        {
            swap_(&a[ i ], &a[high]);
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
