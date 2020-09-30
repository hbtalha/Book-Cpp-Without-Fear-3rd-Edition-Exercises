// Rewrite Example 9.1 so it prompts for directory location and filename separately.
// (Hint: Use two strings and use the strcat function to join them.)

#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

int main()
{
    string filename, filepath;

    cout << "Enter the file name:";
    getline(cin, filename);

    cout << "Enter the file path:";
    getline(cin, filepath);

    ofstream file(filepath + filename);

    if (! file)
    {
        cout << endl << "The file could not be opened!" << endl;

        return -1;
    }

    cout << endl << filename << " was successufully opened!" << endl;
    file << "Helder Batlha created and opened the file";

    return 0;
}
