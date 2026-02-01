#include "Storage.h"
#include "Encryption.h"
#include <fstream>

void Storage::saveVault(map<string, string> data)
{
    ofstream file("data/vault.dat");
    Encryption enc;

    for (auto &p : data)
    {
        file << p.first << ","
             << enc.encrypt(p.second) << "\n";
    }
    file.close();
}

map<string, string> Storage::loadVault()
{
    ifstream file("data/vault.dat");
    map<string, string> data;
    Encryption enc;

    string line;
    while (getline(file, line))
    {
        int pos = line.find(',');
        string site = line.substr(0, pos);
        string pass = line.substr(pos + 1);

        data[site] = enc.decrypt(pass);
    }
    file.close();
    return data;
}
