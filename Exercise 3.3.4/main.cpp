// Extend the program so that it handles values as high as 999.
//( Hint: you¡¯ll need to complete Exercise 3.3.3 first, or the range of acceptable values will have many ¡°holes¡± in it.)

#include <iostream>

using namespace std;

int main()
{
    int n;

    cout << "Enter a number:" ;
    cin >> n;
    cout << endl;

    // variables for number 1 - 99
    int tens_digits = n / 10;
    int units_digits = n % 10;
    int tens = n % 10;

    // variables for number 100 - 999
    int hundreds = n / 100; // check for how many hundreds
    int hndrd_remainder = n % 100; // used when the there is a number above or equal to 20 over a hundred
    int hundreds_tens = hndrd_remainder / 10; // used to determine the tens above one hundred
    int hndrd_remainder_remainder = hndrd_remainder % 10; // used to determine the number from 1 to 9 above one hundred and in the tens above 20 in the hundreds

/* - [ ANOTHER OPTION]

    int exact_hndrd = n - hndrd_remainder; // used to determine the exact hundred , one hundred, two hundreds, three hundreds etc

    // used when the number above a hundred is from 1 to 9, 102; 505, 203, 809, etc
    int hndrd_one = exact_hndrd+ 1;
    int hndrd_nine = exact_hndrd + 9;

    // used when the number above a hundred is from 10 to 19, 110; 515, 213, 819, etc
    int hndrd_eleven = exact_hndrd+ 10;
    int hndrd_nineteen = exact_hndrd + 19;

*/

    if ( n >= 100 && n <= 999)
    {
        switch (hundreds)
        {
        case 1:
            cout << "one hundred " ;
            break;
        case 2:
            cout << "two hundreds " ;
            break;
        case 3:
            cout << "three hundreds " ;
            break;
        case 4:
            cout << "four  hundreds " ;
            break;
        case 5:
            cout << "five hundreds " ;
            break;
        case 6:
            cout << "six hundreds " ;
            break;
        case 7:
            cout << "seven hundreds " ;
            break;
        case 8:
            cout << "eight hundreds " ;
            break;
        case 9:
            cout << "nine hundreds " ;
            break;
        }

        if (hndrd_remainder >= 20)
        {
            switch (hundreds_tens)
            {
            case 2:
                cout << "twenty ";
                break;
            case 3:
                cout << "thirty ";
                break;
            case 4:
                cout << "forty ";
                break;
            case 5:
                cout << "fifty ";
                break;
            case 6:
                cout << "sixty ";
                break;
            case 7:
                cout << "seventy ";
                break;
            case 8:
                cout << "eighty ";
                break;
            case 9:
                cout << "ninety ";
                break;
            }

            switch (hndrd_remainder_remainder)
            {
            case 1:
                cout << "one  " ;
                break;
            case 2:
                cout << "two  " ;
                break;
            case 3:
                cout << "three " ;
                break;
            case 4:
                cout << "four " ;
                break;
            case 5:
                cout << "five  " ;
                break;
            case 6:
                cout << "six  " ;
                break;
            case 7:
                cout << "seven  " ;
                break;
            case 8:
                cout << "eight  " ;
                break;
            case 9:
                cout << "nine  " ;
                break;
            }
        }

        if ( hndrd_remainder >= 1 &&  hndrd_remainder <= 9)
        {
            switch (hndrd_remainder_remainder)
            {
            case 1:
                cout << "one  " ;
                break;
            case 2:
                cout << "two  " ;
                break;
            case 3:
                cout << "three " ;
                break;
            case 4:
                cout << "four  " ;
                break;
            case 5:
                cout << "five  " ;
                break;
            case 6:
                cout << "six  " ;
                break;
            case 7:
                cout << "seven  " ;
                break;
            case 8:
                cout << "eight  " ;
                break;
            case 9:
                cout << "nine  " ;
                break;
            }
        }

        if ( hndrd_remainder >= 10 &&  hndrd_remainder <= 19 )
        {
            switch ( tens )
            {
            case 0:
                cout << "ten";
                break;
            case 1:
                cout << "eleven  " ;
                break;
            case 2:
                cout << "twelve  " ;
                break;
            case 3:
                cout << "thirteen " ;
                break;
            case 4:
                cout << "fourteen  " ;
                break;
            case 5:
                cout << "fifteen  " ;
                break;
            case 6:
                cout << "sixteen  " ;
                break;
            case 7:
                cout << "seventeen  " ;
                break;
            case 8:
                cout << "eighteen  " ;
                break;
            case 9:
                cout << "nineteen  " ;
                break;
            }
        }
    }

    else  if ( n >= 10 && n < 20)
    {
        switch ( tens )
        {
        case 0:
            cout << "ten";
            break;
        case 1:
            cout << "eleven  " ;
            break;
        case 2:
            cout << "twelve  " ;
            break;
        case 3:
            cout << "thirteen " ;
            break;
        case 4:
            cout << "fourteen  " ;
            break;
        case 5:
            cout << "fifteen  " ;
            break;
        case 6:
            cout << "sixteen  " ;
            break;
        case 7:
            cout << "seventeen  " ;
            break;
        case 8:
            cout << "eighteen  " ;
            break;
        case 9:
            cout << "nineteen  " ;
            break;

        }
    }
    else
    {
        switch (tens_digits)
        {
        case 2:
            cout << "twenty ";
            break;
        case 3:
            cout << "thirty ";
            break;
        case 4:
            cout << "forty ";
            break;
        case 5:
            cout << "fifty ";
            break;
        case 6:
            cout << "sixty ";
            break;
        case 7:
            cout << "seventy ";
            break;
        case 8:
            cout << "eighty ";
            break;
        case 9:
            cout << "ninety ";
            break;
        }

        switch (units_digits)
        {
        case 1:
            cout << "one  " ;
            break;
        case 2:
            cout << "two  " ;
            break;
        case 3:
            cout << "three " ;
            break;
        case 4:
            cout << "four  " ;
            break;
        case 5:
            cout << "five  " ;
            break;
        case 6:
            cout << "six  " ;
            break;
        case 7:
            cout << "seven  " ;
            break;
        case 8:
            cout << "eight  " ;
            break;
        case 9:
            cout << "nine  " ;
            break;
        }
    }
    cout << endl;

    return 0;
}

