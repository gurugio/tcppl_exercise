#include <iostream>

using namespace std;


int main(void)
{
  char msg[] = "abcdefghijklmn";
  char *p1 = &msg[3];
  char *p2 = &msg[6];

  cout << p2 - p1 << endl;
}
