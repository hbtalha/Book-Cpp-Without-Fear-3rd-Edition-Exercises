// Write a version of the program that maintains an array of 70 integers of type long long.
// Then fill up this array with the first 70 Fibonacci numbers.
// (Note: In our nomenclature, we¡¯ve dubbed the first number F(0), not F(1).)
// Instead of using the Fibo(0) function from Example 17.2, set F(0) and F(1) directly.
// Then write a loop to calculate each remaining array element, (F(2) to F(70)),
// by adding the values of the two preceding array elements.
// Print the array with calls to the output_formatted_string function already provided.

#include <iostream>
#include <cstring>
#include <string>
#include <sstream>

#define GROUP_SEP ','
#define GROUP_SIZE    3

using namespace std;

int fibo (int n)
{
    if (n < 2)
    {
        return 1;
    }

    long long temp1 = 1;
    long long temp2 = 1;
    long long total = 0;

    while (n-- > 1)
    {
        total = temp1 + temp2;
        temp2 = temp1;
        temp1 = total;
    }

    return total;
}

string output_formatted_string(long long num)
{
    // Read data into string s.
    stringstream temp, out;
    temp << num;
    string s = temp.str();

    int n = s.size() % GROUP_SIZE;
    int i = 0;
    if (n > 0 && s.size() > GROUP_SIZE)
    {
        out << s.substr(i, n) << GROUP_SEP;
        i += n;
    }
    n = s.size() / GROUP_SIZE - 1;
    while (n-- > 0)
    {
        out << s.substr(i, GROUP_SIZE) << GROUP_SEP;
        i += GROUP_SIZE;
    }
    out << s.substr(i);
    return out.str();
}

int main()
{
    long long fibo_array[70];

    for (int i = 0; i < 70; ++i)
    {
        fibo_array[ i ] = fibo(i + 2);
    }

    string s;

    for (int i = 0; i < 70; ++i)
    {
         s = output_formatted_string(fibo_array[ i ]);

        cout << "\nFibo(" << i + 2 << ") = " << s << endl;
    }

    return 0;
}
