#include<iostream>
#include <fstream>
#include <cstring>

using namespace std;



struct Tnode {
    string word;
    int count;
    Tnode *left;
    Tnode *right;
};

Tnode *root;

int cmp_string(const void *p, const void *q)
{
    return strcmp(static_cast<const string *>(p)->c_str(),
                  static_cast<const string *>(q)->c_str());
}

int cmp_node(const Tnode *a, const Tnode *b)
{
    return cmp_string(static_cast<const void *>(&(a->word)),
                      static_cast<const void *>(&(b->word)));
}


int insert_node(Tnode *node)
{
    if (root == NULL)
    {
        root = node;
        return 0;
    }
    else
    {
        Tnode *cur = root;

        while (1)
        {
            cout << "cur->" << cur->word << endl;

            if (cmp_node(node, cur) == 0)
            {
                cur->count++;
                break;
            }
            else if (cmp_node(node, cur) < 0)
            {
                cout << "left" << endl;
                if (cur->left == NULL)
                {
                    cur->left = node;
                    break;
                }
                else
                {
                    cur = cur->left;
                }
            }
            else
            {
                cout << "right" << endl;
                if (cur->right == NULL)
                {
                    cur->right = node;
                    break;
                }
                else
                {
                    cur = cur->right;
                }
            }
        }
    }
}

void print_tree(Tnode *tree)
{
    if (tree != NULL)
    {
        print_tree(tree->left);
        cout << tree->word << "X" << tree->count << endl;
        print_tree(tree->right);
    }
}

int main(void)
{
    Tnode node_data[] = {
        string("ddd"), 1, NULL, NULL,
        string("ccc"), 1, NULL, NULL,
        string("aaa"), 1, NULL, NULL,
        string("eee"), 1, NULL, NULL,
        string("fff"), 1, NULL, NULL,
        string("ggg"), 1, NULL, NULL
    };

    for (int i = 0; i < sizeof(node_data)/sizeof(Tnode); i++)
        insert_node(&node_data[i]);

    print_tree(root);

    for (int i = 0; i < sizeof(node_data)/sizeof(Tnode); i++)
        insert_node(&node_data[i]);

    print_tree(root);
    
}

