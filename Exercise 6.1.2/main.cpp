// Write a program that initializes an array of six integers with the values 10, 22, 13, 99, 4, and 5.
// Print each of these out and then print their sum. (Hint: You¡¯ll need to keep a running total.)

#include <iostream>

using namespace std;

int main()
{
    int n[6] = {10, 22, 13, 99, 4, 5};

    int sum = 0;

    for (int i = 0; i < 6; ++i)
    {
        cout << n[i];

        if(i < 5)
            cout  << " + ";

        sum += n[i];
    }

    cout << endl << endl << "Sum = " << sum << endl;

    return 0;
}
