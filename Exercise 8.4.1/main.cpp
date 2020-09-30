// Revise the example so that in addition to printing out tokens (substrings) one to a line, the program also prints a statement telling how many tokens it found.

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char str[50], *p;
    int count_tokens = 0;

    cout << "Input a string: ";
    cin.getline(str, 50);

    p = strtok(str, ",");

    while (p != nullptr)
    {
        cout << p << endl;
        p = strtok(nullptr, ",");

        count_tokens += 1;
    }

    cout << endl << count_tokens << " tokens found!" << endl;

    return 0;
}
