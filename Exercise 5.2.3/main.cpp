// Write a program that finds the first prime number greater than 1 billion (1,000,000,000).

#include <iostream>
#include <cmath>

using namespace std;

bool is_prime( int n)
{
    double square_root = sqrt(n);

    for (int i = 2; i <= square_root; ++i  )
    {
        if ( n % i == 0)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    int n = 1000000000;

    for ( int i = n+1; i > n; ++i)
    {
        if (is_prime(i))
        {
            cout << endl << i << " is the first prime number larger than " << n << endl;
            break;
        }
    }

    return 0;
}
