#include <iostream>
#include <map>
#include <cctype>
#include <cmath>

using namespace std;

enum class Kind: char {
    name, number, end,
    plus='+', minus='-', mul='*', div='/', print=';', assign='=', lp='(', rp=')'
};

struct Token {
    Kind kind;
    string string_value;
    double number_value;
};

int no_of_errors;
int linenum;

double error(const string& s)
{
    no_of_errors++;
    cerr << "error: " << s << " at line-" << linenum << '\n';
    return 1;
}

class Token_stream {
public:
    Token_stream(istream& s): ip{&s}, owns{false} {}
    Token_stream(istream* p): ip{p}, owns{true} {}

    ~Token_stream() { close(); }

    Token get(); // read and return next token
    Token& current() { return ct; }

    void set_input(istream& s) { close(); ip = &s; owns = false; }
    void set_input(istream* p) { close(); ip = p; owns = true; }
private:
    void close() { if (owns) delete ip; }

    istream* ip;
    bool owns;
    Token ct {Kind::end};
};


double call_function(string fname, string arg)
{
	cout << "func:" << fname << " arg:" << arg << endl;

	if (fname == "sqrt") {
		return sqrt(stoi(arg));
	} else if (fname == "log") {
		return log(stoi(arg));
	} else if (fname == "sin") {
		return sin(stoi(arg));
	}
	return 1.0;
}

Token Token_stream::get(void)
{
    char ch;

    do {
        if (!ip->get(ch)) return ct = {Kind::end};
    } while (ch != '\n' && isspace(ch));

    switch (ch) {
        case ';':
        case '\n':
            linenum++;
            return ct = {Kind::print};
        case 0:
            return ct = {Kind::end};
        case '+': case '-': case '*': case '/': case '=': case '(': case ')':
            return ct = {static_cast<Kind>(ch)};
        case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7':
        case '8': case '9':
            ip->putback(ch);
            *ip >> ct.number_value;
            ct.kind = Kind::number;
            return ct;
        default:
            if (isalpha(ch)) {
                ct.string_value = ch;
                while (ip->get(ch)) {
                    if (isalnum(ch))
                        ct.string_value += ch;
                    else {
                        ip->putback(ch);
                        break;
                    }
                }

/*
Exercises: X13 [19]

gkim@gkim-laptop:~/tcppl_exercise/X13$ g++ 19.cpp && ./a.out
log(4)
func:log arg:4
1.38629
sin(30)
func:sin arg:30
-0.988032
sqrt(100)
func:sqrt arg:100
10
  C-c C-c
*/
				ip->get(ch);
				if (ch == '(') {
					// get argument
					string arg;
					while (ip->get(ch)) {
						if (isdigit(ch)) {
							arg += ch;
						} else if (ch == ')') {
							break;
						} else {
							// BUGBUG: no error handling
							cout << "syntax error for function\n";
							break;
						}
					}
					ct.number_value = call_function(ct.string_value, arg);
					ct.kind = Kind::number;
				} else {
					ip->putback(ch);
					ct.kind = Kind::name;
				}
            }
    }
    return ct;
}

double term(bool);
double expr(bool);
double prim(bool);

Token_stream ts {cin};
map<string, double> table;

double expr(bool get)
{
    double left = term(get);

    for(;;) {
        switch (ts.current().kind) {
            case Kind::plus:
                left += term(true);
                break;
            case Kind::minus:
                left -= term(true);
                break;
            default:
                return left;
        }
    }
}

double term(bool get)
{
    double left = prim(get);

    for(;;) {
        switch (ts.current().kind) {
        case Kind::mul:
            left *= prim(true);
            break;
        case Kind::div:
            if (auto d = prim(true)) {
                left /= d;
                break;
            }
            return error("divide by 0");
        default:
            return left;
        }
    }
}

double prim(bool get)
{
    if (get) ts.get();

    switch (ts.current().kind) {
        case Kind::number:
        {
            double v = ts.current().number_value;
            ts.get();
            return v;
        }
        case Kind::name:
        {
            double& v = table[ts.current().string_value];
            if (ts.get().kind == Kind::assign) v = expr(true);
            return v;
        }
        case Kind::minus:
            return -prim(true);
        case Kind::lp:
        {
            auto e = expr(true);
            if (ts.current().kind != Kind::rp) return error("')' is expected");
            ts.get(); //eat
            return e;
        }
        default:
            return error("primary expected");
    }
}

void calculate()
{
    for(;;) {
        ts.get();
        if (ts.current().kind == Kind::end) break;
        if (ts.current().kind == Kind::print) continue;
        cout << expr(false) << endl;
    }
}

int main(void)
{
    table["pi"] = 3.14;
    table["e"] = 2.718;

    calculate();
    return no_of_errors;
}
