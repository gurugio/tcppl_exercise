#include <iostream>

using namespace std;

int fact_iter(int n)
{
	int ret = 1;

	for (int i = 1; i <= n; i++)
		ret *= i;

	return ret;
}

int fact_recur(int n)
{
	return n == 1 ? 1 : (n * fact_recur(n - 1));
}
	
int main(void)
{
	for (int i = 2; i <= 7; i++) {
		cout << fact_iter(i) << "==" << fact_recur(i) << endl;
	}
}
