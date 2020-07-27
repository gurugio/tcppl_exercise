#include <iostream>
#include <cstring>


using namespace std;

struct Node
{
	char* message;
	struct Node* left;
	struct Node* right;
};


void tree_add(Node* root, char* m)
{
	if (root == nullptr)
		throw runtime_error{"tree_add: null"};

	if (strcmp(root->message, m) < 0) {
		if (root->left == nullptr) {
			root->left = new Node{m, nullptr, nullptr};
		} else {
			tree_add(root->left, m);
		}
	} else if (strcmp(root->message, m) > 0) {
		if (root->right == nullptr) {
			root->right = new Node{m, nullptr, nullptr};
		} else {
			tree_add(root->right, m);
		}
	} else {
		throw runtime_error{"tree_add: duplicated"};
	}
}

Node* find(Node* root, char* m)
{
	if (root == nullptr)
		throw runtime_error{"find: failed"};

	if (strcmp(root->message, m) < 0) {
		return find(root->left, m);
	} else if (strcmp(root->message, m) > 0) {
		return find(root->right, m);
	}
	return root;
}

void print_tree(Node *root)
{
	cout << "Node: " << root->message;
	if (root->left != nullptr)
		cout << "[" << root->left->message << "]";
	else
		cout << "[]";
	if (root->right != nullptr)
		cout << "[" << root->right->message << "]";
	else
		cout << "[]";
	cout << endl;

	if (root->left != nullptr)
		print_tree(root->left);
	if (root->right != nullptr)
		print_tree(root->right);
}

int main(void)
{
	Node root{"ddd", nullptr, nullptr};

	tree_add(&root, "fff");
	tree_add(&root, "bbb");
	tree_add(&root, "eee");
	tree_add(&root, "ggg");
	tree_add(&root, "ccc");
	tree_add(&root, "aaa");
	tree_add(&root, "hello");
	print_tree(&root);

	Node* found = find(&root, "hello");
	cout << found->message << endl;
	found = find(&root, "eee");
	cout << found->message << endl;

	found = find(&root, "hello!!");
	cout << found->message << endl;
}

