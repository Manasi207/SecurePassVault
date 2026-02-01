
#ifndef AUTH_H
#define AUTH_H

#include <string>
using namespace std;

class Auth
{
public:
    bool registerMaster(string pass);
    bool login(string pass);
    bool loginFlow();
};

#endif
