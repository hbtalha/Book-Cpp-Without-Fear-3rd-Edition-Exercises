// For the more ambitious: Write a version that permits subtracting any number from 1 to n, where n is stipulated at the beginning of the game.
// For example, the user when prompted might say that each player can subtract any number from 1 to 7.
//Can you create an optimal computer strategy for this general case?

// Subtraction Game
// The Game trick is simple, the computer will subtract a number so the result can be a multiple of the limit range number plus one
// e.g if the total is 57 and the limit range number is 4, the pc will subtract 2 so the result will be 55 wich is multiple of 5, the limit range number

#include <iostream>

using namespace std;

int main ()
{
    int total;
    int n;
    int limit_range; // range limit

    cout << "Pick Up A Starting Total: ";
    cin >> total;

    while (total <= 0)
    {
        cout << "\nOops! Total Can't Be Less Than 1!!\nRe-enter:";
        cin >> total;

        if ( total > 0)
            cout << endl << "Starting Total = " << total << endl;

    }

    cout << "Pick Up The Range From 1 To:";
    cin >> limit_range;

    while (limit_range <= 1)
    {
        cout << "\nMust Be Above 1\nRe-enter:";
        cin >> limit_range;

    }

    while (true)
    {
        int decrementation = limit_range; // the remainder start by the range limit

        while (true)
        {
            int divisor = limit_range + 1;
            --decrementation;  //- - decrementation, it keeps on decrementing until it matches a remainder

            if (total % divisor == limit_range )
            {
                total -= limit_range;
                cout << endl << "I Am Subtracting... " << limit_range << endl;
                cout << "New Total: " << total << endl;
                break;
            }
            else if (total % divisor == 0)
            {
                --total;
                cout << "\nI Am Subtracting... 1" << endl;
                cout << "New Total: " << total << endl;
                break;
            }
            else if (total % divisor == 1)
            {
                --total;
                cout << "\nI Am Subtracting... 1" << endl;
                cout << "New Total: " << total << endl;
                break;
            }
            else if (total % divisor == decrementation )
            {
                total -= decrementation;
                cout << "\nI Am Subtracting... " << decrementation << endl;
                cout << "New Total: " << total << endl;
                break;
            }
        }

        if (total <= 0 )
        {
            cout << "\a";

            cout <<"I Win!!" << endl;
            break;
        }

        cout << "\nEnter Your Subtracting Number From 1 To " << limit_range << ": ";
        cin >> n;

        while (n < 1 || n > limit_range)
        {
            cout << "\nThe number must be from 1 To " << limit_range
                 << "\nRe-enter: ";
            cin >> n;

            if (n <= limit_range)
                cout << endl;
        }

        total -=n;

        cout << "New Total: " << total << endl;

        if (total <= 0 )
        {
            cout <<"\a\n\nYou Win!!" << endl;
            break;
        }
    }

    cin.get();
    cin.get();
}
