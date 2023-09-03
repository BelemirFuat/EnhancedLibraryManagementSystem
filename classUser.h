#ifndef CLASSUSER_H
#define CLASSUSER_H

#include <list>
#include <string>
#include "classBook.h"

class User
{
public:
    std::string name;
    std::string password;
    std::string email;
    std::string phone;
    std::string address;
    std::string type;
    std::string userID;
    float credit;

    std::list<Book> borrowedBooks;
    std::list<Book> returnedBooks;
    std::list<Book> currentBooks;

    User(std::string name_ = "", std::string password_= "", std::string email_= "", std::string phone_= "", std::string address_= "",
         std::string type_= "", std::string userID_= "", float credit_ = 0)
    {
        name = name_;
        password = password_;
        email = email_;
        phone = phone_;
        address = address_;
        type = type_;
        userID = userID_;
        credit = credit_;
    }
    bool operator==(const User &other) const
    {
        return userID == other.userID;
    }

    int login(std::string, std::string, std::list<User>);//0 = admin, 1 = user, -1 = invalid
};

#endif // CLASSUSER_H