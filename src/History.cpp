#include "History.h"

void History::push(string site, string pass)
{
    hist[site].push(pass);
}

string History::undo(string site)
{
    if (hist[site].empty())
        return "";

    string p = hist[site].top();
    hist[site].pop();
    return p;
}
