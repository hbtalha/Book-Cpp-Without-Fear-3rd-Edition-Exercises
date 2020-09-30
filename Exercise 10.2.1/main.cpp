// Rewrite the normalize function so that it uses the division- assignment operator (/=).

#include <iostream>
#include <cstdlib>

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

    void qq()
    {
        //cout << endl << gcf(6, 4) << endl;
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
    Fraction f;

    f.set_fraction(156, 12);

    f.qq();
    cout << f.get_num() << "\n----\n" << f.get_den() << endl;

    return 0;
}
