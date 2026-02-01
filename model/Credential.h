#ifndef CREDENTIAL_H
#define CREDENTIAL_H

#include <string>
using namespace std;

class Credential
{
public:
    string siteName;
    string url;
    string username;
    string encPassword; // encrypted password

    Credential() {}
    Credential(string s, string u, string user, string pass)
        : siteName(s), url(u), username(user), encPassword(pass) {}
};

#endif
