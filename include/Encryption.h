#ifndef ENCRYPTION_H
#define ENCRYPTION_H

#include <string>
using namespace std;

class Encryption
{
    int key = 5; // simple XOR/Caesar key

public:
    string encrypt(string data);
    string decrypt(string data);
};

#endif
