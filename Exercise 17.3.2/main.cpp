// Initialize an array to {1, 2, 3, 4, 5}. Then, use range-based for to double each element of the array.
// Print out the results to confirm that the statements worked as expected. (Hint: Don¡¯t forget to include the ampersand (&).)

#include <iostream>

using namespace std;

int main()
{
    int arr[5];
    int j = 0;

    for (int &i : arr)
    {
        i = ++j;
    }

    for (int &i : arr)
    {
        i *= 2;
    }

    for (int i : arr)
    {
        cout << i << endl;
    }


    return 0;
}
