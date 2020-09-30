// Write and test a get_size function for the Btree class. You should be able to do this by adding another private data member called nSize.

#include <iostream>

using namespace std;

class Bnode
{
    string val;
    Bnode* pLeft;
    Bnode* pRight;

public:
    Bnode(string s)
    {
        val = s;

        pLeft = pRight = nullptr;
    }

public:
    void insert_left(Bnode* p)
    {
        pLeft = p;
    }

    void insert_right(Bnode * p)
    {
        pRight = p;
    }

    Bnode* get_left()
    {
        return pLeft;
    }

    Bnode* get_right()
    {
        return pRight;
    }

    string get_val()
    {
        return val;
    }
};

class Btree
{
    Bnode* root;
    Bnode*insert_at_sub(string s, Bnode* p);
    void print_sub(Bnode* p);
    int nSize = 0;

public:
    Btree ()
    {
        root = nullptr;
    }
    void insert(string s);

    void print()
    {
        print_sub(root);
    }

    int get_size()
    {
        return nSize;
    }
};

void Btree::insert(string s)
{
    ++nSize;

    if (root == nullptr)
    {
        root = new Bnode(s) ;
    }
    else
        insert_at_sub(s, root);
}


Bnode* Btree::insert_at_sub(string s, Bnode* p)
{
    if (s < p->get_val())
    {
        if (p->get_left() == nullptr)
        {
            Bnode* newp = new Bnode(s);
            p->insert_left(newp);
        }
        else
        {
            insert_at_sub(s, p->get_left());
        }
    }
    else  if (s > p->get_val())
    {
        if (p->get_right() == nullptr)
        {
            Bnode* newp = new Bnode(s);
            p->insert_right(newp);
        }
        else
        {
            insert_at_sub(s, p->get_right());
        }
    }
}

void Btree::print_sub(Bnode *p)
{
    if(p)
    {
        print_sub(p->get_left());
        cout << p->get_val() << endl;
        print_sub(p->get_right());
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

   // my_tree.print();

   cout << my_tree.get_size() << endl;

    return 0;
}
