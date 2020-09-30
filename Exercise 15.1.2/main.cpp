// Rewrite the program so that there is no default action. In other words, require the user to type either a ¡°Y¡± or ¡°N.¡±
// Keep querying the user until she responds accordingly.

#include <iostream>
#include <cstdlib>
#include <time.h>

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


}
