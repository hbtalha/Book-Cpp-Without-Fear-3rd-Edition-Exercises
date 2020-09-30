// Write a program that lets the user enter any number of lines of text, one at a time.
// In effect, this creates a primitive editor that permits text entry but no editing of a line of text after it¡¯s been entered.
// Set up a loop that doesn¡¯t terminate until the user presses ENTER without typing any text (a zero-length string).
// Alternatively, you can recognize a special code (for example, @@@) to terminate the session.
// You can then use the strcmp (¡°string compare¡±) function to detect this string.
// You may recall that what this function does is to compare two C-strings and return 0 if they have the same contents

#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

int main()
{
    string filename;
    while (true)
    {
        cout << "Enter the file name ('@@@' to exit):";
        getline(cin, filename);

        if ( filename == "@@@")
        {
            break;
        }

        ofstream file(filename);

        if (! file)
        {
            cout << endl << "The file could not be opened!" << endl;
            cout << endl;
        }
        else
        {
            cout << endl << filename << "  successufully opened" << endl;
            cout << endl;
        }

        file << "Helder Batlha created and opened the file";
    }






    return 0;
}
