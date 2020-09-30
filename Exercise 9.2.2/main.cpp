// lter the example again so that it prints the contents of the file in all-uppercase letters.
// You may find it helpful to copy some of the code from Exercise 8.3 on page 195.

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>

#define COL_WIDTH 80


using namespace std;

void convert_touppercase (char *s)
{
    int length = strlen(s);

    for (int i = 0; i < length; ++i )
    {
        s[i] = toupper(s[i]);
    }
}

int main()
{
    int c;
    char filename[PATH_MAX];
    char input_line[COL_WIDTH + 1];

    cout << "Enter the file name:";
    cin.getline(filename, PATH_MAX);

    fstream file(filename, ios::in | ios::binary);

    if (! file)
    {
        cout << endl << filename << " could not be opened!";
        return -1;
    }

    int lines = 24;

    string exit;

    while (true)
    {
        for (int i = 0; i <= lines && ! file.eof(); i++)
        {
            file.getline(input_line, COL_WIDTH);

            convert_touppercase(input_line);

            cout << input_line << endl;
        }

        if (file.eof())
        {
            break;
        }

        file.close();

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
