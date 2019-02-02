#include <R5R.h>

std::string R5R::Encrypt(const std::string& text)
{
    std::string t = text;

    t = T0(t); // 1
    t = T2(t); // R
    t = T0(t); // 1
    t = T0(t); // 2
    t = T0(t); // 3
    t = T0(t); // 4
    t = T0(t); // 5
    t = T2(t); // R

    t = T0(t); // 1
    t = T2(t); // R
    t = T3(t); // S
    t = T4(t); // M

    return t;
}

