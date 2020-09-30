#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int i = 2;
    int n = 0;
    bool is_prime = true;
    double sqrootm = 0;

    cout << "Enter a number and press Enter:";
    cin >> n;

    sqrootm = sqrt(n);

    while (i <= sqrootm)
        if (n % i == 0)
        {
            is_prime = false;
            break;
        }
        ++i;
    }

    if (is_prime)
    {
        cout << n << " is a prime number!" << endl;
    }
    else
    {
        cout << n << " is not a prime number!" << endl;
    }

    return 0;
}
