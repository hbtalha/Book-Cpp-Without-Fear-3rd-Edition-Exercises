// Rewrite Example 8.3 so that it uses direct pointer reference, described at the end of Chapter 6, rather than array indexing.
// If you have reached the end of the string, the value of the current character is a null-terminator, so you can test for the end-of-string condition by using *p == '\0'.
// You can also use *p itself as the condition, because it is nonzero if it¡¯s not pointing to a zero (or null) value.

#include <iostream>
#include <string.h>

using namespace std;

void touppercase( char *p)
{
    while (true)
    {
        *p = toupper(*p);

        p++;

        if (*p == '\0')
            break;
    }
}
int main()
{
    char s[100];

    cout << "Enter to convert: ";
    cin.getline(s, 100);

    char *p = s;

    touppercase(p);

    cout << endl << "String Converted:" << s << endl;


    return 0;
}
