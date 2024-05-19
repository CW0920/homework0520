#include <iostream>
#include "Administrator.h"
#include "User.h"

int main()
{
    User user;
    Administrator admin;
    string username, userpassword;
    cin >> username;
    cin >> userpassword;

    if (user.Login(username, userpassword)) {
        cout << "User login successful." << endl;
    }
    else {
        cout << "User login failed." << endl;
    }

    string adminname, adminpassword;
    cin >> adminname;
    cin >> adminpassword;

    if (admin.Login(adminname, adminpassword)) {
        cout << "Administrator login successful." << endl;
    }
    else {
        cout << "Administrator login failed." << endl;
    }

    return 0;
}