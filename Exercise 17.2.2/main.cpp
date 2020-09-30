// Write a program that prompts for a number, which you then store as a long long.
// Permit the user to enter the number using optional digit separators.
// Then determine the first prime number bigger than the number entered and print this print number.
// If needed, refer to the prime-number-testing code in Chapters 2 and 4.

#include <iostream>
#include <cstdlib>
#include <cmath>

#define GROUP_SEP ','

using namespace std;

long long read_formatted_input(string num)
{
    for (int i = 0; i < num.size(); ++i)
    {
        if (num[ i ] == GROUP_SEP)
        {
            num.erase(i, 1);
        }
    }

    return atoll(num.c_str());
}

bool is_prime(long long n)
{
    double sqrt_n = sqrt(n);

    for (int i = 2; i <= sqrt_n; ++i)
    {
        if (n % i == 0)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    string n;

    cout << "Enter a number: ";
    getline(cin, n);

    long long num = read_formatted_input(n);

    int i = num;

    for (int i = num + 1; i > num; ++i)
    {
        if (is_prime(i))
        {
            cout << endl << "First prime number bigger than " << num << "  is " << i << endl;
            break;
        }
    }




    return 0;
}


























