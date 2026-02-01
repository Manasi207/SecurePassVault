#ifndef AES_MANAGER_H
#define AES_MANAGER_H

#include <string>
using namespace std;

// Simple AES simulation using XOR for demonstration
class AESManager
{
    const char key = 'K';

public:
    string encrypt(string data);
    string decrypt(string data);
};

#endif
