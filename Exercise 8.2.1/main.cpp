// Rewrite Example 8.2 so that it accepts only integer input.
// (Hint: You will want to change all types directly affected, from double to int format, including constants.)

#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdlib>

using namespace std;

int get_number()
{
    char s[100];

    cin.getline(s, 100);

    if (s == 0)
    {
        return 0;
    }

    return atoi(s);
}

int main()
{
    int x;

    while (true)
    {
        cout << "\nEnter a number:";
        x = get_number();

        if (x == 0)
        {
            break;
        }

        cout << endl << "Square of " << x << " is " << sqrt(x);

        cout << endl;
    }

    return 0;
}
