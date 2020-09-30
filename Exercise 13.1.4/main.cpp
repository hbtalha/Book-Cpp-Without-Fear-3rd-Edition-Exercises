#include <iostream>
#include <list>

using namespace std;

int main()
{
    double s;
    list <double> ls;
    list <double>::iterator iter;

    while (true)
    {
        cout << "Insert into the list: ";
        cin >> s;

        if (s == 0)
            break;

        for (iter = ls.begin(); iter != ls.end() && s > *iter;)
        {
            ++iter;
        }

        ls.insert(iter, s);
    }

    double counter = 0, highest, lowest;

    for (iter = ls.begin(); iter != ls.end(); ++iter)
    {
        counter += *iter;
    }

    for (iter = ls.begin(); iter != ls.end(); ++iter)
   {
       double a = 0;

        if ( *iter > a)
        {
            highest = *iter;

             a = *iter;
        }
    }

    for (iter = ls.begin(); iter != ls.end(); ++iter)
    {
        double n = 0;

        if ( n < *iter)
        {
             lowest = *iter;
        }
    }

    cout << endl << "Lowest number: " << lowest << endl;

    cout << "Highest number: " << highest << endl;

    cout << endl << "Average: " << counter / ls.size() << endl;

    cout << endl << "Size of the list: " << ls.size() << endl << endl;;



    return 0;
}
