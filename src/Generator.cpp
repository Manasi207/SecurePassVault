#include "Generator.h"
#include <cstdlib>
#include <ctime>

string Generator::generate(int len)
{
    string chars =
        "abcdefghijklmnopqrstuvwxyz"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "0123456789@#$%";

    srand(time(0));

    string pass = "";
    for (int i = 0; i < len; i++)
        pass += chars[rand() % chars.size()];

    return pass;
}
