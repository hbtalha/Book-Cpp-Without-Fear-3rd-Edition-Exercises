#include <iostream>
#include <stdlib.h>

using namespace std;

class DoorManager
{
    int alt_door, bad_door, winDoor, selDoor;

public:
    void start_new_game();
    void set_sel_door(int n);

    int get_alt_door()
    {
        return alt_door;
    }

    int get_bad_door()
    {
        return bad_door;
    }

    bool query_door(int n)
    {
        return n == (winDoor);
    }
};

void DoorManager::start_new_game()
{
    winDoor = rand() % 3 + 1;
}

void DoorManager::set_sel_door(int n)
{
    if (selDoor == winDoor)
    {
        if (rand() % 2)
        {
            alt_door = (selDoor) % 3;
            bad_door = (selDoor) % 3;
        }
        else
        {
            bad_door = (selDoor + 1) % 3;
            alt_door = (selDoor + 2) % 3;
        }
    }
    else
    {
        alt_door = winDoor;

        bad_door = 3 - alt_door - selDoor;
    }
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
