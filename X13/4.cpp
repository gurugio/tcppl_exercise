#include <iostream>
#include <fstream>

using namespace std;


int main(int argc, char **argv)
{
	if (argc <= 1) {
		cout << "specify files.." << endl;
		return 1;
	}
	
	for (int i = 1; i < argc; i++) {
		string line;
		ifstream srcfile;

		srcfile.open(argv[i], ios::in);
		if (srcfile.is_open()) {
			while (getline(srcfile, line)) {
				cout << line << endl;
			}
			srcfile.close();
		} else {
			cout << "Failed to open: " << argv[i] << endl;
		}
	}

	return 0;
}
