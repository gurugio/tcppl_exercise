#include <iostream>

using namespace std;

using tennisattack = void (*) (int);

class pingpong
{
private:
	int depth_max;
	tennisattack ping;
	tennisattack pong;
	
public:
	pingpong(int d) : depth_max{d}, ping{nullptr}, pong{nullptr} {}
	pingpong(int d, tennisattack pi, tennisattack po) : depth_max{d}, ping{pi}, pong{po} {}
	
	void default_ping(int depth)
	{
		if (depth > depth_max)
			throw runtime_error{"Ping: over-depth"};
		cout << depth << ":ping\n";
		default_pong(depth + 1);
	}

	void default_pong(int depth)
	{
		if (depth > depth_max)
			throw runtime_error{"Pong: over-depth"};
		cout << depth << ":pong\n";
		default_ping(depth + 1);
	}

	void call_ping(int depth)
	{
		if (depth > depth_max)
			throw runtime_error{"Ping: over-depth"};
		ping(depth);
		call_pong(depth + 1);
	}

	void call_pong(int depth)
	{
		if (depth > depth_max)
			throw runtime_error{"Pong: over-depth"};
		pong(depth);
		call_ping(depth + 1);
	}
	
	void play(void)
	{
		if (ping == nullptr) default_ping(0);
		else call_ping(0);
	}
};

void myping(int d)
{
	cout << d << ":myping\n";
}

void mypong(int d)
{
	cout << d << ":mypong\n";
}

int main(void)
{
	pingpong tabletennis(10);

	try {
		tabletennis.play();
	} catch (exception& e) {
		cerr << e.what() << endl;
	}

	pingpong tennis2(10, myping, mypong);
	try {
		tennis2.play();
	} catch (exception& e) {
		cerr << e.what() << endl;
	}
}
