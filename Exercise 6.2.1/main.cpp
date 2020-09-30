// Instead of declaring and defining the variable r at the beginning of the function, declare it inside the loop that uses it.
// With this approach, r does not need to be initialized to 0 because you can assign a meaningful value directly.
// (This saves only a small amount of code, but it does make sense.)

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

 int hits[10];

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
        int r = random(10);

        ++hits[r];
    }


    for (int i = 0; i < 10; ++i)
    {
        cout << i << ": " << hits[i] << " Accuracy: ";

        double results = hits[i];

        cout << results / (n / 10.0) << endl;

    }

    cout <<  endl;

    return 0;
}
