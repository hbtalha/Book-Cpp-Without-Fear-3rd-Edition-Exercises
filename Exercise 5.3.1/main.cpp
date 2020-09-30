// Rewrite the main function for Example 5.3 so that it prints the prompt message ¡°Enter a number (0 = exit) and press ENTER.¡±
// The program should call get_divisors to show the prime factorization and then prompt the user again, until he or she enters 0.
// (Hint: If you need to, look at the code for Example 5.2 on page 106.)


#include <iostream>
#include <cmath>

using namespace std;

void get_divisors(int n)
{
    double sqr_n = sqrt(n);

    for ( int i = 2; i <= sqr_n; ++i )
    {
        if ( n % i == 0 )
        {
            cout << i << "  ";
            get_divisors( n / 2);
            return;
        }
    }
}

int main()
{
    int n;
    while (true)
    {
        cout << "\nEnter a number (0 to exit): ";
        cin >> n;

        if( n == 0)
            break;

        get_divisors(n);

        cout << endl;
    }
    return 0;
}
