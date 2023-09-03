#include "classLibrary.h"
#include "classBook.h"
#include <iostream>
#include <string>
#include <list>
// book operations
bool Library::addBook(std::string name_, std::string author_, std::string publisher_, std::string isbn_, std::string category_,
                      std::string edition_, std::string price_, std::string quantity_, std::string language_, std::string pages_,
                      std::string description_, std::string publishedDate_, std::list<Book> allBooks, std::list<Book> availableBooks)
{
    if (checkBook(isbn_, allBooks, availableBooks) == false)
    {
        Book newBook(name_, author_, publisher_, isbn_, category_, edition_, price_, quantity_, language_, pages_, description_, publishedDate_);
        allBooks.push_back(newBook);
        availableBooks.push_back(newBook);
        return true;
    }
    else
    {
        return false; // there is already that book in the inventory
    }
}

bool Library::removeBook(std::string isbn_, std::list<Book> allBooks, std::list<Book> availableBooks, std::list<Book> notAvailableBooks)
{
    if (checkBook(isbn_, allBooks, availableBooks) == true)
    {
        for (auto it : allBooks)
        {
            if (it.isbn == isbn_)
            {
                allBooks.remove(it);
                availableBooks.remove(it);
                notAvailableBooks.remove(it);
                break;
            }
        }
        return true;
    }
    else
    {
        return false; // there's no book with this isbn
    }
}
void Library::displayInventory(std::list<Book> allBooks, std::list<Book> availableBooks, std::list<Book> notAvailableBooks)
{
    std::cout << "All books: " << std::endl;
    for (auto it : allBooks)
    {
        std::cout << it.name << std::endl;
        std::cout << it.author << std::endl;
        std::cout << it.publisher << std::endl;
        std::cout << it.isbn << std::endl;
        std::cout << it.category << std::endl;
        std::cout << it.edition << std::endl;
        std::cout << it.price << std::endl;
        std::cout << it.quantity << std::endl;
        std::cout << it.language << std::endl;
        std::cout << it.pages << std::endl;
        std::cout << it.description << std::endl;
        std::cout << it.publishedDate << std::endl;
    }
    std::cout << "Available books: " << std::endl;
    for (auto it : availableBooks)
    {
        std::cout << it.name << std::endl;
        std::cout << it.author << std::endl;
        std::cout << it.publisher << std::endl;
        std::cout << it.isbn << std::endl;
        std::cout << it.category << std::endl;
        std::cout << it.edition << std::endl;
        std::cout << it.price << std::endl;
        std::cout << it.quantity << std::endl;
        std::cout << it.language << std::endl;
        std::cout << it.pages << std::endl;
        std::cout << it.description << std::endl;
        std::cout << it.publishedDate << std::endl;
    }
    std::cout << "Not available books: " << std::endl;
    for (auto it : notAvailableBooks)
    {
        std::cout << it.name << std::endl;
        std::cout << it.author << std::endl;
        std::cout << it.publisher << std::endl;
        std::cout << it.isbn << std::endl;
        std::cout << it.category << std::endl;
        std::cout << it.edition << std::endl;
        std::cout << it.price << std::endl;
        std::cout << it.quantity << std::endl;
        std::cout << it.language << std::endl;
        std::cout << it.pages << std::endl;
        std::cout << it.description << std::endl;
        std::cout << it.publishedDate << std::endl;
    }
}
bool Library::checkBook(std::string isbn_, std::list<Book> allBooks_, std::list<Book> avaiableBooks)
{
    for (auto it : allBooks_)
    {
        if (it.isbn == isbn_)
        {
            return true;
        }
    }
    return false;
}
bool Library::checkAvailableBook(std::string isbn_, std::list<Book> availableBooks_)
{
    for (auto it : availableBooks_)
    {
        if (it.isbn == isbn_)
        {
            return true;
        }
    }
    return false;
}
bool Library::checkNotAvailableBook(std::string isbn_, std::list<Book> notAvailableBooks_)
{
    for (auto it : notAvailableBooks_)
    {
        if (it.isbn == isbn_)
        {
            return true;
        }
    }
    return false;
}

// user operations
bool Library::addUser(std::string name, std::string password, std::string email, std::string phone, std::string address, std::string type, std::string userID, float credit, std::list<User> allUsers)
{
    if (checkUser(userID, allUsers) == false)
    {
        User newUser(name, password, email, phone, address, type, userID, credit);
        allUsers.push_back(newUser);
        return true;
    }
    else
    {
        return false; // there is already that user in the system
    }
}
bool Library::removeUser(std::string userID, std::list<User> allUsers)
{
    if (checkUser(userID, allUsers) == true)
    {
        for (auto it : allUsers)
        {
            if (it.userID == userID)
            {
                allUsers.remove(it);
                break;
            }
        }
        return true;
    }
    else
    {
        return false; // there's no user with this userID
    }
}
bool Library::borrowBook(std::string isbn, std::string userID, std::list<User> allUsers, std::list<Book> allBooks, std::list<Book> availableBooks, std::list<Book> notAvailableBooks)
{
    if (checkUser(userID, allUsers) == true)
    {
        if (checkBook(isbn, allBooks, availableBooks) == true)
        {
            if (checkAvailableBook(isbn, availableBooks) == true)
            {
                for (auto it : allUsers)
                {
                    if (it.userID == userID)
                    {
                        for (auto it2 : allBooks)
                        {
                            if (it2.isbn == isbn)
                            {
                                it.borrowedBooks.push_back(it2);
                                it.currentBooks.push_back(it2);
                                it.credit -= std::stof(it2.price);
                                break;
                            }
                        }
                        break;
                    }
                }
                for (auto it : allBooks)
                {
                    if (it.isbn == isbn)
                    {
                        availableBooks.remove(it);
                        notAvailableBooks.push_back(it);
                        break;
                    }
                }
                return true;
            }
            else
            {
                return false; // the book is not available
            }
        }
        else
        {
            return false; // there's no book with this isbn
        }
    }
    else
    {
        return false; // there's no user with this userID
    }
}
bool Library::returnBook(std::string userID, std::string isbn, std::list<User> allUsers, std::list<Book> allBooks, std::list<Book> availableBooks, std::list<Book> notAvailableBooks)
{
    if (checkUser(userID, allUsers) == true)
    {
        if (checkNotAvailableBook(isbn, notAvailableBooks) == true)
        {
            if (checkCurrentBook(userID, isbn, allUsers) == true)
            {
                for (auto it : allUsers)
                {
                    if (it.userID == userID)
                    {
                        for (auto it2 : allBooks)
                        {
                            if (it2.isbn == isbn)
                            {
                                it.returnedBooks.push_back(it2);
                                it.currentBooks.remove(it2);
                                break;
                            }
                        }
                        break;
                    }
                }
                for (auto it : allBooks)
                {
                    if (it.isbn == isbn)
                    {
                        notAvailableBooks.remove(it);
                        availableBooks.push_back(it);
                        break;
                    }
                }
                return true;
            }
            else
            {
                return false; // the user didn't borrow this book
            }
        }
    }
}
void Library::displayUsers(std::list<User> allUsers)
{
    for (auto it : allUsers)
    {
        std::cout << "Name: " << it.name << std::endl;
        std::cout << "Password: " << it.password << std::endl;
        std::cout << "Email: " << it.email << std::endl;
        std::cout << "Phone: " << it.phone << std::endl;
        std::cout << "Address: " << it.address << std::endl;
        std::cout << "Type: " << it.type << std::endl;
        std::cout << "UserID: " << it.userID << std::endl;
        std::cout << "Credit: " << it.credit << std::endl;
    }
}
bool Library::checkUser(std::string userID, std::list<User> allUsers)
{
    for (auto it : allUsers)
    {
        if (it.userID == userID)
        {
            return true;
        }
    }
    return false;
}
bool Library::displayBorrowedBooks(std::string userID, std::list<User> allUsers)
{
    for (auto it : allUsers)
    {
        if (it.userID == userID)
        {
            for (auto it2 : it.borrowedBooks)
            {
                std::cout << "Name: " << it2.name << std::endl;
                std::cout << "Author: " << it2.author << std::endl;
                std::cout << "Category: " << it2.category << std::endl;
                std::cout << "Pages: " << it2.pages << std::endl;
                std::cout << "Description: " << it2.description << std::endl;
                std::cout << "Price: " << it2.price << std::endl;
                std::cout << "Publisher: " << it2.publisher << std::endl;
                std::cout << "ISBN: " << it2.isbn << std::endl;
                std::cout << "Edition: " << it2.edition << std::endl;
                std::cout << "Quantity: " << it2.quantity << std::endl;
                std::cout << "Language: " << it2.language << std::endl;
                std::cout << "Published date: " << it2.publishedDate << std::endl;
            }
            break;
        }
    }
    return false;
}
bool Library::displayReturnedBooks(std::string userID, std::list<User> allUsers)
{
    for (auto it : allUsers)
    {
        if (it.userID == userID)
        {
            for (auto it2 : it.returnedBooks)
            {
                std::cout << "Name: " << it2.name << std::endl;
                std::cout << "Author: " << it2.author << std::endl;
                std::cout << "Category: " << it2.category << std::endl;
                std::cout << "Pages: " << it2.pages << std::endl;
                std::cout << "Description: " << it2.description << std::endl;
                std::cout << "Price: " << it2.price << std::endl;
                std::cout << "Publisher: " << it2.publisher << std::endl;
                std::cout << "ISBN: " << it2.isbn << std::endl;
                std::cout << "Edition: " << it2.edition << std::endl;
                std::cout << "Quantity: " << it2.quantity << std::endl;
                std::cout << "Language: " << it2.language << std::endl;
                std::cout << "Published date: " << it2.publishedDate << std::endl;
            }
            break;
        }
    }
    return false;
}
bool Library::displayCurrentBooks(std::string userID, std::list<User> allUsers)
{
    for (auto it : allUsers)
    {
        if (it.userID == userID)
        {
            for (auto it2 : it.currentBooks)
            {
                std::cout << "Name: " << it2.name << std::endl;
                std::cout << "Author: " << it2.author << std::endl;
                std::cout << "Category: " << it2.category << std::endl;
                std::cout << "Pages: " << it2.pages << std::endl;
                std::cout << "Description: " << it2.description << std::endl;
                std::cout << "Price: " << it2.price << std::endl;
                std::cout << "Publisher: " << it2.publisher << std::endl;
                std::cout << "ISBN: " << it2.isbn << std::endl;
                std::cout << "Edition: " << it2.edition << std::endl;
                std::cout << "Quantity: " << it2.quantity << std::endl;
                std::cout << "Language: " << it2.language << std::endl;
                std::cout << "Published date: " << it2.publishedDate << std::endl;
            }
            break;
        }
    }
    return false;
}
bool Library::addCredit(std::string userID, float price, std::list<User> allUsers)
{
    for (auto it : allUsers)
    {
        if (it.userID == userID)
        {
            it.credit += price;
            return true;
        }
    }
    return false;
}
bool Library::checkCurrentBook(std::string userID, std::string isbn, std::list<User> allUsers)
{
    for (auto it : allUsers)
    {
        if (it.userID == userID)
        {
            for (auto it2 : it.currentBooks)
            {
                if (it2.isbn == isbn)
                {
                    return true;
                }
            }
            break;
        }
    }
    return false;
}