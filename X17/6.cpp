#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;


class Tree {
public:

	class Tnode {
	public:
		Tnode(string s ="", int c =0, Tnode* l =nullptr, Tnode* r =nullptr):
			word{s}, count{c}, left{l}, right{r} {}

		// compare or operator<
		// is_empty
		bool is_empty(void) {
			return word.size() == 0;
		}

		bool operator<(string w) {
			return word < w;
		}

		bool operator>(string w) {
			return word > w;
		}

		bool operator==(string w) {
			return word == w;
		}

		void print(void) {
			if (left != nullptr)
				left->print();

			cout << word << ":" << count;
			if (left != nullptr)
				cout << "  left=" << left->word;
			if (right != nullptr)
				cout << "  right=" << right->word;
			cout << endl;

			if (right != nullptr)
				right->print();
		}
		
		string word;
		int count;
		Tnode* left;
		Tnode* right;
	};

	Tree(Tnode* node =nullptr);
	void add(string word);
	void print(void);
	
	//private:
	Tnode* root;
};

Tree::Tree(Tnode* node)
{
	// if (node == nullptr)
	// 	root = new Tnode {"", 0, nullptr, nullptr};
	// else
	// 	root = node;
	root = node;
}

void Tree::add(string word)
{
	Tnode* cur;

	if (root == nullptr) {
		root = new Tnode {word, 1, nullptr, nullptr};
		return;
	}

	cur = root;
	
	while (cur != nullptr) {
		if (*cur > word) {
			if (cur->left == nullptr) {
				cur->left = new Tnode {word, 1, nullptr, nullptr};
				return;
			} else {
				cur = cur->left;
			}
		} else if (*cur == word) {
			cur->count++;
			return;
		} else {
			if (cur->right == nullptr) {
				cur->right = new Tnode {word, 1, nullptr, nullptr};
				return;
			} else {
				cur = cur->right;
			}
		}
	}
	return;
}

void Tree::print(void)
{
	root->print();
}

int main(void)
{
	Tree tr;

	srand(time(NULL));	

	for (int i = 0; i < 50; i++) {
		char ch = 'a' + rand() % 20;
		string s {ch};
		cout << "add:" << s << endl;
		tr.add(s);
	}

	/*
	 * The order of the result should be sorted because it prints tree nodes in-order.
	 */
	tr.print();
}
