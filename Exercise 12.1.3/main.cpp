// Write and test a find function for the Btree class.
// This function should take a string as input, and return a Boolean value (true or false) depending on whether or not that string is in the tree.
// Write a recursive solution.

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
    void seek_sub( string s, Bnode* p);
    bool found = false;

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
    seek_sub(s, root);

    if (found == true)
        cout << endl << "found" << endl;
    else
        cout << endl << "not found" << endl;
}

void Btree::seek_sub(string s, Bnode* p)
{
    if (p)
    {
        seek_sub(s, p->pLeft);
        seek_sub(s, p->pRight);

        if (s == p->val)
        {
            found = true;
        }
    }
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

    my_tree.seek("geson");

    return 0;
}
