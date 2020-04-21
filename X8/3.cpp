#include <iostream>

using namespace std;

int main(void)
{
  using uchar = unsigned char; // unsigned char
  uchar uc = 'a';
  cout << uc << endl;

  using cuchar = const unsigned char; // const unsigned char
  cuchar cuc = 'b';
  cout << cuc << endl;

  int x = 1234;
  using pint = int*; // pointer to integer
  pint pi = &x;
  cout << *pi << endl;

  char ch = 'c';
  char* pc = &ch;
  using ppc = char**; // pointer to pointer to char
  ppc ppch = &pc;
  cout << **ppch << endl;

  char arr[16] = "abc";
  using ptocarr = char (*)[16]; // pointer to array of char
  ptocarr p_ch_arr = &arr;
  cout << p_ch_arr << endl;
  cout << p_ch_arr + 1 << endl; // p_ch_arr + 16
  char *t = *p_ch_arr;
  cout << *t << *(t+1) << *(t+2) << endl;

  using pint7 = int (*[7]); // array of 7 pointers to int
  int int7[7] = {0,1,2,3,4,5,6};
  //int *ptoint[7] = {&int7[0],
  pint7 ptoint = {&int7[0],
		    &int7[1],
		    &int7[2],
		    &int7[3],
		    &int7[4],
		    &int7[5],
		    &int7[6]};
  cout << *ptoint[0] << *ptoint[1] << *ptoint[2] << *ptoint[3] << endl;

  using ppint7 = pint7*;
  ppint7 pptoint = &ptoint;
  cout << pptoint << endl;
  cout << pptoint + 1 << endl; // ptoint + 0x38(=8X7)
  
  int *pmatrix[8][7] =
    {
     {&int7[0],&int7[1],&int7[2],&int7[3],&int7[4],&int7[5],&int7[6]},
     {&int7[0],&int7[1],&int7[2],&int7[3],&int7[4],&int7[5],&int7[6]},
     {&int7[0],&int7[1],&int7[2],&int7[3],&int7[4],&int7[5],&int7[6]},
     {&int7[0],&int7[1],&int7[2],&int7[3],&int7[4],&int7[5],&int7[6]},
     {&int7[0],&int7[1],&int7[2],&int7[3],&int7[4],&int7[5],&int7[6]},
     {&int7[0],&int7[1],&int7[2],&int7[3],&int7[4],&int7[5],&int7[6]},
     {&int7[0],&int7[1],&int7[2],&int7[3],&int7[4],&int7[5],&int7[6]},
     {&int7[0],&int7[1],&int7[2],&int7[3],&int7[4],&int7[5],&int7[6]}
    };
  //
  // do not know how to make "array of 8 arrays of 7 pointers to int".
  //
  // using ptointmatrix = int (*)[8][7];
  // ptointmatrix pmatrix_ex = pmatrix;
}
