#ifndef CLASSLIBRARY_H
#define CLASSLIBRARY_H

#include <list>
#include <string>
#include "classBook.h"
#include "classUser.h"

class Library
{
public:
    // book operations
    bool addBook(std::string, std::string, std::string, std::string, std::string, std::string,
                 std::string, std::string, std::string, std::string, std::string, std::string, std::list<Book>, std::list<Book>);

    bool removeBook(std::string, std::list<Book>, std::list<Book>, std::list<Book>);
    void displayInventory(std::list<Book>, std::list<Book>, std::list<Book>);
    bool checkBook(std::string, std::list<Book>, std::list<Book>);
    bool checkAvailableBook(std::string, std::list<Book>);
    bool checkNotAvailableBook(std::string, std::list<Book>);
    bool updateBook(std::string, std::list<Book>,std::list<Book>,std::list<Book>,std::list<User>);
    void displayBook(std::string, std::list<Book>, std::list<Book>);
    // user operations
    bool addUser(std::string, std::string, std::string, std::string, std::string, std::string, std::string, float, std::list<User>);
    bool removeUser(std::string, std::list<User>);
    bool borrowBook(std::string, std::string, std::list<User>, std::list<Book>, std::list<Book>, std::list<Book>);
    bool returnBook(std::string, std::string, std::list<User>, std::list<Book>, std::list<Book>, std::list<Book>);
    void displayUsers(std::list<User>);
    bool checkUser(std::string, std::list<User>);
    bool displayBorrowedBooks(std::string, std::list<User>);
    bool displayReturnedBooks(std::string, std::list<User>);
    bool displayCurrentBooks(std::string, std::list<User>);
    bool addCredit(std::string, float, std::list<User>);
    bool checkCurrentBook(std::string, std::string, std::list<User>);
};

#endif // CLASSLIBRARY_H