#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * TN implements "cout << ", ==, !=, <, >
 */

template <typename TN>
class Intset
{
public:
	Intset() {}
	Intset(Intset& rhs) {
		store = rhs.store;
	}

	/* set_union returns new object.
	 * move-constructor is necessary for assignment: Intset setc = seta.set_union(setb);
	 */
	Intset(Intset&& rhs) {
		store = move(rhs.store);
	}
	
	// union->keyword, intersection, difference
	Intset set_union(const Intset& rhs) {
		Intset tmpset = *this;
		Intset newset;
		int new_index = 0;

		for (auto x: rhs.store)
			tmpset.add(x);
		
		// sort and remove duplicated numbers
		sort(tmpset.store.begin(), tmpset.store.end());

		newset.store.push_back(tmpset.store[0]);
		
		for (int i = 1; i < tmpset.store.size(); i++) {
			if (tmpset.store[i] != newset.store[new_index]) { // only equal
				newset.store.push_back(tmpset.store[i]);
				new_index++;
			}
		}
		return newset;
	}
	
	Intset operator+(const Intset& rhs) {
		return this->set_union(rhs);
	}

	Intset set_intersect(const Intset& rhs) {
		Intset tmpset;

		for (auto x: rhs.store) {
			int i;
			for (i = 0; i < this->store.size(); i++) {
				if (x == this->store[i])
					break;
			}
			if (i != this->store.size())
				tmpset.add(x);
		}
		return tmpset;
	}

	Intset operator*(const Intset& rhs) {
		return this->set_intersect(rhs);
	}
	
	Intset set_differ(const Intset& rhs) {
		Intset tmpset;

		for (auto x: store) {
			int i;
			for (i = 0; i < rhs.store.size(); i++) {
				if (x == rhs.store[i])
					break;
			}
			if (i == rhs.store.size())
				tmpset.add(x);
		}
		
		return tmpset;
	}

	Intset operator-(const Intset& rhs) {
		return this->set_differ(rhs);
	}

	int add(TN n) {
		store.push_back(n);
		return store.size();
	}

	void print(void) {
		vector<TN> tmpstore = store;

		// remove duplicated elements
		sort(tmpstore.begin(), tmpstore.end());
		store.clear();

		int new_index = 0;
		store.push_back(tmpstore[0]);
		for (int i = 1; i < tmpstore.size(); i++) {
			if (tmpstore[i] != store[new_index]) {
				store.push_back(tmpstore[i]);
				new_index++;
			}
		}

		for (auto x: store)
			cout << x << endl;
	}
private:
	vector<TN> store;
};


// cout, ==, !=, <, >
class Node {
public:
	Node(int n, string s): data{n}, msg{s} {}

	bool operator==(const Node& rhs) const {
		return data == rhs.data;
	}

	bool operator!=(const Node& rhs) const {
		return data != rhs.data;
	}

	bool operator<(const Node& rhs) const {
		return data < rhs.data;
	}

	bool operator>(const Node& rhs) const {
		return data > rhs.data;
	}

	friend ostream& operator<<(ostream& os, const Node& n);

private:
	int data;
	string msg;
};

ostream& operator<<(ostream& os, const Node& n)
{
	os << n.data << ":" << n.msg;
	return os;
}

int main(void)
{
	Intset<int> seta;
	Intset<int> setb;
	
	seta.add(1);
	seta.add(1);
	seta.add(2);
	seta.add(3);
	seta.add(11);
	cout << "A:";
	seta.print();
	cout << endl;
	
	setb.add(2);
	setb.add(3);
	setb.add(3);
	setb.add(3);
	setb.add(4);
	setb.add(5);
	setb.add(5);
	setb.add(5);
	cout << "B:";
	setb.print();
	cout << endl;
	
	Intset<int> setc = seta + setb; //seta.set_union(setb);
	cout << "sum:";
	setc.print();
	cout << endl;

	Intset<int> setd = seta * setb; //seta.set_intersect(setb);
	cout << "inter:";
	setd.print();
	cout << endl;
	
	Intset<int> sete = seta - setb; //seta.set_differ(setb);
	cout << "differ:";
	sete.print();
	cout << endl;


	Intset<Node> nodeset_a;
	Intset<Node> nodeset_b;

	nodeset_a.add(Node{1, "aaa"});
	nodeset_a.add(Node{1, "aaa"});
	nodeset_a.add(Node{2, "bbb"});
	nodeset_a.add(Node{3, "ccc"});
	nodeset_a.add(Node{11, "kkk"});
	nodeset_a.print();

	nodeset_b.add(Node{2, "b"});
	nodeset_b.add(Node{2, "b"});
	nodeset_b.add(Node{2, "b"});
	nodeset_b.add(Node{3, "c"});
	nodeset_b.add(Node{4, "d"});
	nodeset_b.add(Node{4, "d"});
	nodeset_b.add(Node{4, "d"});
	nodeset_b.add(Node{4, "d"});
	nodeset_b.add(Node{5, "e"});
	nodeset_b.print();

	Intset<Node> nodeset_c = nodeset_a + nodeset_b;
	cout << "sum:";
	nodeset_c.print();
	cout << endl;
	Intset<Node> nodeset_d = nodeset_a * nodeset_b;
	cout << "inter:";
	nodeset_d.print();
	cout << endl;
	Intset<Node> nodeset_e = nodeset_a.set_differ(nodeset_b);//nodeset_a - nodeset_b;
	cout << "differ:";
	nodeset_e.print();
	cout << endl;
}
