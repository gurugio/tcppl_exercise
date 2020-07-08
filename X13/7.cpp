#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;


using CFT = int(const void*, const void*);

struct User {
	const char* name;
	const char* id;
	int dept;
};

void ssort(void* base, size_t n, size_t sz, CFT cmp)
{
	for (int gap = n/2; 0 < gap; gap /= 2) {
		for (int i = gap; i != n; i++) {
			for (int j = i - gap; 0 <= j; j -= gap) {
				char* b = static_cast<char*>(base);
				char* pj = b + j*sz;  // &base[j]
				char* pjg = b + (j + gap) * sz; // &base[j + gap]
				if (cmp(pjg, pj) < 0) {
					for (int k = 0; k != sz; k++) {
						char temp = pj[k];
						pj[k] = pjg[k];
						pjg[k] = temp;
					}
				}
			}
		}
	}
}

int cmp1(const void* p, const void* q)
{
	int ret = strcmp(static_cast<const User*>(p)->name,
					 static_cast<const User*>(q)->name);
	cout << "comp:" << static_cast<const User*>(p)->name << ":" << static_cast<const User*>(q)->name << "=" << ret << endl;
	return ret;
}

vector<User> heads = {
	{"eeee", "dmr", 11271},
	{"dddd", "ravi", 11272},
	{"bbbb", "tgs", 11273},
	{"aaaa", "nls", 11274},
	{"e", "bwk", 11275},
};

void print_id(vector<User>& v)
{
	for (auto& x: v)
		cout << x.name << '\t' << x.id << '\t' << x.dept << endl;
}

bool usercomp_name(User& a, User& b)
{
	cout << "comp:" << a.name << ":" << b.name << "=" << strcmp(a.name, b.name) << endl;
	return strcmp(a.name, b.name);
}

bool usercomp_dept(User& a, User& b)
{
	cout << "comp:" << a.dept << ":" << b.dept << endl;
	return a.dept < b.dept;
}

bool comp_int(int a, int b)
{
	cout << "comp_int:" << a << ":" << b << endl;
	return a > b;
}

int main()
{
	cout << "<Algorithm> name order\n";
	sort(heads.begin(), heads.end(), usercomp_name);
	print_id(heads);
	cout << endl;
	cout << "<Algorithm> dept order\n";
	sort(heads.begin(), heads.end(), usercomp_dept);
	print_id(heads);
	cout << endl;

	cout << "<Custom> Heads in alphabetical order\n";
	ssort(&heads[0], heads.size(), sizeof(User), cmp1);
	print_id(heads);
	cout << endl;

	vector<int> ddd {10,9,8,7,6,5,4,3,2,1};
	sort(ddd.begin(), ddd.end(), comp_int);
	for (auto x: ddd)
		cout << x << endl;
}
