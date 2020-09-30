// Use an ampersand (&) as a delimiter.

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char str[50], *p;
    int count_tokens = 0;

    cout << "Input a string: ";
    cin.getline(str, 50);

    p = strtok(str, "&");

    while (p != nullptr)
    {
        cout << p << endl;
        p = strtok(nullptr, "&");

        count_tokens += 1;

    }

    cout << endl << count_tokens << " tokens found!" << endl;

    return 0;
}
