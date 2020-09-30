// Rewrite the code in main so that it uses a loop similar to the one in Example 5.2 (page 106),
// allowing the user to keep rerunning sessions any number of times until he or she enters 0 to terminate the program.
// Before each session, you need to reinitialize all the elements of the hits array to 0.
// You can do that either by including a for loop that sets each element to 0 or by calling a function that contains such a loop.

#include <iostream>
#include <ctime>
#include <cstdlib>

#define VALUES 10

using namespace std;

int hits[VALUES];

int random( int n )
{
    return rand() % n;
}

int main()
{
    int n = 0;

    while (true)
    {
        cout << "\nEnter a number (0 to exit): ";
        cin >> n;

        if ( n == 0)
            break;

        for (int i = 0; i < n; ++i )
        {
            int r = random(VALUES);

            ++hits[r];
        }


        for (int i = 0; i < VALUES; ++i)
        {
            cout << i << ": " << hits[i] << " Accuracy: ";

            double results = hits[i];

            cout << results / (n / 10.0) << endl;

        }

        for ( int i = 0; i < VALUES; ++i )
        {
            hits[i] = 0;
        }

        cout <<  endl;
    }

    cout <<  endl;

    return 0;
}

