#include <iostream>
#include <map>
#include <cctype>

using namespace std;

double error(const string& s);

enum class Kind: char {
    name, number, end,
    plus='+', minus='-', mul='*', div='/', print=';', assign='=', lp='(', rp=')',
    error
};

struct Token {
    Kind kind;
    string string_value;
    double number_value;
};

class Token_stream {
public:
    Token_stream(istream& s): ip{&s}, owns{false} {}
    Token_stream(istream* p): ip{p}, owns{true} {}

    ~Token_stream() { close(); }

    Token get(); // read and return next token
    Token& current() { return ct; }
    void error() { ct.kind = Kind::error; }

    void set_input(istream& s) { close(); ip = &s; owns = false; }
    void set_input(istream* p) { close(); ip = p; owns = true; }
private:
    void close() { if (owns) delete ip; }

    istream* ip;
    bool owns;
    Token ct {Kind::end};
};

Token Token_stream::get(void)
{
    char ch;

    do {
        if (!ip->get(ch)) return ct = {Kind::end};
    } while (ch != '\n' && isspace(ch));

    switch (ch) {
        case ';':
        case '\n':
            //cout << "Get print: <" << ch << ">" << endl;
            return ct = {Kind::print};
        case 0:
            //cout << "Get end\n";
            return ct = {Kind::end};
        case '+': case '-': case '*': case '/': case '=': case '(': case ')':
            //cout << "Get oper: " << ch << endl;
            return ct = {static_cast<Kind>(ch)};
        case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7':
        case '8': case '9':
            ip->putback(ch);
            *ip >> ct.number_value;
            //cout << "Get number: <" << ct.number_value << ">" << endl;
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
                //cout << "Get name: <" << ct.string_value << ">" << endl;
                ct.kind = Kind::name;
                return ct;
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
    if (ts.current().kind == Kind::error) {
        goto error_end;
    }
    double right;

    for(;;) {
        switch (ts.current().kind) {
            case Kind::plus:
                right = term(true);
                if (ts.current().kind == Kind::error) {
                    goto error_end;
                }
                left += right;
                break;
            case Kind::minus:
                right = term(true);
                if (ts.current().kind == Kind::error) {
                    goto error_end;
                }
                left -= right;
                break;
            default:
                return left;
        }
    }
error_end:
    return left;
}

double term(bool get)
{
    double left = prim(get);
    if (ts.current().kind == Kind::error) {
        goto error_end;
    }
    double right;

    for(;;) {
        switch (ts.current().kind) {
        case Kind::mul:
            right = prim(true);
            if (ts.current().kind == Kind::error) {
                goto error_end;
            }
            left *= right;
            break;
        case Kind::div:
            right = prim(true);
            if (ts.current().kind == Kind::error) {
                goto error_end;
            }
            if (right != 0) {
                left /= right;
                break;
            }
            return error("divide by 0");
            break;
        default:
            return left;
        }
    }
error_end:
    return left;
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

int no_of_errors;
double error(const string& s)
{
    no_of_errors++;
    cerr << "error: " << s << '\n';
    ts.error();
    return 1;
}

void calculate()
{
    for(;;) {
        ts.get();
        /*if (ts.current().kind == Kind::name) {
            cout << "First token: " << ts.current().string_value << endl;
        } else if (ts.current().kind == Kind::number) {
            cout << "First token: " << ts.current().number_value << endl;
        } else {
            cout << "First token: " << static_cast<int>(ts.current().kind) << endl;
        }*/
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