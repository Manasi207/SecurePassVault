#include "Storage.h"
#include "security/AESManager.h"
#include <fstream>
#include <sstream>

void Storage::saveVault(vector<Credential> &creds)
{
    ofstream file("data/vault.dat");
    AESManager aes;

    for (auto &c : creds)
    {
        file << c.siteName << ","
             << c.url << ","
             << c.username << ","
             << aes.encrypt(c.encPassword) << "\n";
    }
    file.close();
}

vector<Credential> Storage::loadVault()
{
    vector<Credential> creds;
    ifstream file("data/vault.dat");
    AESManager aes;
    string line;

    while (getline(file, line))
    {
        stringstream ss(line);
        string site, url, user, pass;

        getline(ss, site, ',');
        getline(ss, url, ',');
        getline(ss, user, ',');
        getline(ss, pass, ',');

        creds.push_back(Credential(site, url, user, aes.decrypt(pass)));
    }

    file.close();
    return creds;
}
