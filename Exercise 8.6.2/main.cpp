#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

bool get_num(double *p)
{
    string input_line;

    cout << "Enter a number: ";
    getline(cin, input_line);

    if (input_line.size() == 1)
    {
        return false;
    }

    *p = atof(input_line.c_str());
}

int main()
{
    double sum = 0, n = 0;

    while (get_num(&n))
    {
        sum+=n;
    }

    cout << "\nThe sum is " << sum << endl;
    return 0;
}
