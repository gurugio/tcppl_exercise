#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;


int main(void)
{
	ofstream file;
    srand(time(nullptr)); // use current time as seed for random generator

	file.open("intfile.txt");

	for (int i = 0; i < 1000; i++)
		file << rand() << endl;

	file.close();
}
