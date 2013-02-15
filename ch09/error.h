
namespace Error {
    struct Zero_divide {
        Zero_divide() { }
    };

    struct Syntax_error {
        const char *p;
        Syntax_error(const char *q) { p = q; }
    };
}    
