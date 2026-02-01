#ifndef PASSWORD_MANAGER_H
#define PASSWORD_MANAGER_H

#include <vector>
#include <string>
#include "model/Credential.h"
#include "Trie.h"
#include "History.h"
#include "Storage.h"

class PasswordManager
{
    vector<Credential> vault;
    Trie trie;
    History history;
    Storage storage;

public:
    PasswordManager();

    void addCredential(Credential c);
    void viewCredential(string siteName); // asks for authentication
    void editCredential(string siteName);
    void deleteCredential(string siteName);
    void search(string prefix);
    void listAll();
};

#endif
