// Write greater-than (>) and less-than (<) functions, and revise the main function of the example to test these functions.
// For example, test whether 1/2 + 1/3 is greater than 5/9. (Hint: Remember that A/B is greater than C/D if A * D > B * C.)

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

    friend ostream &operator<<(ostream &os, Fraction &p);

    bool operator==(const Fraction &p) const
    {
        return (num == p.num && den == p.den);
    }

    bool operator>(const Fraction &p) const
    {
        // return (num / den > p.num / p.den);

        return (num * p.den > p.num * den);
    }

    bool operator<(const Fraction &p) const
    {
        // return (num / den < p.num / p.den);

        return (num * p.den < p.num * den);
    }

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

    Fraction f1(8,2);
    Fraction f2(2,3);

    cout << f1 << endl << endl;

    if (f1 > f2)
    {
        cout << "The objects are equal!" << endl;
    }
    else
        cout << "The objects are not equal!" << endl;

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

ostream &operator<<(ostream &os, Fraction &p)
{
    os << "(" << p.num << "," << p.den << ")";;
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


























