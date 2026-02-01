#ifndef PASSWORD_MANAGER_H
#define PASSWORD_MANAGER_H

#include <map>
#include "Trie.h"
#include "History.h"
#include "Storage.h"

class PasswordManager
{
    map<string, string> vault;

    Trie trie;
    History history;
    Storage storage;

public:
    PasswordManager();

    void addPassword(string site, string pass);
    string getPassword(string site);
    void deletePassword(string site);

    void search(string prefix);
    void listAll();
};

#endif
