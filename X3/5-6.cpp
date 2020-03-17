#include <iostream>
#include <string>


using namespace std;

int main()
{
  bool var_bool = true;
  char var_char = 'A';
  int var_int = 12345678;
  double var_double = 0.12345678;
  string var_string = "This is a string";
  int tmp;

  cout << var_bool << ":" << var_char << ":" << var_int << ":"
       << var_double << ":" << var_string << endl;

  cout << "enter bool char int double string: ";
  cin >> var_bool >> var_char >> var_int >> var_double >> var_string;
  cout << var_bool << ":" << var_char << ":" << var_int << ":"
       << var_double << ":" << var_string << endl;

}


// gkim@laptop:~/tcppl_exercise/X3$ ./a.out
// 1:A:12345678:0.123457:This is a string
// enter bool char int double string: 0 b 1 0.2 wow
// 0:b:1:0.2:wow
