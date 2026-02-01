#include <iostream>
#include "Auth.h"
#include "PasswordManager.h"
#include "Generator.h"
using namespace std;

int main()
{

    Auth auth;
    if (!auth.loginFlow())
        return 0;

    PasswordManager pm;

    while (true)
    {
        cout << "\n1.Add\n2.Get\n3.Search\n4.Generate\n5.List\n6.Exit\nChoice: ";

        int ch;
        cin >> ch;

        string s, p;

        switch (ch)
        {

        case 1:
            cout << "Site:";
            cin >> s;
            cout << "Pass:";
            cin >> p;
            pm.addPassword(s, p);
            break;

        case 2:
            cout << "Site:";
            cin >> s;
            cout << pm.getPassword(s);
            break;

        case 3:
            cout << "Prefix:";
            cin >> s;
            pm.search(s);
            break;

        case 4:
            cout << Generator::generate(12);
            break;

        case 5:
            pm.listAll();
            break;

        case 6:
            exit(0);
        }
    }
}
