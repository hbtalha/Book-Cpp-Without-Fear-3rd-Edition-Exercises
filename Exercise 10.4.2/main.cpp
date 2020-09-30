// Rewrite main so that it multiplies any two fractions input and prints the results.

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

private:
    void normalize();
    int gcf(int a, int b);
    int lcd(int a, int b);

public:
    Fraction add(Fraction other);
    Fraction mult(Fraction other);
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

int Fraction::lcd(int a, int b)
{
    int n = gcf(a, b);
    return a / n * b;
}

Fraction Fraction::add(Fraction other)
{
    Fraction fract;

    int l_c_d = lcd(den, other.den);

    fract.set_fraction(num * other.den + den * other.num, l_c_d);

    return fract;
}

Fraction Fraction::mult(Fraction other)
{
    Fraction fract;

    fract.set_fraction(num * other.num, den * other.den);

    return fract;
}

int main()
{
    Fraction fract1, fract2, fract3;

    int den1, num1, den2, num2;

    cout << "Numerator of the fraction1: ";
    cin >> num1;

    cout << "Denumerator of the fraction1: ";
    cin >> den1;

    cout << endl;

    cout << "Numerator of the fraction2: ";
    cin >> num2;

    cout << "Denumerator of the fraction2: ";
    cin >> den2;

    cout << endl;

    fract1.set_fraction(num1, den1);
    fract2.set_fraction(num2, den2);

    fract3 = fract1.mult(fract2);

    cout << fract1.get_num() << "/" << fract1.get_den() << " * " << fract2.get_num() << "/" << fract2.get_den() << " = ";

    cout << fract3.get_num() << "/" << fract3.get_den() << endl;

    return 0;
}
