#include <iostream>
using namespace std;

char* itoa(int i, char b[], size_t maxlen)
{
	int len;
	int digit;
	
	for (len = 0; len < maxlen - 1; len++) {
		digit = i % 10;
		i /= 10;
		b[len] = '0' + digit;
		if (i == 0)
			break;
	}
	b[len + 1] = 0;

	for (int k = 0; k <= len/2; k++) {
		char t = b[k];
		b[k] = b[len - k];
		b[len - k] = t;
	}
	return b;
}

int main(void)
{
	char buf[64];
	cout << itoa(0, buf, sizeof(buf)) << endl;
	cout << itoa(1234, buf, sizeof(buf)) << endl;
	cout << itoa(123450, buf, sizeof(buf)) << endl;
}
