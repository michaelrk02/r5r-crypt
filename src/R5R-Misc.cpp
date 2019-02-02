#include <stdint.h>
#include <R5R.h>

// Forward
std::string R5R::T0(const std::string& s)
{
    std::string t;
    uint32_t len = s.length();
    t.resize(len);
    for (uint32_t i = 0; i < len; i++)
    {
        uint32_t src = i;
        uint32_t dest = (i * 2) - (((i * 2) >= len) ? ((len % 2 == 0) ? (len - 1) : len) : 0);
        t[dest] = s[src];
    }
    return t;
}

// Backward
std::string R5R::T1(const std::string& s)
{
    std::string t;
    uint32_t len = s.length();
    t.resize(len);
    for (uint32_t i = 0; i < len; i++)
    {
        uint32_t src = (i * 2) - (((i * 2) >= len) ? ((len % 2 == 0) ? (len - 1) : len) : 0);
        uint32_t dest = i;
        t[dest] = s[src];
    }
    return t;
}

// Revert
std::string R5R::T2(const std::string& s)
{
    std::string t;
    uint32_t len = s.length();
    t.resize(len);
    for (uint32_t i = 0; i < len; i++)
    {
        uint32_t src = i;
        uint32_t dest = len - 1 - i;
        t[dest] = s[src];
    }
    return t;
}

// Swap
std::string R5R::T3(const std::string& s)
{
    std::string t;
    uint32_t len = s.length();
    t.resize(len);
    for (uint32_t i = 0; i < len; i++)
    {
        char chold = s[i];
        char chnew = s[i];
        if (chold >= 'A' && chold <= 'Z')
        {
            chnew = chold + 32;
        }
        else if (chold >= 'a' && chnew <= 'z')
        {
            chnew = chold - 32;
        }
        t[i] = chnew;
    }
    return t;
}

// Modify
std::string R5R::T4(const std::string& s)
{
    int mod = 5;
    std::string t;
    uint32_t len = s.length();
    t.resize(len);
    for (uint32_t i = 0; i < len; i++)
    {
        char chold = s[i];
        char chnew = s[i];
        if (chold >= 'A' && chold <= 'Z')
        {
            chnew = chnew - 'A';
            chnew = (26 + chnew + (mod % 26)) % 26;
            chnew = chnew + 'A';
        }
        else if (chold >= 'a' && chold <= 'z')
        {
            chnew = chnew - 'a';
            chnew = (26 + chnew + (mod % 26)) % 26;
            chnew = chnew + 'a';
        }
        t[i] = chnew;
    }
    return t;
}

// Original
std::string R5R::T5(const std::string& s)
{
    int mod = -5;
    std::string t;
    uint32_t len = s.length();
    t.resize(len);
    for (uint32_t i = 0; i < len; i++)
    {
        char chold = s[i];
        char chnew = s[i];
        if (chold >= 'A' && chold <= 'Z')
        {
            chnew = chnew - 'A';
            chnew = (26 + chnew + (mod % 26)) % 26;
            chnew = chnew + 'A';
        }
        else if (chold >= 'a' && chold <= 'z')
        {
            chnew = chnew - 'a';
            chnew = (26 + chnew + (mod % 26)) % 26;
            chnew = chnew + 'a';
        }
        t[i] = chnew;
    }
    return t;
}

