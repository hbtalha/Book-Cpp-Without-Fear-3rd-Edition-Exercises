// Revise the program so that it keeps a running count of which decisions were made (how often the user stuck with the first door, how often she switched) and,
// as the user is about to quit, summarizes the ¡°win¡± percentage for each decision: What is the win percentage when the player sticks with the first door?
// What is the win percentage when the player switches?

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

class DoorManager
{
    int win_door, bad_door, alt_door, sel_door;

public:
    void start_new_game();
    void set_sel_door (int n);

     int get_bad_door()
     {
         return bad_door + 1;
     }

     int get_alt_door()
     {
         return alt_door + 1;
     }

     bool query_door(int n)
     {
         return n == (win_door + 1);
     }
};

void DoorManager::start_new_game()
{
    win_door = rand() % 3;
}

void DoorManager::set_sel_door(int n)
{
    sel_door = n -1;

    if (sel_door == win_door)
    {
        if (rand() % 2)
        {
            alt_door = (sel_door + 1) % 3;
            bad_door = (sel_door + 2) % 3;
        }
        else
        {
            bad_door = (sel_door + 1) % 3;
            alt_door = (sel_door + 2) % 3;
        }
    }
    else
    {
        alt_door = win_door;

        bad_door = 3 - sel_door - alt_door;
    }
}

class PrizeManager
{
public:
    string get_good_prize();
    string get_bad_prize();
};

string PrizeManager::get_good_prize()
{
    static const string prize_list[5] =
    {
        "YOUR BRAND NEW CAR!",
        "A BA-ZILLION DOLLARS!",
        "A EUROPEAN VACATION!",
        "A CONDO IN HAWAII!",
        "TEA WITH THE QUEEN OF ENGLAND!"
    };

    return prize_list[rand() % 5];
}
string PrizeManager::get_bad_prize()
{
    static const string prize_list[8] =
    {
        "two week's supply of Spam.",
        "a crate of rotting fish heads.",
        "a visit from a circus clown.",
        "two weeks at a clown college.",
        "a ten-year-old VCR player.",
        "a lesson from a mime.",
        "psychoanalysis from a clown.",
        "a tour of the city dump."
    };

    return prize_list[rand() % 8];
}

void play_game(int &maintain_choice_counter, int &switch_choice_counter, int &switch_choice_prize, int &switch_choice_stinker, int &maintain_choice_prize, int &maintain_choice_stinker);
int get_number();
PrizeManager prize_mgr;
DoorManager door_mgr;

int main()
{
    srand(time(nullptr));

    int maintain_choice_counter = 0, switch_choice_counter = 0, switch_choice_prize = 0, switch_choice_stinker = 0, maintain_choice_prize = 0, maintain_choice_stinker = 0;
    string s;

    cout << "Welcome to Good Deal, Bad Deal!" << endl;
    cout << "I'm your host, Monty Schmall." << endl;


    while(true)
    {
        play_game(maintain_choice_counter, switch_choice_counter, switch_choice_prize, switch_choice_stinker, maintain_choice_prize, maintain_choice_stinker);

        cout << "\n\n------------------------------------------------------------------------------------------------------------------------\n";


         cout << "Play again? (Y or N): ";
        getline(cin, s);

        if (s[0] == 'N' || s[0] == 'n')
        {
            break;
        }
    }

    cout << "\n\nNumber of times the contestant stuck with with the first door:" << maintain_choice_counter << endl;
    cout << "Number of times the contestant switched the door: " << switch_choice_counter << endl;

    cout << "\nNumber of times the contestant stuck with with the first door and won:" << maintain_choice_prize << endl;
    cout << "Number of times the contestant stuck with with the first door and lost:" << maintain_choice_stinker << endl;

    cout << "\nNumber of times the contestant switched the door and won: " << switch_choice_prize << endl;
    cout << "Number of times the contestant switched the door and lost: " << switch_choice_stinker << endl;

    return 0;
}

void play_game(int &maintain_choice_counter, int &switch_choice_counter, int &switch_choice_prize, int &switch_choice_stinker, int &maintain_choice_prize, int &maintain_choice_stinker)
{
    int n;
    string s;

    door_mgr.start_new_game();

    cout << "\nWhich of three doors would you like (1, 2, 3)? ";
    n = get_number();

    door_mgr.set_sel_door(n);

    cout << "\nBefore I reveal what's behind the door," << " I'm going to show a door you DIDN'T" << " pick." << endl;

    cout << "\nBehind door " << door_mgr.get_bad_door() << " is... " << prize_mgr.get_bad_prize();

    cout << "'\n\nNow, would you like to switch from Door" << " No. " << n << endl << " to Door No. " << door_mgr.get_alt_door() << "? (Y or N): ";
    getline(cin, s);

    if (s[0] == 'y' || s[0] == 'Y')
    {
        switch_choice_counter += 1;
    }
    else
    {
        maintain_choice_counter += 1;
    }

    bool switch_choice_check;

    switch_choice_check = false;

    if (s[0] == 'y' || s[0] == 'Y')
    {
        n = door_mgr.get_alt_door();

        switch_choice_check = true;
    }

    cout << "\nOk you just won...  ";

    if (door_mgr.query_door(n))
    {
        cout << prize_mgr.get_good_prize();

        if (switch_choice_check == true)
        {
            switch_choice_prize += 1;
        }
        else
        {
            maintain_choice_prize += 1;
        }
    }
    else
    {
        cout << prize_mgr.get_bad_prize();

        if (switch_choice_check == true)
        {
            switch_choice_stinker += 1;
        }
        else
        {
            maintain_choice_stinker += 1;
        }
    }
}

int get_number()
{
    string str;

    while(true)
    {
        getline(cin, str);

        int n = atoi(str.c_str());

        if (n >= 1 && n <= 3 )
        {
            return n;
        }

        cout << "Must be 1, 2 or 3! /nRe-enter: ";
    }

}
