
#include "parser.h"
#include "error.h"
#include "lexer.h"

namespace Parser {
    double prim(bool get);
    double term(bool get);
    double expr(bool get);

    using Lexer::get_token;
    using Lexer::curr_tok;
}

