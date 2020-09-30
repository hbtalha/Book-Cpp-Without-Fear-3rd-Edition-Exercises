// Revise the example so that it reports the size of the list.
// You can write code to count the number of insertions, or you can simply call the template¡¯s size function, which has the syntax list.size().

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

    cout << endl << "Size of the list: " << LS.size() << endl << endl;;

    for (iter = LS.begin(); iter != LS.end(); ++iter)
    {
        cout << *iter << endl;
    }

    return 0;
}

