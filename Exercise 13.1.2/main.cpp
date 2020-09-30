// Revise Example 13.1 so that it keeps a continually sorted list, but keeps it in reverse order. - not sure how to do it

#include <iostream>
#include <list>

using namespace std;

int main()
{
    string s;
    list <string> LS;
    list <string>::iterator iter;

    while (true)
    {
        cout << "Insert into the list: ";
        getline(cin, s);

        if (s.size() == 0)
            break;

        for (iter = LS.end(); iter != LS.begin() && s > *iter;)
        {
            ++iter;
        }

        LS.insert(iter, s);
    }

    LS.sort();

    cout << endl;

    for (iter = LS.begin(); iter != LS.end(); ++iter)
    {
        cout << *iter << endl;
    }

    return 0;
}
