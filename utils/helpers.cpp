#include "helpers.h"

string getTime()
{
    time_t now = time(0);
    string dt = ctime(&now);
    return dt;
}

bool isValidSite(string site)
{
    regex pattern("^[a-zA-Z0-9.-]+$");
    return regex_match(site, pattern);
}

void pressEnter()
{
    cout << "\nPress Enter to continue...";
    cin.ignore();
    cin.get();
}
