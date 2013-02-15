#include "parser.h"
#include "lexer.h"
#include "error.h"
#include "table.h"
#include "driver.h"

#include <sstream>
#include <iostream>

int line_num;

void Driver::skip()
{
    while (*Driver::input) {
        char ch;
        Driver::input->get(ch);

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
            Driver::input = &std::cin;
            break;
        case 2:
            std::cout << "argv[1]=" << argv[1] << std::endl;
            Driver::input = new std::istringstream(argv[1]);
            break;
        default:
            std::cerr << "too many arguments\n";
            return 1;
    }
    
    table["pi"] = 3.14159;
    table["e"] = 2.71828;
    table["sqrt"] = 0;

    line_num = 1;

    // 루프에서 첫 토큰을 읽으면 그 다음 토큰들은 expr내부에서 읽혀진다.
    // 따라서 한번의 루프가 한 줄이 된다.
    while (*Driver::input) {
        try {
            Lexer::get_token();

            if (Lexer::curr_tok == Lexer::END) break;
            if (Lexer::curr_tok == Lexer::PRINT) continue;

            std::cout << Parser::expr(false) << '\n';

            line_num++;
        }
        catch (Error::Zero_divide) {
            std::cerr << "attempt to divide by zero\n";
            if (Lexer::curr_tok != Lexer::PRINT)
                Driver::skip();
        }
        catch (Error::Syntax_error e) {
            std::cerr << "syntax error:" << e.p << std::endl;
            if (Lexer::curr_tok != Lexer::PRINT)
                Driver::skip();
        }
    }

    if (Driver::input != &std::cin)
        delete Driver::input;
    
    return Driver::no_of_errors;
}

