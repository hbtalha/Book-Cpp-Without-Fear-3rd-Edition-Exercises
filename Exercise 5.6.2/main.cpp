// Write a random-number generator that returns a random floatingpoint number between 0.0 and 1.0.
// (Hint: Call rand, cast the result r to type double by using static_cast<double>(r),
// and then divide by the highest value in the int range, RAND_MAX.) Make sure you declare the function with the double return type.

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

double random_generator ( double a, double b)
{
      return (b - a) * ( static_cast <double> (rand() / static_cast <double> (RAND_MAX))) + 1; // can't figure it out, i just pasted from an Internet forum, and it doesn't work the way I expect
}

int main()
{
   double n1, n2;

    cout << "Enter number1: ";
    cin >> n1;

    cout << "Enter number2: ";
    cin >> n2;

    srand(time(nullptr));

    cout << endl << random_generator(n1, n2) << endl;

    return 0;
}
