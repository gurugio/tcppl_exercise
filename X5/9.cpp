#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


int main(void)
{
	ifstream file;
	vector<int> nums;

	file.open("intfile.txt");

	cout << "before read: " << nums.size() << endl;
	for (int i = 0; i < 1000; i++) {
		int num;
		file >> num;
		cout << "read: " << num << endl;
		nums.push_back(num);
	}
	cout << "read size: " << nums.size() << endl;

	file.close();
}
