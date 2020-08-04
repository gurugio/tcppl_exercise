#include <iostream>
#include <cassert>

using namespace std;

class Table {
public:

	/*
	 * make my own map with iterator
	 */

	class iterator {
	public:
		iterator(pair<string, int> *p): ptr{p} {}

		pair<string, int>& operator*() const {
			return *ptr;
		}

		iterator operator++() {
			ptr++;
			return *this;
		}

		bool operator!=(const iterator& other) const {
			return ptr != other.ptr;
		}
		bool operator==(const iterator& other) const {
			return ptr == other.ptr;
		};

	private:
		pair<string, int> *ptr;
	};

	Table();
	~Table();

	void insert(pair<string, int> elem);
	int& operator[](string key);
	void print(void) const;
	pair<string, int> find(string key);
	iterator begin() const {
		return iterator(array);
	}
	iterator end() const {
		return iterator(array + size);
	}

private:
	pair<string, int> *array;
	int size; // where the new element is stored
	int capacity; // allocation size
};


Table::Table()
{
	// not implement resizing, error handling and etc to make it simple
	array = new pair<string, int>[100];
	capacity = 100;
	size = 0;
}

Table::~Table()
{
	delete[] array;
}

void Table::insert(pair<string, int> elem)
{
    if (size == capacity)
        throw runtime_error("Table full");

	array[size] = elem;
	size++;
}

int& Table::operator[](string key)
{
	int i;
	for (i = 0; i < size; i++)
		if (array[i].first == key)
			return array[i].second;

    if (size == capacity)
        throw runtime_error("Table full");

	// not found
	array[i] = make_pair(key, 0);
	size++;
	return array[i].second;
}

pair<string, int> Table::find(string key)
{
	for (int i = 0; i < size; i++) {
		if (array[i].first == key)
			return array[i];
	}
	throw runtime_error("Not found");
}

void Table::print(void) const
{
	for (int i = 0; i < size; i++)
		cout << array[i].first << ":" << array[i].second << endl;
}

int main(void)
{
	Table lookup;

	lookup.insert(make_pair("aaa", 1));
	lookup.insert(make_pair("bbb", 1));
	lookup.insert(make_pair("ccc", 1));

	// change value
	lookup["aaa"] = 2;
	assert(lookup["aaa"] == 2);

	// add new key and value
	lookup["ddd"] = 3;
	assert(lookup["ddd"] == 3);

	for (auto it: lookup) {
		cout << it.first << ":" << it.second << endl;
	}

	try {
		cout << lookup["bbb"] << endl;
		lookup.find(string("zzz")); // exception test
	} catch (exception& e) {
		cout << "exception:" << e.what() << endl;
	}
}
