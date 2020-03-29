#include <iostream>
#include <regex>

using namespace std;


int main(void)
{
	regex pat ("[0-9]+");
	//regex pat ("[0-9]+(?:[.][0-9]+)?"); // floating number
	for (string line; getline(cin, line); ) {
		smatch matches;
		while (regex_search(line, matches, pat)) {
			for (auto mt: matches) cout << mt << endl;
			line = matches.suffix().str();
		}
	}
}
