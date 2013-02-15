#include <iostream>
#include <string>
#include <map>
#include <cctype>
#include <sstream>
#include <cmath>

using namespace std;

enum Token_value {
    NAME, NUMBER, END, FUNC,
    PLUS='+', MINUS='-', MUL='*', DIV='/',
    PRINT=';', ASSIGN='=', LP='(', RP=')'
};

Token_value curr_tok = PRINT;

double expr(bool);
double term(bool);
double prim(bool);
Token_value get_token();
double error(const string& s);


typedef double (*math_func)(double);

struct func_table
{
    char name[16];
    math_func fp;
};

double call_sqrt(double val)
{
    return sqrt(val);
}

func_table ftable[] = {
    {"sqrt", call_sqrt}
};
    

double expr(bool get)
{
    double left = term(get);
    for(;;)
    {
        switch (curr_tok) {
            case PLUS:
                left += term(true);
                break;
            case MINUS:
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
    for (;;)
    {
        switch (curr_tok) {
            case MUL:
                left *= prim(true);
                break;
            case DIV:
                if (double d = prim(true)) {
                    left /= d;
                    break;
                }
                return error("divide by 0");
            default:
                return left;
        }
    }
}

// double number_value;
// string string_value;

struct symbol
{
    double number_value;
    string string_value;
};

struct symbol cur_value;

map<string, double> table;



double prim(bool get)
{
    if (get) get_token();

    switch (curr_tok) {
        case NUMBER:
            {
                double v = cur_value.number_value;
                get_token();
                return v;
            }
        case NAME:
            {
                double& v = table[cur_value.string_value];
                if (get_token() == ASSIGN)
                    v = expr(true);
                return v;
            }
        case FUNC:
            {
                int ftable_index = table[cur_value.string_value];
                double v = 0;

                cout << "func index=" << ftable_index << endl;
                cout << "func found:" << ftable[ftable_index].name << endl;
                if (get_token() == LP)
                {
                    v = expr(true);
                    cout << "argument:" << v << endl;
                }
                else
                {
                    cout << "LP should be found" << endl;
                }
                return ftable[ftable_index].fp(v);
            }
        case MINUS:
            return -prim(true);
        case LP:
            {
                double e = expr(true);
                if (curr_tok != RP)
                    return error("')' expected");
                get_token();
                return e;
            }
        default:
            return error("primary expected");
    }
}

int line_num;

Token_value get_token()
{
    char ch = 0;
    
    do
    {
        if (!cin.get(ch))
        {
            cout << "get_token: input ends\n";
            return curr_tok = END;
        }
    } while (ch != '\n' && isspace(ch)); // 공백이면 다시 읽기
    
    switch (ch) {
        case 0:
            cout << "get_token: read eof\n";
            return curr_tok = END;
        case ';':
        case '\n':
            return curr_tok = PRINT;
        case '*':
        case '/':
        case '+':
        case '-':
        case '(':
        case ')':
        case '=':
            cout << "get_token: read OP=" << ch << '\n';
            return curr_tok = Token_value(ch);
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
        case '.':
            cin.putback(ch);
            cin >> cur_value.number_value;
            cout << "get_token: read NUMBER=" << cur_value.number_value << '\n';
            return curr_tok = NUMBER;
        default:
            if (isalpha(ch)) {
                cur_value.string_value = ch;

                while (cin.get(ch) && isalnum(ch))
                    cur_value.string_value.push_back(ch);

                if (ch == '(')
                {
                    cin.putback(ch);
                    cout << "get_token: read FUNC=" << cur_value.string_value << endl;
                    return curr_tok = FUNC;
                }
                else
                {
                    cin.putback(ch);

                    cout << "get_token: read NAME=" << cur_value.string_value << '\n';
                    return curr_tok = NAME;
                }
            }
            error("bad token");
            return curr_tok = PRINT;
    }
}


int no_of_errors;

double error(const string& s)
{
    no_of_errors++;
    cerr << "error:" << s << " at line:" << line_num << '\n';
    return 1;
}

istream* input;

int main(int argc, char* argv[])
{
    switch (argc) {
        case 1:
            input = &cin;
            break;
        case 2:
            cout << "argv[1]=" << argv[1] << endl;
            input = new istringstream(argv[1]);
            break;
        default:
            error("too many arguments");
            return 1;
    }
    
    table["pi"] = 3.14159;
    table["e"] = 2.71828;
    table["sqrt"] = 0;

    line_num = 1;

    // 루프에서 첫 토큰을 읽으면 그 다음 토큰들은 expr내부에서 읽혀진다.
    // 따라서 한번의 루프가 한 줄이 된다.
    while (*input) {
        get_token();

        if (curr_tok == END) break;
        if (curr_tok == PRINT) continue;

        cout << expr(false) << '\n';

        line_num++;
    }

    if (input != &cin)
        delete input;
    
    return no_of_errors;
}

