#ifndef HISTORY_H
#define HISTORY_H

#include <stack>
#include <map>
#include <string>
using namespace std;

class History
{
    map<string, stack<string>> hist;

public:
    void push(string site, string pass);
    string undo(string site);
};

#endif
