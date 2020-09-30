#include <iostream>

#define MAX 5

using namespace std;

double a[MAX];

void swap_(double *p1,double *p2)
{
    double temp = *p1;
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
            if ( a[j] > a[high]) // if i set the equality sigh to 'less than' it will sort from lowest to highest
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
