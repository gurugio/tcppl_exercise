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

		try {
			call_pong(depth + 1);
		} catch (exception& e) {
			cout << "Exception from pong at depth:" << (depth + 1) << endl;
			throw;
		}
	}

	void call_pong(int depth)
	{
		if (depth > depth_max)
			throw runtime_error{"Pong: over-depth"};
		pong(depth);
		try {
			call_ping(depth + 1);
		} catch (exception& e) {
			cout << "Exception from ping at depth:" << (depth + 1) << endl;
			throw;
		}
	}
	
	void play(void)
	{
		try {
			if (ping == nullptr) default_ping(0);
			else call_ping(0);
		} catch (exception& e) {
			cout << "Exception: " << e.what() << endl;
		}
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
	tabletennis.play();

	pingpong tennis2(10, myping, mypong);
	tennis2.play();
}
