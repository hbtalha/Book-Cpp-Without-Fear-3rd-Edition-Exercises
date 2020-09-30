// Modify Example 5.3 so that it uses a nonrecursive solution. You will end up having to write more code. (Hint: To make the job easier, write two functions:
// get_all_divisors and get_lowest_divisor. The main function should call get_all_ divisors, which in turn has a loop: get_all_divisors calls get_lowest_divisor repeatedly,
// each time replacing n with n/i, where i is the divisor that was found. If n itself is returned, then the number is prime and the loop should stop.)

#include <iostream>
#include <cmath>

using namespace std;

using namespace std;

void get_divisors(int n);

void get_lowest ( int n)
{
    get_divisors(n / 2);
}

void get_divisors(int n)
{
    double sqr_n = sqrt(n);

    for ( int i =2; i <= sqr_n; ++i )
    {
        if ( n % i == 0 )
        {
            cout << i << "  ";
            get_lowest(n);
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
