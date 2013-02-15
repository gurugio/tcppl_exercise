#include <iostream>
#include <string>
#include <map>
#include <cctype>
#include <sstream>
#include <cmath>

using namespace std;

namespace Parser {
    double expr(bool);
    double term(bool);
    double prim(bool);
}

namespace Lexer {  
    enum Token_value {
        NAME, NUMBER, END, FUNC,
        PLUS='+', MINUS='-', MUL='*', DIV='/',
        PRINT=';', ASSIGN='=', LP='(', RP=')', COMMA=','
    };

    Token_value curr_tok = PRINT;

    struct symbol
    {
        double number_value;
        string string_value;
    };

    struct symbol cur_value;

    Token_value get_token();
}

namespace Error {
    int no_of_errors;
    int line_num;
    
    double error(const string& s)
    {
        no_of_errors++;
        cerr << "error:" << s << " at line:" << line_num << '\n';
        return 1;
    }

    struct Zero_divide {
        Zero_divide() { no_of_errors++; }
    };

    struct Syntax_error {
        const char *p;
        Syntax_error(const char *q) { p = q; no_of_errors++; }
    };
}    

namespace Driver {
    istream* input;
    void skip();
}

using namespace Driver;
using namespace Parser;
using namespace Lexer;
using namespace Error;

map<string, double> table;


double error(const string& s);


typedef int (*math_func)(int, int);

struct func_table
{
    char name[16];
    math_func fp;
};

struct overflow
{
    string *msg;
    overflow() { msg = new string("overflow"); };
};

struct underflow
{
    string *msg;
    underflow() { msg = new string("underflow"); };    
};

int myplus(int a, int b)
{
    if ((numeric_limits<int>::max() - a) > b)
    {
        return a+b;
    }
    else
    {
        throw overflow();
    }
}

int myminus(int a, int b)
{
    if (a > b)
    {
        return a - b;   
    }
    else
    {
        throw underflow();
    }
}

func_table ftable[] = {
    {"myplus", myplus},
    {"myminus", myminus}
};
    

double Parser::expr(bool get)
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

double Parser::term(bool get)
{
    double left = prim(get);
    for (;;)
    {
        switch (curr_tok) {
            case MUL:
                cout << "mul left=" << left << endl;
                left *= prim(true);
                break;
            case DIV:
                if (double d = prim(true)) {
                    left /= d;
                    break;
                }
//                return error("divide by 0");
                throw Error::Zero_divide();
            default:
                return left;
        }
    }
}

double Parser::prim(bool get)
{
    if (get) get_token();

    switch (curr_tok) {
        case NUMBER:
            {
                double v = cur_value.number_value;
                cout << "prim:" << cur_value.number_value << endl;
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
                int a = 0;
                int b = 0;
                int v = 0;
                Token_value t;
                
                cout << "func index=" << ftable_index << endl;
                cout << "func found:" << ftable[ftable_index].name << endl;
                
                if (get_token() == LP)
                {
                    a = (int)(expr(true));
                    cout << "1st argument:" << a << endl;
                }
                else
                {
                    cout << "LP should be found" << endl;
                }

                if (curr_tok == COMMA)
                {
                    b = (int)expr(true);
                    cout << "2nd argument:" << b << endl;
                }
                else
                {
                    cout << "COMMA should be found" << endl;
                }

                if (curr_tok == RP)
                {
                    cout << "func call complete" << endl;
                }
                else
                {
                    cout << "LP should be found" << endl;
                }
                
                // read ';'
                t = get_token();
                cout << "final tok=" << t << endl;
                
                // read '\n'
                if ((t = get_token()) == PRINT)
                {
                    cout << "final tok=" << t << endl;
                    try
                    {
                        v = ftable[ftable_index].fp(a, b);
                    }
                    catch (overflow o)
                    {
                        cout << *o.msg << endl;   
                    }
                    catch (underflow u)
                    {
                        cout << *u.msg << endl;                      
                    }
                }
                return v;
            }
        case MINUS:
            return -prim(true);
        case LP:
            {
                double e = expr(true);
                if (curr_tok != RP)
                    throw Error::Syntax_error("')' expected");
                    //return error("')' expected");
                get_token();
                return e;
            }
        default:
            {
//            return error("primary expected");
                cout << "curr_tok=" << (char)curr_tok << endl;
                throw Error::Syntax_error("primary expected");
            }
    }
}



Token_value Lexer::get_token()
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
        case ',':
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
            throw Error::Syntax_error("bad token");
            // return curr_tok = PRINT;
    }
}


void Driver::skip()
{
    while (*input) {
        char ch;
        input->get(ch);

        switch (ch) {
            case '\n':
            case ';':
                return;
        }
    }
}


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
            cerr << "too many arguments\n";
            return 1;
    }
    
    table["pi"] = 3.14159;
    table["e"] = 2.71828;
    table["myplus"] = 0;
    table["myminus"] = 1;

    line_num = 1;

    // 루프에서 첫 토큰을 읽으면 그 다음 토큰들은 expr내부에서 읽혀진다.
    // 따라서 한번의 루프가 한 줄이 된다.
    while (*input) {
        try {
            Lexer::get_token();

            if (Lexer::curr_tok == Lexer::END) break;
            if (Lexer::curr_tok == Lexer::PRINT) continue;

            cout << Parser::expr(false) << '\n';

            line_num++;
        }
        catch (Error::Zero_divide) {
            cerr << "attempt to divide by zero\n";
            if (Lexer::curr_tok != Lexer::PRINT)
                skip();
        }
        catch (Error::Syntax_error e) {
            cerr << "syntax error:" << e.p << endl;
            if (Lexer::curr_tok != Lexer::PRINT)
                skip();
        }
    }

    if (input != &cin)
        delete input;
    
    return no_of_errors;
}

