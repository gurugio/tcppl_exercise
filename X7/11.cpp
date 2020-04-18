#include <iostream>
#include <iomanip>

using namespace std;


#define TYPE(t) {#t, sizeof(t) / sizeof(char)}

struct type_size {
	char name[16];
	int size_by_char;
};

int main(void)
{
	struct type_size types[] = {
								TYPE(bool),
								TYPE(char),
								TYPE(short),
								TYPE(int),
								TYPE(long),
								TYPE(long long),
								TYPE(float),
								TYPE(double),
								TYPE(unsigned),
								TYPE(unsigned long),
	};

	for (auto t: types) {
		cout << setw(16) << t.name << ":";
		for (int i = 0; i < t.size_by_char; i++)
			cout << "*";
		cout << endl;
	}
	
	return 0;
}
