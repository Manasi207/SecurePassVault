#include "PasswordManager.h"
#include <iostream>

PasswordManager::PasswordManager()
{
    vault = storage.loadVault();

    for (auto &p : vault)
        trie.insert(p.first);
}

void PasswordManager::addPassword(string site, string pass)
{
    history.push(site, vault[site]);

    vault[site] = pass;
    trie.insert(site);

    storage.saveVault(vault);
}

string PasswordManager::getPassword(string site)
{
    return vault.count(site) ? vault[site] : "Not Found";
}

void PasswordManager::deletePassword(string site)
{
    vault.erase(site);
    storage.saveVault(vault);
}

void PasswordManager::search(string prefix)
{
    auto res = trie.autocomplete(prefix);

    for (auto &s : res)
        cout << s << endl;
}

void PasswordManager::listAll()
{
    for (auto &p : vault)
        cout << p.first << endl;
}
