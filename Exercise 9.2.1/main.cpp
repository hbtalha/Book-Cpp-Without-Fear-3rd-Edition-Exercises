// Alter Example 9.2 so the user can optionally enter a number in response to the ¡°More?¡± prompt.
// The number determines how many lines to print at a time instead of 24.
// (Hint: Use the atoi library function to convert string input to integer; if the value entered is greater than 0, modify the numbers of lines to read).

#include <iostream>
#include <fstream>
#include <cstdlib>

#define COL_WIDTH 80


using namespace std;

int main()
{
    int c;
    char filename[PATH_MAX];
    char input_line[COL_WIDTH + 1];

    cout << "Enter the file name:";
    cin.getline(filename, PATH_MAX);

    ifstream file (filename);

    if (! file)
    {
        cout << endl << filename << " could not be opened!" << endl;
        return -1;
    }

    int lines = 24;

    string exit;

    while (true)
    {
        for (int i = 0; i <= lines && ! file.eof(); i++)
        {
            file.getline(input_line, COL_WIDTH); // didnt understand this loop, specially this part
            cout << input_line << endl;
        }

        if (file.eof())
        {
            break;
        }

        cout << "\nPress 'Q' to exit or how many more lines to display:";
        getline(cin, exit);

        c = exit[0];

        lines = atoi(exit.c_str()) - 1;

        if (c == 'Q' || c == 'q')
        {
            break;
        }
    }

    return 0;
}
