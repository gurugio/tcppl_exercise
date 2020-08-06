#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

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
			if (tmpset.store[i] != newset.store[new_index]) {
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

	int add(int n) {
		store.push_back(n);
		return store.size();
	}

	void print(void) {
		vector<int> tmpstore = store;

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
	vector<int> store;
};

int main(void)
{
	Intset seta;
	Intset setb;
	
	seta.add(1);
	seta.add(1);
	seta.add(2);
	seta.add(3);
	seta.add(11);

	setb.add(2);
	setb.add(3);
	setb.add(3);
	setb.add(3);
	setb.add(4);
	setb.add(5);
	setb.add(5);
	setb.add(5);
	
	Intset setc = seta + setb; //seta.set_union(setb);
	cout << "sum:";
	setc.print();
	cout << endl;

	Intset setd = seta * setb; //seta.set_intersect(setb);
	cout << "inter:";
	setd.print();
	cout << endl;
	
	Intset sete = seta - setb; //seta.set_differ(setb);
	cout << "differ:";
	sete.print();
	cout << endl;
}
