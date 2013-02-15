#include "lexer.h"
#include "error.h"
#include <iostream>
#include <cctype>

Lexer::Token_value Lexer::curr_tok = PRINT;
double Lexer::number_value;
std::string Lexer::string_value;

Lexer::Token_value Lexer::get_token()
{
    char ch = 0;
    
    do
    {
        if (!std::cin.get(ch))
        {
            std::cout << "get_token: input ends\n";
            return Lexer::curr_tok = END;
        }
    } while (ch != '\n' && isspace(ch)); // 공백이면 다시 읽기
    
    switch (ch) {
        case 0:
            std::cout << "get_token: read eof\n";
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
            std::cout << "get_token: read OP=" << ch << '\n';
            return curr_tok = Token_value(ch);
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
        case '.':
            std::cin.putback(ch);
            std::cin >> number_value;
            std::cout << "get_token: read NUMBER=" << number_value << '\n';
            return curr_tok = NUMBER;
        default:
            if (isalpha(ch)) {
                Lexer::string_value = ch;

                while (std::cin.get(ch) && isalnum(ch))
                    Lexer::string_value.push_back(ch);

                if (ch == '(')
                {
                    std::cin.putback(ch);
                    std::cout << "get_token: read FUNC=" << Lexer::string_value << std::endl;
                    return curr_tok = FUNC;
                }
                else
                {
                    std::cin.putback(ch);

                    std::cout << "get_token: read NAME=" << Lexer::string_value << '\n';
                    return curr_tok = NAME;
                }
            }
            throw Error::Syntax_error("bad token");
            // return curr_tok = PRINT;
    }
}
