#include <iostream>

using namespace std;

int main()
{
    int n[7];
    int sum = 0;

    for (int i = 0; i < 7; ++i)
    {
        cout << "Enter Number " << i +1 << ": ";
        cin >> n[i];
    }
    cout << endl;

    for (int i = 0; i < 7; ++i)
    {
        cout << n[i] << " ";

        sum += n[i];
    }

    cout << endl << endl << "Sum = " << sum << endl;

    return 0;
}
