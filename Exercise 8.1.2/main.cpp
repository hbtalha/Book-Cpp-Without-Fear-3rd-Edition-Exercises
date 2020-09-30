// After completing Exercise 8.1.1, test it by experimenting with different limitations for the str string.
// It helps if you replace the number 600 with the symbolic constant STRMAX, putting the following #define directive at the beginning of the program.
// During preprocessing, this directive causes the compiler to replace occurrences of STRMAX in the source code with the indicated text (600).

//     #define STRMAX 600

#include <iostream>
#include <cstring>

#define STRMAX 100

using namespace std;

int main()
{
    char str[STRMAX];
    char name[100] ;
    char address[100];
    char workplace[100];

    cout << "Enter your name: ";
    cin.getline(name, 100);
    cout << "Enter your address: ";
    cin.getline(address, 100);
    cout << "Enter your workplace: ";
    cin.getline(workplace, 100);

    strncpy(str, "\nMy name is ", STRMAX);
    strncat( str, name, STRMAX - strlen(str));
    strncat( str, ", I live in ", STRMAX - strlen(str));
    strncat( str, address, STRMAX - strlen(str));
    strncat( str, ", \nand i work in ", STRMAX - strlen(str));
    strncat( str, workplace, STRMAX - strlen(str));

    cout << str << endl;

    return 0;
}
