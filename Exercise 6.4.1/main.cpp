#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int deck[52];

void swap_cards(int i, int j )
{
    int hold = deck[ i ];
    deck[ i ] = deck[j];
    deck[ j ] = hold;
}

int random(int n)
{
    return rand() % (n + 1);
}

int main()
{
    string cards_name[ ] = { "Rei", "Conde", "Dama", "Dez", "Nove", "Oito", "Sete", "Sena", "Quina", "Quadra", "Terno", "Duque", "As" };

    srand(time (nullptr));

    for ( int i = 0; i < 52; ++i)
    {
        deck[i] = i;
    }

    for ( int i = 51; i >= 0; --i)
    {
        int j = random(i);

        swap_cards(i, j);
    }

    for ( int i = 0; i < 5; ++i)
    {
        int j = deck[i] % 13;

        cout << cards_name[j] << "  ";
    }

    cout << endl;

    return 0;
}
