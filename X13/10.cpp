#include <iostream>
#include <cassert>

using namespace std;

string encoding(string line, string key)
{
	for (int i = 0; i < line.length(); i++) {
		line[i] = line[i] ^ key[i % key.length()];
	}
	return line;
}

int main(int argc, char **argv)
{
	string line, line_enc, line_dec;
	string key;

	if (argc == 2)
		key = string(argv[1]);
	cout << "key:" << key << endl;

	while (cin >> line) {
		cout << "original:" << line << endl;
		line_enc = encoding(line, key);
		
		line_dec = encoding(line_enc, key);
		cout << "after:" << line_dec << endl;

		assert(line_dec == line);
	}
}

/*
gkim@gkim-laptop:~/tcppl_exercise/X13$ g++ 10.cpp && ./a.out asdf
key:asdf
a
original:a
after:a
abc
original:abc
after:abc
as
original:as
after:as
12345
original:12345
after:12345
123456
original:123456
after:123456
1234567
original:1234567
after:1234567
123456789
original:123456789
after:123456789
  C-c C-c
*/
