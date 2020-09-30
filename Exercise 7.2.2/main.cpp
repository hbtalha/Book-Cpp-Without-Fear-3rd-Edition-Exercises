// Write a program with a function named convert_temp: The function takes the address of a variable of type double and applies Centigrade-to-Fahrenheit conversion.
// A variable that contains a Centigrade temperature should, after the function is called, contain the equivalent Fahrenheit temperature.
// Test the function. (Hint: The relevant formula is F = (C * 1.8) + 32.)

#include <iostream>

using namespace std;

double convert_temp( double *t)
{
    return *t = ((*t * 1.8) + 32);
}

int main()
{
    double t;

    cout << "Enter a temperature in celsius: ";
    cin >> t;

    double tc = t;

    convert_temp(&t);

    cout << endl << tc << " degrees celsius is equivalent to " << t << " degrees fahrenheit.\n";

    return 0;
}
