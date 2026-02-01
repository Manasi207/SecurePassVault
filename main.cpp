#include <iostream>
#include "Auth.h"
#include "PasswordManager.h"
#include "Generator.h"
#include "model/Credential.h"

using namespace std;

int main()
{
    Auth auth;
    if (!auth.loginFlow())
        return 0;

    PasswordManager pm;

    while (true)
    {
        cout << "\n1.Add Credential\n2.View Credential\n3.Edit Credential\n4.Delete Credential\n5.Search\n6.List All\n7.Generate Password\n8.Exit\nChoice: ";
        int ch;
        cin >> ch;

        string site, url, user, pass;
        switch (ch)
        {
        case 1:
            cout << "Site Name: ";
            cin >> site;
            cout << "URL: ";
            cin >> url;
            cout << "Username: ";
            cin >> user;
            cout << "Password: ";
            cin >> pass;
            pm.addCredential(Credential(site, url, user, pass));
            break;
        case 2:
            cout << "Site Name: ";
            cin >> site;
            pm.viewCredential(site);
            break;
        case 3:
            cout << "Site Name: ";
            cin >> site;
            pm.editCredential(site);
            break;
        case 4:
            cout << "Site Name: ";
            cin >> site;
            pm.deleteCredential(site);
            break;
        case 5:
            cout << "Prefix: ";
            cin >> site;
            pm.search(site);
            break;
        case 6:
            pm.listAll();
            break;
        case 7:
            cout << "Generated Password: " << Generator::generate(12) << endl;
            break;
        case 8:
            exit(0);
        }
    }
}
