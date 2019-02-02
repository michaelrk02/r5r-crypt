// R5R encrypion method
// Encryption: P -> 1R5R - 1RSM -> C
// Decryption: C -> MSR1 - R5R1 -> P
// By Michael Krisnadhi
#ifndef __R5R_h__
#define __R5R_h__

#include <string>

#if defined(__GNUC__)
#if defined(__R5R_BUILD__)
#define R5R_API __attribute__((visibility("default")))
#else
#define R5R_API
#endif
#elif defined(_MSC_VER)
#if defined(__R5R_BUILD__)
#define R5R_API __declspec(dllexport)
#else
#define R5R_API __declspec(dllimport)
#endif
#endif

class R5R_API R5R
{
public:
    //! @brief Encrypts a plain text
    //! @param[in] text Plain text
    //! @return Ciphertext
    static std::string Encrypt(const std::string& text);

    //! @brief Decrypts a ciphertext
    //! @param[in] text Ciphertext
    //! @return Plain text
    static std::string Decrypt(const std::string& text);

private:
    static std::string T0(const std::string& s);
    static std::string T1(const std::string& s);
    static std::string T2(const std::string& s);
    static std::string T3(const std::string& s);
    static std::string T4(const std::string& s);
    static std::string T5(const std::string& s);
};

#endif

