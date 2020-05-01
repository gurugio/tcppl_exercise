#include <iostream>
#include <string>
#include <vector>

using namespace std;


int comp_string(string a, string b)
{
	int i = 0;
	for (i = 0; i < a.size() && i < b.size(); i++) {
		if (a[i] != b[i])
			break;
	}
	return a[i] - b[i];
}

void sort_words(vector<string>& words)
{
	for (int i = 0; i < words.size(); i++) {
		for (int j = i + 1; j < words.size(); j++) {
			if (comp_string(words[i], words[j]) > 0) {
				string tmp = words[i];
				words[i] = words[j];
				words[j] = tmp;
			}
		}
	}
}

vector<string> remove_dup(vector<string>& words)
{
	vector<string> ret;
	
	for (int i = 0; i < words.size(); i++) {
		ret.push_back(words[i]);
		for (int j = i + 1; j < words.size(); j++) {
			if (words[i] == words[j])
				i++;
		}
	}
	return ret;
}

int main(void)
{
	vector<string> words;
	string tmp;

	while (cin >> tmp) {
		if (tmp == "quit")
			break;
		words.push_back(tmp);
	}

	sort_words(words);
	for (auto w: words)
		cout << w << endl;

	vector<string> single_words = remove_dup(words);
	for (auto w: single_words)
		cout << w << endl;
}
