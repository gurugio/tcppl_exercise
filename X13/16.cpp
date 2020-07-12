/*
[16] (∗3) Write a macro processor that defines and expands simple macros (like the C preproces-
sor does). Read from cin and write to cout . At first, don’t try to handle macros with argu-
ments. Hint: The desk calculator (§10.2) contains a symbol table and a lexical analyzer that
you could modify.
*/

#include <iostream>
#include <map>
#include <cctype>

using namespace std;

map<string, string> symbol_table;


int main(void)
{
	char ch;

	while (cin.get(ch)) {
		if (ch == '#') {
			cin >> ch;
			if (ch == 'd') {
				cin.putback(ch);
				// no error check for #dnotdefine case
				string define;
				string name, val;
				cin >> define >> name >> val;
				symbol_table[name] = val;
				cin.get(ch); // remove newline
			} else {
				// #include
				cout << '#';
				cout << ch;
			}
		} else if (isalnum(ch)) {
			// read token and check symbol
			string token;
			map<string, string>::iterator it;

			token += ch;
			while (cin.get(ch)) {
				if (isalnum(ch)) {
					token += ch;
				} else {
					cin.putback(ch);
					break;
				}
			}

			it = symbol_table.find(token);
			if (it != symbol_table.end()) {
				cout << it->second;
			} else {
				cout << token;
			}
		} else {
			// special characters
			cout << ch;
		}
	}
}

/*
gkim@gkim-laptop:~/tcppl_exercise/X13$ g++ 16.cpp && ./a.out < 16_ex.cpp
#include <iostream>
#include <vector>

using namespace std;



vector<int> vec;

int main(void)
{
	cout << "abc" << endl;
	cout << 3.14 << endl;
	vec.push_back(3.14);
	for (auto x: vec)
		cout << x << endl;
}
gkim@gkim-laptop:~/tcppl_exercise/X13$ g++ 16.cpp && ./a.out < 16_ex.cpp > ddd.cpp
gkim@gkim-laptop:~/tcppl_exercise/X13$ g++ ddd.cpp 
gkim@gkim-laptop:~/tcppl_exercise/X13$ ./a.out
abc
3.14
3
*/
