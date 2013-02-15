#include <iostream>
#include <string>
#include <cstring>

using namespace std;

namespace string_dlist{
    struct node {
        string *msg;
        node *next;
        node *prev;
    };

    node *create(void); // create dlist-head
    void destroy(node *head); // destroy dlist
    void insert(node *head, node *node);
    void extract(node *node);
    void sort(node *head);
    void print(node *head);
}

using namespace string_dlist;

node *string_dlist::create(void)
{
    node *h = new node;

    h->msg = new string("head");
    h->next = h->prev = h;

    return h;
}

void string_dlist::insert(node *head, node *new_node)
{
    new_node->next = head->next;
    head->next->prev = new_node;
    
    head->next = new_node;
    new_node->prev = head;
}

void string_dlist::extract(node *new_node)
{
    new_node->next->prev = new_node->prev;
    new_node->prev->next = new_node->next;
}

void string_dlist::print(node *head)
{
    for (node *p = head->next; p != head; p = p->next)
        cout << *(p->msg) << endl;
}

int cmp1(const node *p, const node *q)
{
    return strcmp(p->msg->c_str(), q->msg->c_str());
}

// end는 검사하지 않는다
node *find_max(node *start, node *end)
{
    node *max = start;
    node *p;
    for (p = start; p != end; p = p->next)
    {
        cout << "cur->" << *(p->msg) << endl;
        cout << cmp1(max, p) << endl;
        if (cmp1(max, p) < 0)
        {
            max = p;
        }
    }

    cout << "max->" << *(max->msg) << endl;
    return max;
}


void string_dlist::sort(node *head)
{
    node *t;
    node *p = head->next;
    
    while (p != head)
    {
        t = find_max(p, head);
        if (t != p)
        {
            extract(t);
            insert(head, t);
        }
        else
        {
            node *q = p->next;
            extract(p);
            insert(head, p);

            p = q;
        }
    }

}


int main(int argc, char* argv[])
{
    node *h;
    node data[9];

    h = create();
    
    for (int i = 0; i < sizeof(data)/sizeof(node); i++)
    {
        char buf = 'A' + i;
        data[i].msg = new string(&buf);
        data[i].next = data[i].prev = 0;

        insert(h, &data[i]);
    }

    print(h);

    sort(h);
    print(h);

}

