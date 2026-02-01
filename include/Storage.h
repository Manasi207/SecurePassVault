#ifndef STORAGE_H
#define STORAGE_H

#include <vector>
#include "model/Credential.h"

class Storage
{
public:
    void saveVault(vector<Credential> &creds);
    vector<Credential> loadVault();
};

#endif
