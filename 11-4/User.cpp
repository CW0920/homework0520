#include "User.h"
#include "Security.h"

bool User::Login(string username, string password)
{
    int result = Security::validate(username, password);
    return (result == 1 || result == 2);
}