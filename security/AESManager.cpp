#include "AESManager.h"

string AESManager::encrypt(string data)
{
    for (char &c : data)
        c ^= key; // XOR encryption
    return data;
}

string AESManager::decrypt(string data)
{
    for (char &c : data)
        c ^= key; // XOR decryption
    return data;
}
