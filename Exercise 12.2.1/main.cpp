// Prompt the user for how many rings to use in the starting position.
// This number should be no more than MAX_LEVELS (which we set to 10, largely because of screen-space considerations).
// Then repeat; if the user enters 0, then end the program; otherwise, continue with a new session. With this version,
// the use of the populate and clear member functions becomes evident. You need to be able to reset the initial state.

#include <iostream>
#include <cstdlib>

#define max_levels 10

using namespace std;

class Cstack
{
public:
    int rings[max_levels];
    int tos;                          // top of stack
    void populate(int size);
    void clear (int size);
    void push (int n);
    int pop (void);

} stacks[3];

void Cstack::populate(int size)
{
    for (int i = 0; i < size; i++)
    {
        rings[i] = i + 1;
    }

    tos = -1;
}

void Cstack::clear(int size)
{
    for (int i = 0; i < size; ++i)
    {
        rings[i] = 0;
    }
    tos = size - 1;
}

void Cstack::push(int n)
{
    rings[tos--] = n;
}

int Cstack::pop(void)
{
    int n = rings[++tos];

    rings[tos] = 0;

    return n;
}

void move_stacks (int n, int src, int dest, int other);
void move_a_ring(int src, int dest);
void print_stacks(void);
void pr_chars(int ch, int n);
int stack_size = 0;

void input_check (int &n)
{
    string input;

    getline(cin, input);

    while (input.size() == 0)
    {
        system("cls");
        cout << "Enter the number of rings: ";
        getline(cin, input);
    }

    for (int i = 0; i < input.size(); ++i)
    {
        if (!isdigit(input[i]))
        {
            system("cls");
            cout << "\nNumbers Only! \nRe-enter:";
            getline(cin, input);

            while (input.size() == 0)
            {
                system("cls");
                cout << "\nNumbers Only! \nRe-enter:";
                getline(cin, input);
            }

            i = -1;
        }
    }

    n = atoi  (input.c_str());

    while (n > max_levels)
    {
        system("cls");
        cout << "\nCan not be larger than 10! \nRe-enter: ";
        getline(cin, input);

        while (input.size() == 0)
        {
            system("cls");
            cout << "\nCan not be larger than 10! \nRe-enter: ";
            getline(cin, input);
        }

        for (int i = 0; i < input.size(); ++i)
        {
            if (!isdigit(input[i]))
            {
                system("cls");
                cout << "\nNumbers Only! \nRe-enter:";
                getline(cin, input);

                while (input.size() == 0)
                {
                    system("cls");
                    cout << "\nNumbers Only! \nRe-enter:";
                    getline(cin, input);
                }

                i = -1;
            }
        }

        n = atoi  (input.c_str());
    }

    n = atoi  (input.c_str());
}


int main()
{
    int opt;

    do
    {
        cout << "Enter the number of rings: ";
        input_check(stack_size);

        cout << endl << endl;

        stacks[0].populate(stack_size);
        stacks[1].clear(stack_size);
        stacks[2].clear(stack_size);
        print_stacks();
        move_stacks(stack_size, 0, 2, 1);

        cout << "Enter 0 to end the program, other to continue: ";
        cin >> opt;
    } while(opt != 0);

    return 0;
}

void move_stacks (int n, int src, int dest, int other)
{
    if (n == 1)
    {
        move_a_ring(src, dest);
    }
    else
    {
        move_stacks(n-1, src, other, dest);
        move_a_ring(src, dest);
        move_stacks(n-1, other, dest, src);
    }
}

void move_a_ring(int src, int dest)
{
    int n = stacks[src].pop();
    stacks[dest].push(n);
    print_stacks();
}

void print_stacks(void)
{
    int n = 0;

    for (int i = 0; i < stack_size; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            n = stacks[j].rings[i];
            pr_chars(' ', 12 - n);
            pr_chars('*', 2 * n);
            pr_chars(' ', 12 - n);
        }

        cout << endl;
    }

    cout << "---------------------------------------------------------------------------------------------------------------------" << endl;

    //cin.get();

}

void pr_chars(int ch, int n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << (char) ch;
    }
}
