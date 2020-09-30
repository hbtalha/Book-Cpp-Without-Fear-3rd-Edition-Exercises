// Revise the program so that it keeps prompting the user for another line of input to calculate until the user enters an empty line by just pressing ENTER.
// That is to say, continue the cycle of prompting for input, interpreting it as RPN, and printing the answer, until the user wants to quit.
// Don¡¯t quit after one go-round. (By the way, to make sure this program works correctly every time, you ought to clear the stack before beginning a new operation.)

#include <iostream>
#include <cstring>
#include <stack>
#include <stdlib.h>

#define MAX 100

using namespace std;

int main()
{
    char input[MAX], *p;
    stack <double> _stack;
    int c;
    double a, b, n;

    while (true)
    {
        int i;
        while (i < _stack.size())
        {
            _stack.pop();

            ++i;
        }

        cout << endl << "Enter RPN expression: ";
        cin.getline(input, MAX);

        if (input[0] == 0)
            break;

        p = strtok(input, " ");

        while (p)
        {
            c = p[0];

            if(c == '+' || c == '*' || c == '/' || c == '-')
            {
                if (_stack.size() < 2)
                {
                    cout << endl << "Error found...";
                    return - 1;
                }

                b = _stack.top();
                _stack.pop();
                a = _stack.top();
                _stack.pop();

                switch (c)
                {
                case '+':
                    n = a + b;
                    break;
                case '*':
                    n = a * b;
                    break;
                case '/':
                    n = a / b;
                    break;
                case '-':
                    n = a - b;
                    break;
                }
                _stack.push(n);
            }
            else
            {
                _stack.push(atof(p));
            }

            p = strtok(nullptr, " ");
        }

        cout << "The result is " << _stack.top() << endl;
    }


    return 0;
}





