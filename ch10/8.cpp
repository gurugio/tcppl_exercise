#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;


class Tnode {
public:
    Tnode(string word, int count)
    {
        this->word = word;
        this->count = count;
        left = right = 0;
    }
    
    ~Tnode() {}
    string &get_word() { return this->word; }
    int &get_count() { return count; }
    Tnode *get_left() { return left; }
    Tnode *get_right() { return right; }
    void set_left(Tnode *l) { this->left = l; }
    void set_right(Tnode *r) { this->right = r; }

private:
    string word;
    int count;
    Tnode *left;
    Tnode *right;
};


class TnodeTree {
public:
    TnodeTree() { root = 0; }
    
    int insert_node(Tnode *node);
    int cmp_node(Tnode *, Tnode *);
    void print_tree(void) { print_tree_body(root); }
    void print_tree_body(Tnode *);
private:
    Tnode *root;    
};




// int cmp_string(const void *p, const void *q)
// {
//     return strcmp(static_cast<const string *>(p)->c_str(),
//                   static_cast<const string *>(q)->c_str());
// }

int TnodeTree::cmp_node(Tnode *a, Tnode *b)
{
    // return cmp_string(static_cast<const void *>(&(a->word)),
    //                   static_cast<const void *>(&(b->word)));
    return strcmp(a->get_word().c_str(),
                  b->get_word().c_str());
}


int TnodeTree::insert_node(Tnode *node)
{
    if (root == 0)
    {
        root = node;
        return 0;
    }
    else
    {
        Tnode *cur = root;

        while (1)
        {
            cout << "cur->" << cur->get_word() << endl;

            int cmp = cmp_node(node, cur);
            
            if (cmp == 0)
            {
                cur->get_count()++;
                break;
            }
            else if (cmp < 0)
            {
                cout << "left" << endl;
                if (cur->get_left() == NULL)
                {
                    cur->set_left(node);
                    break;
                }
                else
                {
                    cur = cur->get_left();
                }
            }
            else
            {
                cout << "right" << endl;
                if (cur->get_right() == NULL)
                {
                    cur->set_right(node);
                    break;
                }
                else
                {
                    cur = cur->get_right();
                }
            }
        }
    }
}

void TnodeTree::print_tree_body(Tnode *tree)
{
    if (tree != NULL)
    {
        print_tree_body(tree->get_left());
        cout << tree->get_word() << "X" << tree->get_count() << endl;
        print_tree_body(tree->get_right());
    }
}

int main(void)
{
    Tnode node1(string("ddd"), 1);
    Tnode node2(string("ccc"), 1);
    Tnode node3(string("aaa"), 1);
    Tnode node4(string("eee"), 1);
    Tnode node5(string("fff"), 1);

    TnodeTree tree;
    
    Tnode *node_data[] = {&node1, &node2, &node3, &node4, &node5};
        
    
    for (int i = 0; i < sizeof(node_data)/sizeof(Tnode *); i++)
        tree.insert_node(node_data[i]);

    tree.print_tree();

    for (int i = 0; i < sizeof(node_data)/sizeof(Tnode *); i++)
        tree.insert_node(node_data[i]);

    tree.print_tree();

    for (int i = 0; i < sizeof(node_data)/sizeof(Tnode *); i++)
        tree.insert_node(node_data[i]);

    tree.print_tree();

}

