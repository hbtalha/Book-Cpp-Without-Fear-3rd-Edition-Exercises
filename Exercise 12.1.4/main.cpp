/*
Exercise 12.1.4. Write and test a find function as in Exercise 12.1.3, but this time
use an iterative solution. Remember that an iterative solution is one that relies
on loops and does not call itself.
*/

#include <iostream>

using namespace std;

class Bnode
{
public:
    string val;
    Bnode* pRight;
    Bnode* pLeft;

    Bnode( string s)
    {
        val = s;

        pLeft = pRight = nullptr;
    }
};

class Btree
{
    Bnode* root;
    Bnode* insert_at_sub(string s, Bnode* p);
    void print_sub(Bnode* p);
    bool seek_sub( string s, Bnode* p);

public:
    Btree ()
    {
        root = nullptr;
    }

    void insert(string s)
    {
        root = insert_at_sub(s, root);
    }

    void print()
    {
        print_sub(root);
    }

    void seek(string s);
};

Bnode* Btree::insert_at_sub(string s, Bnode* p)
{
    if (!p)
    {
        return new Bnode(s);
    }
    else if ( s < p->val)
    {
        p->pLeft = insert_at_sub(s, p->pLeft);
    }
    else if ( s > p->val)
    {
        p->pRight = insert_at_sub(s, p->pRight);
    }

    return p;
}

void Btree::print_sub(Bnode* p)
{
    if (p)
    {
        print_sub(p->pLeft);
        cout << p->val << endl;
        print_sub(p->pRight);
    }
}

void Btree::seek(string s)
{
    bool found =seek_sub(s, root);

    if (found == true)
        cout << endl << "found" << endl;
    else
        cout << endl << "not found" << endl;
}

bool Btree::seek_sub(string s, Bnode* p)
{
    while (p)
    {
        if (s < p->val)
            p = p->pLeft;
        else if (s > p->val)
            p = p->pRight;
        else
            return true;
    }

    return false;
}

int main()
{
    Btree my_tree;

    my_tree.insert("helder");
    my_tree.insert("edilson");
    my_tree.insert("gelson");
    my_tree.insert("wilson");
    my_tree.insert("hermes");
    my_tree.insert("decio");

    my_tree.seek("gelson");

    return 0;
}
