#include <R5R.h>

std::string R5R::Decrypt(const std::string& text)
{
    std::string t = text;

    t = T5(t); // M
    t = T3(t); // S
    t = T2(t); // R
    t = T1(t); // 1

    t = T2(t); // R
    t = T1(t); // 1
    t = T1(t); // 2
    t = T1(t); // 3
    t = T1(t); // 4
    t = T1(t); // 5
    t = T2(t); // R
    t = T1(t); // 1

    return t;
}

