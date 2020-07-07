#include <iostream>

using namespace std;


int main(int argc, char **argv)
{
	if (argc <= 1) {
		cout << "specify names" << endl;
		return 1;
	}
	
	for (int i = 1; i < argc; i++) {
		cout << "Hello, " << argv[i] << "!" << endl;
	}
	return 0;
}
