// Alter the example so that it can work with any number of values, simply by changing one setting in the program.
// You can do this with a #define directive near the beginning of the code.
// This directive instructs the compiler to replace all occurrences of a symbolic name (in this case, VALUES) with the specified text.

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

    cout << "Enter a number: ";
    cin >> n;

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

    cout <<  endl;

    return 0;
}
