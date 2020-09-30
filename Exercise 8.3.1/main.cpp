// Write a program that is similar to Example 8.3 but converts the string input to all lowercase. (Hint: Use the tolower function from the C++ library.)

#include <iostream>
#include <string.h>

using namespace std;

void tolowercase( char *s)
{
    int length = strlen(s);

    for (int i = 0; i < length; ++i)
    {
        s[i] = tolower(s[i]);
    }
}
int main()
{
    char s[100];

    cout << "Enter to convert: ";
    cin.getline(s, 100);

    tolowercase(s);

    cout << endl << "String Converted:" << s << endl;


    return 0;
}
