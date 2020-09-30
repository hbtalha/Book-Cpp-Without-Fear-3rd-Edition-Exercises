#include <iostream>

using namespace std;

class Bnode
{
public:
    string val;
    Bnode* pLeft;
    Bnode* pRight;

    Bnode( string s)
    {
        val = s;

        pLeft = pRight = nullptr;
    }

    void insert_left(Bnode* p)
    {
        pLeft = p;
    }

    void insert_right(Bnode* p)
    {
        pRight = p;
    }

};

class Btree
{
    Bnode* root;
    Bnode* insert_at_sub(string s, Bnode* p);
    void print_sub(Bnode* p);

public:
    Btree()
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

};

Bnode* Btree::insert_at_sub(string s, Bnode* p)
{
    if ( !p )
        return new Bnode(s);

    Bnode *curr = p;
    Bnode * x;


    while (curr)
    {
        x = curr;

        if( s <= p->val)
        {
            curr = curr->pLeft;
        }
        else
        {
            curr = curr->pRight;
        }
    }

    Bnode *node = new Bnode(s);
    if (s <= x->val)
        x->pLeft = node;
    else
        x->pRight = node;

    return p;
}


void Btree::print_sub(Bnode *p)
{
    if(p)
    {
        print_sub(p->pLeft);
        cout << p->val << endl;
        print_sub(p->pRight);
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

    my_tree.print();

    return 0;
}
