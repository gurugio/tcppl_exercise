#include <iostream>


class dummy
{
public:
    dummy() { std::cout << "initilize global-static variable\n"; }
    ~dummy() { std::cout << "Clean up global-static variable\n"; }
};

static dummy d;

std::ostream &operator<<(std::ostream &os, const char *cs)
{
    os.write("Init operator<<\n", 16);
    os.write(cs, 6);
    os.write("Clean up operator<<\n", 20);
    return os;
}

int main()
{
    std::cout << "hello\n";
}
