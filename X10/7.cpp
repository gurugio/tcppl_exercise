#if 0

----------------------- test file ----------------------
#include <iostream>
using namespace std;

int main(void/* ignore */)
{
	// ignore ignore ignore
	cout << "message /* asdfasdf */" << endl; /* ignore */
	/*
	 * ignore ignore ignore
	 * ignore ignore ignore
	 */
	cout << "message // asdfasdf" << endl;
	/* ignore // ignore */
	/* ignore /* ignore */ cout << "message\n";
}
------------------- end of test file -------------------

------------------ output -----------------
#include <iostream>
using namespace std;

int main(void)
{
                cout << "message /* asdfasdf */" << endl; 
        
        cout << "message // asdfasdf" << endl;
        
         cout << "message\n";
}
-------------- end of output ---------------
#endif

#include <iostream>
using namespace std;

// enum class for mode: quote, oneline_comment, multilime_comment
enum class Mode {
				 NORMAL,
				 QUOTE,
				 ONELINE_COMMENT,
				 MULTILINE_COMMENT
};

int main(void)
{
	string line;
	string text;
	Mode mode = Mode::NORMAL;
	string output;

	while (getline(cin, line)) {
		cout << line << endl;
		text += line;
		text += '\n';
	}

	int i = 0;
	
	while (text[i]) {
		cout << "cur: " << text[i] << endl;
		switch (text[i]) {
		case '"':
			if (mode == Mode::NORMAL) {
				mode = Mode::QUOTE;
				cout << "mode: normal -> quote\n";
				output += text[i];
				cout << "added\n";
			} else if (mode == Mode::QUOTE) {
				mode = Mode::NORMAL;
				cout << "mode: quote -> normal\n";
				output += text[i];
				cout << "added\n";
			}
			break;
		case '/':
			if (mode == Mode::NORMAL && text[i+1] == '/') {
				i++;
				mode = Mode::ONELINE_COMMENT;
				cout << "mode: normal -> oneline_comment\n";
			} else if (mode == Mode::NORMAL && text[i+1] == '*') {
				i++;
				mode = Mode::MULTILINE_COMMENT;
				cout << "mode: normal -> multiline_comment\n";
			}

			if (mode != Mode::MULTILINE_COMMENT && mode != Mode::ONELINE_COMMENT) {
				output += text[i];
				cout << "added\n";
			}
			break;
		case '*':
			if (mode == Mode::MULTILINE_COMMENT && text[i+1] == '/') {
				i++;
				mode = Mode::NORMAL;
				cout << "mode: multiline -> normal\n";
				// do not add
			} else if (mode == Mode::NORMAL || mode == Mode::QUOTE) {
				output += text[i];
				cout << "added\n";
			}
			break;
		case '\n':
			if (mode == Mode::ONELINE_COMMENT) {
				mode = Mode::NORMAL;
				cout << "mode: oneline -> normal\n";
			} else if (mode == Mode::NORMAL || mode == Mode::QUOTE) {
				output += text[i];
				cout << "added\n";
			}
			break;
		default:
			if (mode != Mode::MULTILINE_COMMENT && mode != Mode::ONELINE_COMMENT) {
				output += text[i];
				cout << "added\n";
			}
		}

		i++;
	}

	END:
	cout << output << endl;
	return 0;
}
