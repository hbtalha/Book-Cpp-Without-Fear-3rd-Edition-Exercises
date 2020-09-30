/*
Exercise 12.1.5. Write and test a get_first and a get_last function for Btree; these
functions will return the alphabetically first or alphabetically last string in the
tree. You can use either a recursive or iterative approach.
*/


#include <iostream>

using namespace std;

class Bnode
{
public:
    string val;
    Bnode* pLeft;
    Bnode* pRight;


    Bnode(string s)
    {
        val = s;

        pLeft = pRight = nullptr;
    }

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
    Bnode* get_last_at_sub(Bnode *p);
    Bnode* minVal(Bnode *p);
    Bnode* maxVal(Bnode *p);
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

    string getLast()
    {
        Bnode *p = get_last_at_sub(root);

        return p->val;
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

Bnode* Btree::minVal(Bnode *p)
{
    Bnode *current = p;

    while(current && current->pLeft)
        current = current->pLeft;

    return current;
}

Bnode* Btree::maxVal(Bnode *p)
{
    Bnode *current = p;

    while(current && current->pRight)
        current = current->pRight;

    return current;
}

Bnode* Btree::get_last_at_sub(Bnode *p)
{
    Bnode *_maxLeft = maxVal(p->pLeft);
    Bnode *_maxRight = maxVal(p->pRight);

    Bnode *last = _maxRight;

    if(_maxLeft->val > _maxRight->val)
        last = _maxLeft;

    return last;
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
    my_tree.insert("zanildo");

   // my_tree.print();

   cout << endl << my_tree.getLast() << endl;

    return 0;
}
