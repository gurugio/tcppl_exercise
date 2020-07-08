#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Tnode {
	string word;
	int count;
	Tnode* left;
	Tnode* right;
};

Tnode* tree_newnode(void)
{
	Tnode* node = new Tnode;
	node->count = 0;
	node->left = node->right = nullptr;
	return node;
}

void tree_add(Tnode* root, string word)
{
	if (root->word.length() == 0) {
		root->word = word;
		root->count = 1;
		return;
	}
		
	if (root->word.compare(word) > 0) {
		if (root->left == nullptr) {
			root->left = tree_newnode();
		}
		tree_add(root->left, word);
	} else if (root->word.compare(word) == 0) {
		root->count++;
	} else {
		if (root->right == nullptr) {
			root->right = tree_newnode();
		}
		tree_add(root->right, word);
	}
}

void tree_print(Tnode* root)
{
	if (root == nullptr)
		return;
	tree_print(root->left);
	cout << root->word << ":" << root->count << endl;
	tree_print(root->right);
}

int main(void)
{
	Tnode* root = new Tnode{"", 0, nullptr, nullptr};
	
	srand(time(NULL));	

	for (int i = 0; i < 100; i++) {
		char ch = 'a' + rand() % 20;
		string s {ch};
		cout << "add:" << s << endl;
		tree_add(root, s);
	}

	tree_print(root);
}
