#include "classUser.h"
#include "classBook.h"
#include "classLibrary.h"
#include <list>
#include <string>

int User::login(std::string userID_, std::string password_, std::list<User> userList)
{
    for (auto &it : userList)
    {
        if (it.userID == userID_ && it.password == password_)
        {
            if (it.type == "admin")
            {
                return 0;
            }
            else if (it.type == "user")
            {
                return 1;
            }
            else if(it.type =="free")
            {
                return 2;
            }
        }
    }
    return -1;
}