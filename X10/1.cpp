#include <iostream>

using namespace std;

int main(void)
{
	int i;
	string input_line = "asdf?wer?zxcv?ae?";
	int quest_count = 0;
	int max_length = input_line.size();
	
	for (i=0; i!=max_length; i++)
		if (input_line[i] == '?')
			quest_count++;
	cout << quest_count << endl;

	quest_count = 0;
	i = 0;
	while (input_line[i]) {
		if (input_line[i++] == '?')
			quest_count++;
	}
	cout << quest_count << endl;

	quest_count = 0;
	const char *p = input_line.c_str();
	while (*p) {
		if (*p++ == '?')
			quest_count++;
	}
	cout << quest_count << endl;
}
