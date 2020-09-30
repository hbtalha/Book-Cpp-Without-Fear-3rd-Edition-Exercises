//Can you revise the example so that it uses a while loop, but does not use either the do or break keyword?
//Note that the result should produce exactly the same behavior under all conditions that Example 3.1 does.

#include <iostream>

using namespace std;

int main()
{
    int n = 0, sum = 0, t = 1;
    bool exit;

     while ( !exit )
    {
        cout << " Enter a number (0 to exit):";
        cin >> n;


        sum += n;

        if ( n == 0)
        {
            cout << "\nSum is " << sum << endl;
            exit = true;
        }

        if (!exit)
         cout << "                            +" << endl;
    }
    /*
    while ( t > 0 )
    {
        cout << " Enter a number (0 to exit):";
        cin >> n;

        sum += n;

        t = n;

    }
    cout << "\nSum is " << sum << endl;
    */

    return 0;
}
