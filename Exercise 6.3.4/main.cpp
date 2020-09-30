// Finally, extend support for the hundreds digits, so that values from 1 to 999 can be handled.
// If you¡¯re really ambitious, you can even revise the program so it handles numbers all the way up to 999,999!

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string tens_digits[ ] = { " ", " ", " twenty", " thirty", " forty", " fifty", " sixty", " seventy", " eighty", " ninety"};

    string units_digits[ ] = { "", " one", " two", " three", " four", " five", " six", " seven", " eight", " nine" };

    string tens_ [ ] = { " ten", " eleven", " twelve", " thirteen", " fourteen", "fifteen", " sixteen", " seventeen", " eighteen", " nineteen" };

    int n;

    string *p = tens_;

  //  cout << *((tens_ + 2) - 1 );

 //   cin.get();

    cout << "Enter a number: ";
    cin >> n;

    int tensDigits = n / 10;
    int unitsDigists = n % 10;

    int hundreds_ = n / 100;
    int hundreds_remainder = n % 100;
    int hundreds_tens = hundreds_remainder / 10;
    int hundreds_tens_remainder = hundreds_remainder % 10;

    int thousands = n / 1000;
    int thousands_remainder = n % 1000;
    int thousands_tens = thousands_remainder / 10;
    int thousand_hundreds = thousands_remainder / 100;
    int thousands_hundreds_remainder = thousands_remainder % 100;
    int thousands_hundreds_tens = thousands_hundreds_remainder / 10;
    int thousands_hundreds_tens_remainder = thousands_hundreds_remainder % 10;

     int thousands_ = n / 10000;
    int thousands__remainder = thousands % 10;
    int tens_thousands_hundreds = thousands_remainder / 100;
    int tens_thousands_hundreds_ = thousands_remainder % 100;
    int tens_thousands_hundreds__ = tens_thousands_hundreds_ / 10;
    int tens_thousands_hundreds_tens_remainder = tens_thousands_hundreds_ % 10;

    int _thousands_ = n / 100000;
    int _thousands__remainder = thousands % 10;
    int _tens_thousands_hundreds = thousands_remainder / 100;
    int _tens_thousands_hundreds_ = thousands_remainder % 100;
    int _tens_thousands_hundreds__ = _tens_thousands_hundreds_ / 10;
    int _tens_thousands_hundreds_tens_remainder = _tens_thousands_hundreds_ % 10;

    cout << endl;

    if ( n >= 1000 && n <= 99999)
    {
        if (n < 20000)
        {
            cout << units_digits[thousands];

            if ( thousands > 1)
                cout << " thousands";
            else if (thousands == 1)
                cout << " thousand";

            if (thousands_remainder >= 1 && thousands_remainder <= 9)
            {
                cout << units_digits[thousands_hundreds_remainder];
            }

            if ( thousands_remainder >= 10 && thousands_remainder <= 19)
            {
                cout << tens_[unitsDigists];
            }

            if ( thousands_remainder >= 20 && thousands_remainder <= 99)
            {
                cout << tens_digits[thousands_tens] << units_digits[unitsDigists];
            }

            if (thousands_remainder >= 100)
            {
                cout << units_digits[thousand_hundreds];

                if ( thousand_hundreds > 1)
                    cout << " hundreds";
                else if (thousand_hundreds)
                    cout << " hundred";

                if ( thousands_hundreds_remainder >= 1 && thousands_hundreds_remainder <= 9 )
                {
                    cout << units_digits[thousands_hundreds_remainder];
                }

                if ( thousands_hundreds_remainder >= 10 && thousands_hundreds_remainder <= 19)
                {
                    cout << tens_[unitsDigists];
                }

                if ( thousands_hundreds_remainder >= 20 )
                {
                    cout << tens_digits[thousands_hundreds_tens] << units_digits[thousands_hundreds_tens_remainder];
                }
            }
        }

        if ( n >= 20000 && n <= 99999 )
        {
            cout << tens_digits[ thousands_ ] << units_digits[ thousands__remainder ] << " thousands";

            cout << units_digits[ tens_thousands_hundreds ];

            if ( tens_thousands_hundreds > 1)
                cout << " hundreds";
            else if (tens_thousands_hundreds == 1)
                cout << " hundred";

            if ( tens_thousands_hundreds_ >= 1 && tens_thousands_hundreds_ <= 9 )
            {
                cout << units_digits[tens_thousands_hundreds_];
            }

            if ( tens_thousands_hundreds_ >= 10 && tens_thousands_hundreds_ <= 19)
            {
                cout << tens_[tens_thousands_hundreds_tens_remainder];
            }

            if ( tens_thousands_hundreds_ >= 20 )
            {
                cout << tens_digits[tens_thousands_hundreds__] << units_digits[ tens_thousands_hundreds_tens_remainder];
            }

        }
    }

    else if (n >= 100 && n <= 999)
    {
        cout << units_digits[hundreds_];

        if ( hundreds_ > 1)
            cout << " hundreds";
        else if (hundreds_ == 1)
            cout << " hundred";

        if ( hundreds_remainder >= 1 && hundreds_remainder <= 9 )
        {
            cout << units_digits[hundreds_remainder];
        }

        if ( hundreds_remainder >= 10 && hundreds_remainder <= 19)
        {
            cout << tens_[unitsDigists];
        }

        if ( hundreds_remainder >= 20 )
        {
            cout << tens_digits[hundreds_tens] << units_digits[hundreds_tens_remainder];
        }
    }
    else if (n >= 10 && n <= 19 )
    {
        cout << tens_[unitsDigists];
    }

    else
    {
        cout << tens_digits[tensDigits] << units_digits[unitsDigists];
    }

    cout << endl;

    return 0;
}
