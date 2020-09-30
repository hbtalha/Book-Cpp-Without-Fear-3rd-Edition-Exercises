// Subtraction Game
// The Player Who Gets To Zero(0) first, Wins

#include <iostream>

using namespace std;

int main ()
{
    int total;
    int n;
    int l; // range limit
    int opt;

    do
    {
        system("cls");

        cout << "Pick Up A Starting Total: ";
        cin >> total;

        while (total <= 0)
        {
            cout << "\nOops! Total Can't Be Less Than 0!!\nRe-enter:";
            cin >> total;
        }

        cout << "Pick Up The Range From 1 To:";
        cin >> l;

        while (l <= 1)
        {
            cout << "Must Be Above 1\nRe-enter:";
            cin >> l;
        }

        while (true)
        {
            cout << "\nEnter Your Subtracting Number From 1 To " << l << ": ";
            cin >> n;

            while (n < 1 || n >l)
            {
                cout << "\nThe number must be from 1 To " << l << ": "
                     << "\nRe-enter: ";
                cin >> n;
            }

            total-=n;

            cout << "New Total: " << total << endl;

            if (total <= 0 )
            {
                cout <<"\a\nYou Win!!" << endl;
                break;
            }
        }

        cin.get();
        cin.get();

        system("cls");

        cout << " 1 To Play Again , Other To finish" << endl << endl;
        cout << "Enter: ";
        cin >> opt;
    }
    while (opt == 1);

}

