#include <iostream>
#include <string>
#include <R5R.h>
using namespace std;

int main(int argc, char** argv)
{
    if (argc == 2)
    {
        string p = argv[1];
        string c = R5R::Encrypt(p);
        cout << c << endl;
    }
    else
    {
        cout << "Usage: r5r-enc <plaintext>" << endl;
    }
    return 0;
}

