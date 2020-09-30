// Write a program that initializes an array of eight integers with the values 5, 15, 25, 35, 45, 55, 65, and 75, and then prints each of these out.
// (Hint: Instead of using the loop condition i < 5, use i < 8, because in this case there are eight elements.)

#include <iostream>

using namespace std;

int main()
{
    int n[8] = {5, 15, 25, 35, 45, 55, 65, 75};

    for(int i = 0; i < 8; ++i)
    {
        cout << n[i] << " ";
    }

    return 0;
}
