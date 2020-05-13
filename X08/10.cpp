#include <iostream>
#include <string>
#include <array>

using namespace std;


void pr_strings(array<string, 3> months)
{
	for (int i = 0; i < months.size(); i++)
		cout << months[i] << endl;
}

int main(void)
{
	array<string, 3> months {"Jan", "Feb", "Mar"};
	pr_strings(months);
}
