#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int count_pair(const char *src, const char *pair)
{
	int count = 0;
	for (int i = 0; i < strlen(src) - strlen(pair); i++) {
		if (strncmp(&src[i], pair, strlen(pair)) == 0)
			count++;
	}
	return count;
}

int count_pair(string& src, string& pair)
{
	return count_pair(src.c_str(), pair.c_str());
}

int main(void)
{
	char test[] = "xabaacbaxabb";
	char pair[] = "ab";
	string t {test};
	string p {pair};
	
	cout << count_pair(test, pair) << endl;
	cout << count_pair(t, p) << endl;
}
