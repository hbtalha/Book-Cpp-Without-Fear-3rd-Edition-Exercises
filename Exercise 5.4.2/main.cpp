#include <iostream>

using namespace std;

int main()
{
    int a, b;

    cout << "Enter the first number: ";
    cin >> a;

    cout << "Enter the second number: ";
    cin >> b;

    while (true)
    {
        if (b == 0)
        {
            cout << "GCF = " << a;
            break;
        }
        else
        {
            int temp = b;
            b = a % b;
            a = temp;
        }
    }
    return 0;
}
