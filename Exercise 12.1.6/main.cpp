#include <iostream>

using namespace std;

class Bnode
{
public:
    string val;
    Bnode *pLeft, *pRight;

    Bnode( string s)
    {
        val = s;

        pLeft = pRight = nullptr;
    }
};

class Btree
{
    Bnode *root;
    Bnode *insert_at_sub(string s, Bnode* p);
    void print_sub(Bnode* p);
    int nSize = 0;

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

    int get_size()
    {
        return nSize;
    }

    int *ps = &nSize;

    void delete_node()
    {
        deleter(root);
    }

    void deleter(Bnode* p);
};

Bnode* Btree::insert_at_sub(string s, Bnode* p)
{
    if (!p)
    {
        ++(*ps);

        return new Bnode(s);
    }
    else if (p)
    {
        if (s < p->val)
        {
            p->pLeft = insert_at_sub(s, p->pLeft);
        }
        if (s > p->val)
        {
            p->pRight = insert_at_sub(s, p->pRight);
        }
    }

    return p;
}

void Btree::print_sub(Bnode *p)
{
    if (p)
    {
        print_sub(p->pLeft);
        cout << p->val << endl;
        print_sub(p->pRight);
    }
}

void Btree::deleter(Bnode* p)
{
    if (p)
    {
        deleter(p->pLeft);
        delete  p;
        deleter(p->pRight);
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

    my_tree.delete_node();

    cout << my_tree.get_size();

    return 0;
}
