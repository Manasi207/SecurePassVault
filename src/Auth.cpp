#include "Auth.h"
#include <fstream>
#include <functional> // ← CORRECT HEADER instead of <hash>
#include <iostream>

string hashIt(string s)
{
    std::hash<string> h;
    return to_string(h(s));
}

bool Auth::registerMaster(string pass)
{
    ofstream f("data/master.hash");
    f << hashIt(pass);
    f.close();
    return true;
}

bool Auth::login(string pass)
{
    ifstream f("data/master.hash");

    if (!f)
    {
        cout << "No master password found. Create one.\n";
        registerMaster(pass);
        return true;
    }

    string h;
    f >> h;

    return h == hashIt(pass);
}

bool Auth::loginFlow()
{
    string pass;
    cout << "Enter Master Password: ";
    cin >> pass;

    if (login(pass))
    {
        cout << "Login Success!\n";
        return true;
    }

    cout << "Wrong Password!\n";
    return false;
}
