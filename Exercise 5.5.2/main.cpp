// Instead of printing the ¡°Move¡± message directly on the screen, have the move_ring function call yet another function, to which you give the name exec_move.
// The exec_move function should take a source and destination stack number as its two arguments.
//Because this is a separate function, you can use as many lines of code as you need to print a message. You can print a more informative message:

// 'Move the top ring from stack 1 to stack 3'.

#include <iostream>

using namespace std;

void exc_move (int scr, int dest)
{
    cout << "Move The Top Ring From Stack " << scr << " To Stack " << dest << endl;
}
void move_a_ring(int scr, int dest)
{
    exc_move(scr, dest);
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

