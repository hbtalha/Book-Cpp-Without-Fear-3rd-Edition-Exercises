// Create an array of five Fraction objects. Then, write a loop to input the numerator and denominator for each.
// Finally, write a loop to print each of the five objects, using ¡°get¡± functions.

#include <iostream>
#include <cstdlib>

#define MAX 2

using namespace std;

class Fraction
{
    int den, num;

public:
    void set_fraction(int n, int d)
    {
        num = n;
        den = d;

        normalize();
    }

    int get_num()
    {
        return num;
    }

    int get_den()
    {
        return den;
    }

private:
    void normalize();
    int gcf(int a, int b);
    int lcm(int a, int b);
};

void Fraction::normalize()
{
    // handle case involving 0
    if (den == 0 || num == 0)
    {
        num = 0;
        den = 1;
    }

    // handle neg. number
    if (den < 0)
    {
        num *= -1;
        den *= -1;
    }

    // simplifying the fraction
    int n = gcf(num, den);
    num /= n;
    den /= n;
}

int Fraction::gcf(int a, int b)
{
    if (b == 0)
    {
        return abs(a);
    }

    return gcf(b, a%b);
}

int Fraction::lcm(int a, int b)
{
    int n = gcf(a, b);
    return a / n * b;
}

int main()
{
    Fraction farr[5];

    for (int i = 0; i < MAX; ++i)
    {
        int num, den;

        cout << "Numerator of the fraction" << i + 1 << ": ";
        cin >> num;
        cout << "Denominator of the fraction" << i + 1 << ": ";
        cin >> den;

        farr[i].set_fraction(num, den);

        cout << endl;
    }

    cout << endl;

    for (int i = 0; i < MAX; ++i)
    {
        cout << farr[i].get_num() << "/" << farr[i].get_den() << ",  ";
    }

    cout << endl;


    return 0;
}
