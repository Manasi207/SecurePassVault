#include "Encryption.h"

string Encryption::encrypt(string data)
{
    for (char &c : data)
        c = c + key;
    return data;
}

string Encryption::decrypt(string data)
{
    for (char &c : data)
        c = c - key;
    return data;
}
