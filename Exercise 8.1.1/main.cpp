// Rewrite the example so that it cannot exceed the limits of str. For example, you¡¯d replace the statement
//        ' strcat(str, addr); ,
// with the following statement:
//        ' strncat(str, addr, 600 - strlen(str)); '

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char str[600];
    char name[100] ;
    char address[100];
    char workplace[100];

    cout << "Enter your name: ";
    cin.getline(name, 100);
    cout << "Enter your address: ";
    cin.getline(address, 100);
    cout << "Enter your workplace: ";
    cin.getline(workplace, 100);

    strncpy(str, "\nMy name is ", 600);
    strncat( str, name, 600 - strlen(str));
    strncat( str, ", I live in ", 600 - strlen(str));
    strncat( str, address, 600 - strlen(str));
    strncat( str, ", \nand i work in ", 600 - strlen(str));
    strncat( str, workplace, 600 - strlen(str));

    cout << str << endl;

    return 0;
}
