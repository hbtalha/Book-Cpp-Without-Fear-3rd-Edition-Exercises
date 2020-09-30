// Alter Example 6.2 so that it generates not 10 different values but 5: In other words, use the rand_0toN1 function to get a 0, 1, 2, 3, or 4.
// Then perform the requested number of trials, in which you¡¯d expect each value of the five values to be produced one-fifth of the time.

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int hits[5];

int random( int n )
{
    return rand() % n;
}

int main()
{
    int n = 0;

    cout << "Enter a number: ";
    cin >> n;

    for (int i = 0; i < n; ++i )
    {
        int r = random(5);

        ++hits[r];
    }


    for (int i = 0; i < 5; ++i)
    {
        cout << i << ": " << hits[i] << " Accuracy: ";

        double results = hits[i];

        cout << results / (n / 10.0) << endl;

    }

    cout <<  endl;

    return 0;
}
