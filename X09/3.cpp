#include <iostream>

using namespace std;

struct node {
	struct node *next;
	int data;
};

int main(void)
{
	struct node n0 = {nullptr, 0};
	struct node n1 = {nullptr, 1};
	struct node n2 = {nullptr, 2};

	n0.next = &n1;
	n1.next = &n2;

	struct node *head = &n0;
	while (head) {
		cout << head->data << endl;
		head = head->next;
	}
}
