// Revise the program so that the user can enter any positive integer value for n. Ideally, you should test the input to see whether it is greater than 0.

#include <iostream>

using namespace std;

void move_a_ring(int scr, int dest)
{
    cout << "Move From " << scr << " To " << dest << endl;
}

void move_rings (int n, int scr, int dest, int other)
{
    if(n == 1)
    {
        move_a_ring(scr, dest);
    }
    else
    {
        move_rings(n - 1, scr, other, dest);
        move_a_ring(scr, dest);
        move_rings(n - 1, other, dest, scr);
    }
}

int main()
{
    int n;

    cout << "Enter The Number Of Rings: ";
    cin >> n;

    while ( n < 0 )
    {
        cout << "\nMust Be Above 1!! \nRe-enter: ";
        cin >> n;
    }

    cout << endl;

    move_rings(n, 1, 3, 2);

    return 0;
}
