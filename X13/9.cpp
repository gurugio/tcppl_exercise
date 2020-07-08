#include <iostream>

using namespace std;


void convert(int *mat, int size)
{
	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			int t = *((mat + i*size) + j);
			*((mat + i*size) + j) = *((mat + j*size) + i);
			*((mat + j*size) + i) = t;
		}
	}
}

int main(void)
{
	// convertible -> row and colume are same
	int matrix[5][5];

	for (int i = 0; i != 5; i++)
		for (int j = 0; j != 5; j++)
			matrix[i][j] = 10*i + j;
	
	convert(&matrix[0][0], 5);
	for (int i = 0; i != 5; i++) {
		for (int j = 0; j != 5; j++) {
			cout << matrix[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}
