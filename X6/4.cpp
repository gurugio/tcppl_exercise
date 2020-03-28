#include <iostream>
#include <vector>
#include <random>

using namespace std;


class rand_int {
public:
	rand_int(float low, float high) :dist{low, high} {}

	int operator()() {
		return int(dist(re));
	}

private:
	default_random_engine re;
	normal_distribution<float> dist;
};


void no_class(void)
{
	default_random_engine re;
	normal_distribution<double> dist(15.0, 4.0);
	vector<int> histogram(30);

	for (int i = 0; i != 200; i++) {
		int d = dist(re);
		//cout << "rnd=" << d << endl;
		++histogram[d];
	}

	for (int i = 0; i != histogram.size(); ++i) {
		cout << i << '\t';
		for (int j = 0; j != histogram[i]; ++j)
			cout << '*';
		cout << endl;
	}
}

int main(void)
{
	no_class();

	rand_int rnd {15, 4};
	vector<int> histogram(30);
	
	for (int i = 0; i != 200; i++) {
		int d = rnd();
		//cout << "rnd=" << d << endl;
		++histogram[d];
	}

	for (int i = 0; i != histogram.size(); ++i) {
		cout << i << '\t';
		for (int j = 0; j != histogram[i]; ++j)
			cout << '*';
		cout << endl;
	}
}

