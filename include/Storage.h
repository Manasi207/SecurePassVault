#ifndef STORAGE_H
#define STORAGE_H

#include <map>
#include <string>
using namespace std;

class Storage
{
public:
    void saveVault(map<string, string> data);
    map<string, string> loadVault();
};

#endif
