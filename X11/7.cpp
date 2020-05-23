#include <iostream>
#include <cassert>
#include <cstring>

using namespace std;


size_t my_strlen(const char* str)
{
    size_t len = 0;
    while (*str++)
        len++;
    return len;
}

char *my_strcpy(char* dst, const char* src)
{
    size_t i;
    for (i = 0; src[i] != '\0'; i++) {
        dst[i] = src[i];
    }
    dst[i] = 0; // null
    
    return dst;
}

int my_strcmp(const char* s1, const char* s2)
{
    size_t i;
    for (i = 0; s1[i] != 0 && s2[i] != 0; i++) {
        if (s1[i] != s2[i])
            break;
    }
    return s1[i] - s2[i];
}

int main(void)
{
    assert(my_strlen("") == 0);
    assert(my_strlen("1234") == 4);

    char dst[5];
    char src1[1] = {0};
    char src2[5] = "1234";
    my_strcpy(dst, src1);
    assert(dst[0] == 0);
    my_strcpy(dst, src2);
    assert(dst[0] == '1' && dst[4] == 0);

    assert(my_strcmp(src1, src2) != 0);
    assert(my_strcmp(src2, "1234") == 0);
    assert(my_strcmp(src2, "123456") != 0);
    assert(my_strcmp("1234", src2) == 0);
    assert(my_strcmp("123456", src1) != 0);
    assert(my_strcmp(src1, src2) == strcmp(src1, src2));
    assert(my_strcmp(src2, "1234") == strcmp(src2, "1234"));
    assert(my_strcmp(src2, "123456") == strcmp(src2, "123456"));
    return 0;
}