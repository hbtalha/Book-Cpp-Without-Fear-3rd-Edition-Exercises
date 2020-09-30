// Write sub and div functions for the Fraction class, along with code in main to test these functions.
// (The algorithm for sub is similar to that for add, although you can write an even simpler function by
// multiplying the numerator of the argument by −1 and then just calling the add function.)

#include <iostream>
#include <cstdlib>

using namespace std;

class Fraction
{
    int num, den;

public:
    void set(int n, int d)
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

public:
    Fraction add(Fraction other);
    Fraction sub(Fraction other);
    Fraction mult(Fraction other);
    Fraction div (Fraction other);
};

void Fraction::normalize()
{
    if (num == 0 || den == 0)
    {
        num = 0;
        den = 1;
    }

    if (den < 0)
    {
        num *= -1;
        den *= den;
    }

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

Fraction Fraction::add(Fraction other)
{
    Fraction fract;

    int lcd = lcm(den, other.den);

    fract.set(num * other.den + den * other.num, lcd);

    return fract;
}

Fraction Fraction::sub(Fraction other)
{
    Fraction fract, fract1;

    other.num *= -1;

    fract.set(num, den);

    fract1 = fract.add(other);

  //  int lcd = lcm(den, other.den);

    //fract.set(num * other.den - den * other.num, lcd);

    return fract1;
}

Fraction Fraction::mult(Fraction other)
{
    Fraction fract;

    fract.set(num * other.num, den * other.den)    ;

    return fract;
}

Fraction Fraction::div(Fraction other)
{
    Fraction fract;

    fract.set(num * other.den, den * other.num);

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

    fract1.set(num1, den1);
    fract2.set(num2, den2);

    fract3 = fract1.sub(fract2);

    cout << fract1.get_num() << "/" << fract1.get_den() << " - " << fract2.get_num() << "/" << fract2.get_den() << " = ";

    cout << fract3.get_num() << "/" << fract3.get_den() << endl;

    return 0;
}
