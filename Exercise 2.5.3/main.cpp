#include <iostream>

using namespace std;

int main ()
{
    int total;
    int n;
    int e;
do{
    cout << "\nPick Up A Starting Total: ";
    cin >> total;

    while (total <= 0)
    {
        cout << "\nOops! Total Can't Be Less Than 0!!\nRe-enter:";
        cin >> total;

        //cout << endl;
    }

    cout << endl;


        while (true)
        {
            if (total % 3 == 2)
            {
                total = total - 2;
                cout << "I Am Subtracting... 2" << endl;
                cout << "New Total: " << total << endl;
            }
            else
            {
                total --;
                cout << "I Am Subtracting... 1" << endl;
                cout << "New Total: " << total << endl;
            }

            if (total <= 0 )
            {
                cout <<"\aI Win!!" << endl;
                break;
            }

            cout << "Enter Your Subtracting Number (1 or 2): ";
            cin >> n;

            while (n < 1 || n > 2)
            {
                cout << "\nThe number must be 1 or 2: "
                     << "\nRe-enter: ";
                cin >> n;
            }


            //cout << endl;

            total-=n;

            cout << "New Total: " << total << endl;

            if (total <= 0 )
            {
                cout <<"\a\nYou Win!!" << endl;
                break;
            }


        }
        cout << "\nEnter 1 To Exit, Other To continue:";
        cin >> e;

        if (e == 1)
        {
            break;
        }
        else{}
    }while (true);

    return 0;
}
