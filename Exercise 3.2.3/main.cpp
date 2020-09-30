// Assuming that you¡¯ve completed Exercise 3.2.2, you should be able to write a program that implements the optimum strategy.
// Assume that you, the user, have picked a number in secret. The program should go into a loop in which it asks YOU (the user) whether the guess is too high, too low, or just right.
// The program should then use the high/low answer to refine its guess and make another. Note that you are on your honor to answer honestly.
// Tip: To make the program easy to write, use an arbitrary system of numbers to signal the answer: 1=too high, 2=too low, 3=success.

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    int n;
    int last_guess = 1;
    int hold_last_guesshigh = 150;
    int hold_last_guesslow = 1;
    int number_of_guesses = 0;

    cout << "Pick Your Number (1 - 150): ";
    cin >> n;

    while ( n < 1 || n > 150)
    {
        cout << "\nMust Be Between 1 and 150!! \nRe-enter: ";
        cin >> n;
    }

    srand( static_cast <unsigned int> ( time (NULL) ) );
    int guess = rand() % 150;

    while (true)
    {
        cout << endl << "My Guess: " << guess << endl;

        /*if ( guess == n)
        {
            cout << endl << guess << "\a -> The Right Number!!" << endl;
            break;
        }*/

        int opt;

        cout << endl << "Number Of Guesses: " << ++number_of_guesses << endl << endl;

        cout << "\nIf guess is too low press 1.";
        cout << "\nIf guess is too high press 2.\n";
        cout << "If guess is right press any other Number.\n\n";
        cout << "Choose: ";
        cin >> opt;

        if (opt == 2)
        {
            cout << endl << guess << " Too High!!" << endl;

            hold_last_guesshigh = guess;

            guess =  last_guess + rand() %(hold_last_guesshigh   - last_guess + 1);

            while ( guess == hold_last_guesshigh)
            {
                guess =  last_guess + rand() %(hold_last_guesshigh   - last_guess + 1);
            }
        }
        else if (opt == 1)
        {
            cout << endl << guess << " Too Low!!" << endl;

            hold_last_guesslow = guess;

            guess = guess + rand() % (hold_last_guesshigh  - guess + 1) ;

            while( guess == hold_last_guesslow)
            {
                guess = guess + rand() % (hold_last_guesshigh  - hold_last_guesslow + 1) ;
            }
        }
        else
        {
            cout << endl << "The Right Number!!" << endl;
            break;
        }

        last_guess = hold_last_guesslow;
    }

    return 0;
}
