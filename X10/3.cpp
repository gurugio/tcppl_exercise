#include <iostream>

using namespace std;

/*
 * for fast copy
 */
void send(int* to, int *from, int count)
// Duff ’s device. Helpful comment deliberately deleted.
{
	int n = (count+7)/8;
	switch (count%8) {
	case 0: do { *to++ = *from++;
	case 7: *to++ = *from++;
	case 6: *to++ = *from++;
	case 5: *to++ = *from++;
	case 4: *to++ = *from++;
	case 3: *to++ = *from++;
	case 2: *to++ = *from++;
	case 1: *to++ = *from++;
		} while (--n>0);
	}
}

int main(void)
{
	int src[64] = {0,};
	int dst[64] = {0,};

	for (int i = 4; i <= 16; i+=4) {
		for (int j = 0; j < i; j++)
			src[j] = j;
		
		send(dst, src, i);
		for (int j = 0; j < 16; j++)
			cout << dst[j] << ',';
		cout << endl;
	}

	return 0;
}
