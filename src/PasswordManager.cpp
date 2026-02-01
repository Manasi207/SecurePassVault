#include "PasswordManager.h"
#include "Auth.h"
#include <iostream>
using namespace std;

PasswordManager::PasswordManager()
{
    vault = storage.loadVault();
    for (auto &c : vault)
        trie.insert(c.siteName);
}

void PasswordManager::addCredential(Credential c)
{
    vault.push_back(c);
    trie.insert(c.siteName);
    storage.saveVault(vault);
    cout << "Credential added!\n";
}

void PasswordManager::viewCredential(string siteName)
{
    for (auto &c : vault)
    {
        if (c.siteName == siteName)
        {
            string auth;
            cout << "Re-enter master password: ";
            cin >> auth;
            Auth a;
            if (!a.login(auth))
            {
                cout << "Authentication failed!\n";
                return;
            }

            cout << "Site: " << c.siteName << "\n";
            cout << "URL: " << c.url << "\n";
            cout << "Username: " << c.username << "\n";
            cout << "Password: " << c.encPassword << "\n"; // eye icon simulation
            return;
        }
    }
    cout << "Credential not found.\n";
}

void PasswordManager::editCredential(string siteName)
{
    for (auto &c : vault)
    {
        if (c.siteName == siteName)
        {
            cout << "New username: ";
            cin >> c.username;
            cout << "New password: ";
            cin >> c.encPassword;
            storage.saveVault(vault);
            cout << "Updated!\n";
            return;
        }
    }
    cout << "Credential not found.\n";
}

void PasswordManager::deleteCredential(string siteName)
{
    for (size_t i = 0; i < vault.size(); i++)
    {
        if (vault[i].siteName == siteName)
        {
            vault.erase(vault.begin() + i);
            storage.saveVault(vault);
            cout << "Deleted!\n";
            return;
        }
    }
    cout << "Credential not found.\n";
}

void PasswordManager::search(string prefix)
{
    auto res = trie.autocomplete(prefix);
    for (auto &s : res)
        cout << s << endl;
}

void PasswordManager::listAll()
{
    for (auto &c : vault)
        cout << c.siteName << " | " << c.url << " | " << c.username << endl;
}
