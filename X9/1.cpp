#include <iostream>

using namespace std;


struct types_asc {
  bool bool_var;
  char char_var;
  int int_var;
  long long_var;
  double double_var;
  long double ldouble_var;
};

struct types_dsc {
  long double ld;
  double d;
  long l;
  int i;
  char c;
  bool b;
};

struct types_mix {
  long double ld;
  bool b;
  double d;
  char c;
  long l;
  int i;
};

int main(void)
{
  struct types_asc asc;
  struct types_dsc dsc;
  struct types_mix mix;
  cout << "ascending:" << sizeof(asc) << endl; // dsc and asc are same
  cout << "descending:" << sizeof(dsc) << endl;
  cout << "mix:" << sizeof(mix) << endl; // mix is biggest!
}
