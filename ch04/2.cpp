#include <iostream>
#include <string>
#include <complex>

char ch; // declare & definition
extern char ch; // declare

std::string s; // declare & definition
extern std::string s; // declare

int count = 1; // declare & definition
extern int count; // declare

const double pi = 3.14; // declare & definition
extern const double pi; // declare

extern int error_number; // declare
int error_number = 3; // declare & definition

const char* name = "Njal"; // declare & definition
extern const char* name; // declare

const char* season[] = { "spring", "summer", "fall", "winter" }; // declare & definition
extern const char* season[]; // declare

struct Date { int d, m, y; }; // declare
struct Date mydate = {1,2,3}; // declare && definition


int day(Date* p) { return p->d; } // declare && definition
int day(Date* p); // declare

double sqrt(double); // declare
double mysqrt(double v) { return sqrt(v); } // declare && definition

template<class T>T abs(T a) { return a<0 ? -a : a; } // declare && definition
template<class T>T abs(T a); // declare??


typedef std::complex<short> Point;  // declare
Point x(1,2); // declare & definition

struct User; // declare
struct User { int num, phone; }; // declare & definition

enum Beer { Carlsberg, Tuborg, Thor };
namespace NS { int a; }

int main(void)
{
    std::cout << ch << s << count << pi << error_number << name << season[0] << '\n';
    std::cout << day(&mydate) << mysqrt(4) << abs(-4) << x;
    
    return 0;
}
