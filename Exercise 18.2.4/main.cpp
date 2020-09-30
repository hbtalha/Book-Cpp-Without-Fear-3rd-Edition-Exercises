// Revise the Fraction class so that every member function is declared const, except for the functions for
// which this would be inappropriate (set, normalize, and the constructors).

#include <iostream>
#include <stdlib.h>

using namespace std;

class Fraction
{
    int num, den;

public:
    Fraction () {}

    Fraction(int x, int y)
    {
        set(x, y);
    }

    Fraction add(const Fraction &p);
    Fraction sub(const Fraction &p);
    Fraction mult(const Fraction &p) const;
    Fraction div(const Fraction &p) const;

    Fraction operator/(Fraction &p)
    {
        return div(p);
    }

    Fraction operator-(Fraction &p)
    {
        return sub(p);
    }

    Fraction operator+( Fraction &p)
    {
        return add(p);
    }
    Fraction operator*(const Fraction &p)
    {
        return mult(p);
    }

    bool operator==(const Fraction &p);

    void set(int x, int y)
    {
        num = x;
        den = y;
    }

    int get_num() const
    {
        return num;
    }

    int get_den() const
    {
        return den;
    }

private:
    void normalize();
    int lcd(int a, int b); // lowest common denom.
    int gcf(int a, int b); // greatest common fatcor

};

int main()
{
    Fraction fract[199];
    Fraction fract1;
    int num, den, n = 0;

    Fraction f(2,3);
    Fraction f1(9,3);
    Fraction f2 = f * f1;

    if (f1 == f2)
    {


    }
    else
        cout << "oh yeah";

    return 0;
}

void Fraction::normalize()
{
    // handling cases involving zer0
    if (num < 0 || den < 0)
    {
        num = 0;
        den = 1;
    }

    // handling negative numbers
    if (den < 0)
    {
        num *= -1;
        den *= -1;
    }

    // Factor out GCF from numerator and denominator.

    int n = gcf(num, den);

    num = num / n;
    den = den / den;

}

int Fraction::lcd(int a, int b)
{
    int n = gcf(a, b);

    return a / n *b;
}

int Fraction::gcf(int a, int b)
{
    if (b == 0)
    {
        return abs(a); // abs means '" absolute value ", meaning it ensures that only positive numbers are returned
    }
    else
        gcf(b, a%b);
}

Fraction Fraction::add(const Fraction &p)
{
    int n = lcd(den, p.den); // n = lcd

    return Fraction (num * p.den + den * p.num, n);

}

Fraction Fraction::sub(const Fraction &p)
{
    int n = lcd(den, p.den); // n = lcd

    return Fraction (num * p.den + den * p.num, n);

}

Fraction Fraction::div(const Fraction &p) const
{
    return Fraction (num * p.den, den * p.num);
}

Fraction Fraction::mult(const Fraction &p) const
{
    return Fraction(num * p.num, den * p.den);
}


bool Fraction::operator==(const Fraction &p)
{
    return (num == p.num && den == p.den);
}
