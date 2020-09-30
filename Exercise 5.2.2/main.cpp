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
    for ( int i = 2; i <= 20; ++i )
    {
        if (is_prime(i))
        {
            cout << i << " is a prime number.\n\n";
        }
        else
        {
            cout << i << " is not a prime number.\n\n";
        }
    }

    return 0;
}
