// Revise Example 9.3 so that it prompts the user for a record number and then prompts the user for the rest of the data and repeats. To exit, the user enters ¨C1.

// Not sure i did it correctly, didnt understand the exercise

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>

using namespace std;

#define COL_WIDTH 80

int get_int (int default_number)
{
    char s[COL_WIDTH];

    cin.getline(s, COL_WIDTH);

    if (strlen(s) == 0)
    {
        return default_number;
    }

    return atoi(s);

}

int main()
{
    while(true)
    {
        char filename [FILENAME_MAX];
        int n = 0;
        int age = 0;
        char name[20];
        int recsize = sizeof(name) + sizeof(int);

        cout << "Filename: ";
        cin.getline(filename, FILENAME_MAX);

       fstream filebin (filename, ios::in | ios::binary);

        cout << "Record number: ";
        n = get_int(0);

        cout << "Name: ";
        cin.getline(name, sizeof(name) - 1);

        cout << "Age: ";
        age = get_int(0);

        filebin.write(name, sizeof(name) - 1);

        int opt;

        cout << endl << "Enter '-1' to exit, other to restart.\nEnter:  ";
        cin >> opt;

        if (opt == -1)
            break;

        cout << endl;



        system("cls");
    }
    return 0;
}
