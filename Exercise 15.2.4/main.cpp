// Prevent any card from being redrawn more than once.
// Right now, the user can enter ¡°333¡± and the result is that Card Number 3 will be replaced over and over.
// The ultimate effect will be the same as if it were drawn only once, but this is inefficient, and furthermore,
// if you¡¯re counting down the deck, there will be cards you never see.
// Prevent this from happening so that if the user types ¡°333¡±, the card will be redrawn, but only once.

#include <iostream>
#include <cstdlib>
#include <time.h>
#include <algorithm>
#include <list>

using namespace std;

class Card
{
public:
    int rank;
    int suit;

    Card () {}

    Card(int r, int s)
    {
        rank = r;
        suit = s;
    }

    string display();
};

string Card::display()
{
    static const string aRanks[ ] = {" 2", " 3", " 4"," 5", " 6", " 7", " 8", " 9", "10", " J", " Q", " K", " A" };
    static const string aSuits[ ] = { "clubs", "diamonds", "hearts", "spades" };

    return aRanks[rank] + " of " + aSuits[suit] + ".";
}

class Deck
{
    int cards[52];
    int iCard;
    void shuffle();

public:
    Deck();
    Card deal_a_card();
};

Deck::Deck()
{
    srand(time(nullptr));

    for (int i = 0; i < 52; ++i)
    {
        cards[i] = i;
    }

    shuffle();
}

void Deck::shuffle()
{
    iCard = 0;

    for (int i = 51; i > 0; --i)
    {
        int j = rand() % (i + 1);

        int temp = cards[ i ];
        cards[ i ] = cards[ j ];
        cards[ j ] = temp;
    }
}

Card Deck::deal_a_card()
{
    if (iCard > 52)
    {
        cout << "Reshuffling..." << endl;

        shuffle();
    }

    int r = cards[iCard] % 13;
    int s = cards[iCard++] / 13;

    return Card(r, s);
}

Card aCards[5];
Deck my_deck;
void play();
bool aFlags[5];
bool draw();

list <int> selList;
list <int>::iterator iter;

int main()
{
    string s;

    while (true)
    {
        cout << endl;

        play();

        cout << endl << "Play Again? (Y or N) ";
        getline(cin, s);

        if (s[0] == 'n' || s[0] == 'N')
        {
            break;
        }
        else if (s[0] != 'Y' && s[0] != 'y')
        {
            while (true)
            {
                cout << endl << "Wrong Entrance(Must Be Y or N)!! \nEnter Again: ";
                getline(cin, s);

                if (s[0] == 'n' || s[0] == 'N' || s[0] == 'y' || s[0] == 'Y')
                    break;
            }
        }

        if (s[0] == 'n' || s[0] == 'N')
            break;
    }
}

void play()
{
    for (int i = 0; i < 5; ++i)
    {
        aCards[i] = my_deck.deal_a_card();

        cout << i + 1 << ". ";

        cout << aCards[i].display() << endl;
    }

    if (draw())
    {
        cout << endl;

        for (int i = 0; i < 5; ++i)
        {
            cout << i + 1 << ". ";

            cout << aCards[i].display();

            if (aFlags[i])
            {
                cout << " *" ;
            }

            cout << endl;
        }
    }
}

bool draw()
{
    string input;
    selList.clear();

    cout << "\nInput the #'s to redraw: ";
    getline(cin, input);

    if (input.size() == 0)
    {
        return false;
    }

    int r1 = 0, r2 = 0, r3 = 0, r4 = 0, r5 = 0; // track repetitions

    for (int i = 0; i < input.size(); ++i)
    {
        int n = input[i] - '0';

        if (n == 1)
        {
            r1 += 1;
        }
        if (n == 2)
        {
            r2 += 1;
        }
        if (n == 3)
        {
            r3 += 1;
        }
        if (n == 4)
        {
            r4 += 1;
        }
        if (n == 5)
        {
            r5 += 1;
        }

        if (n >= 1 && n <= 5 && r1 <= 1 &&  r2 <= 1 && r3 <= 1 && r4 <= 1 &&  r5 <= 1)
        {
            selList.push_back(n - 1);
        }
/*
        if (r1 > 1)
        {
            selList.pop_back();

            r1 -= 1;
        }
        if (r2 > 1)
        {
            selList.pop_back();

            r2 -= 1;
        }
        if (r3 > 1)
        {
            selList.pop_back();

            r3 -= 1;
        }
        if (r4 > 1)
        {
            selList.pop_back();

            r4 -= 1;
        }
        if (r5 > 1)
        {
            selList.pop_back();

            r5 -= 1;
        }
*/
    }

    int lis = selList.size();

    for (iter = selList.begin(); iter != selList.end(); ++iter)
    {
        int n = *iter;
        aCards[n] = my_deck.deal_a_card();
        aFlags[n] = true;
    }


    return true;
}
