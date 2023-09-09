#include <iostream>
#include <string>
#include <list>
#include <conio.h>

#include "classUser.h"
#include "classBook.h"
#include "classLibrary.h"

const char one = 66;
const char two = 70;

using namespace std;

list<User> userList;
list<Book> allBooks;
list<Book> availableBooks;
list<Book> notAvailableBooks;

void menuEntry();
void menuLogin();
void menuAdmin();
void menuUser();
void menuFree();
void bookOperations(string);
void userOperations();
void importData();
void exportData();
void checkBook();
void addBook();

Library defLib;
User defUser("Def", "1234", "def@defmail.com", "+905554443322", "Turkey", "admin", "0", 0);
int main()
{
    menuEntry();
    return 0;
}

void menuEntry()
{
    int choice;
    cout << "Welcome to the Library Management System" << endl;
    cout << "Please choose an option:" << endl;
    cout << "1. Login" << endl;
    cout << "2. Exit" << endl;
    cin >> choice;
    switch (choice)
    {
    case 1:
        menuLogin();
        break;
    case 2:
        exit(0);
        break;
    default:
        cout << "Invalid choice" << endl;
        menuEntry();
        break;
    }
}

void menuLogin()
{
    cout << "Enter your username: ";
    string username;
    cin >> username;
    cout << "Enter your password: ";
    char inputChar;
    string inputPassword = "";

    while (true)
    {
        inputChar = _getch(); // Read a character without displaying it
        if (inputChar == 13)  // Enter key
            break;
        inputPassword += inputChar;
        cout << '*'; // Display an asterisk for each character entered
    }

    User user;
    int loginStatus = user.login(username, inputPassword, userList);
    switch (loginStatus)
    {
    case 0:
        cout << "You've logged as an admin!" << endl;
        cout << "User Name: " << user.name << endl;
        menuAdmin();
        break;
    case 1:
        cout << "You've logged as an User!" << endl;
        cout << "User Name: " << user.name << endl;
        menuUser();
        break;
    case 2:
        menuFree();
        break;
    case -1:
        cout << "Invalid username or password!" << endl;
        menuLogin();
        break;
    default:
        cout << "Error!" << endl;
        menuEntry();
        break;
    }
}

void menuAdmin()
{
    cout << "1. Book Operations " << endl;
    cout << "2. User Operations " << endl;
    cout << "3. Import Data " << endl;
    cout << "4. Export Data" << endl;
    cout << "0. Log Out" << endl;
    cout << "Please Choose: ";
    int choice;
    cin >> choice;

    if (choice == 1)
    {
        bookOperations("admin");
    }
    else if (choice == 2)
    {
        userOperations();
    }
    else if (choice == 3)
    {
        importData();
    }
    else if (choice == 4)
    {
        exportData();
    }
    else if (choice == 0)
    {
        menuLogin();
    }
    else
    {
        cout << "Invalid Choice. Try Again." << endl;
        menuAdmin();
    }
}

void menuUser()
{
    cout << "1.Book Operations" << endl;
    cout << "2. Export" << endl;
    cout << "0. Logout" << endl;
    cout << "Please Choose: ";
    int choose;
    cin >> choose;

    if (choose == 1)
    {
        bookOperations("user");
    }
    else if (choose == 2)
    {
        exportData();
    }
    else if (choose == 0)
    {
        cout << "You've logged out" << endl;
        menuLogin();
    }
    else
    {
        cout << "Incorrect input. Please try again." << endl;
        menuUser();
    }
}

void menuFree()
{
    cout << "1. Book Operations" << endl;
    cout << "0. Logout" << endl;
    cout << "Please choose: ";
    int choice;
    cin >> choice;

    if (choice == 1)
    {
        bookOperations("free");
    }
    else if (choice == 0)
    {
        cout << "You've logged out" << endl;
        menuLogin();
    }
    else
    {
        cout << "Incorrect input. Please try again." << endl;
        menuFree();
    }
}

void bookOperations(string userType)
{
    int i = 1;
    cout << i++ << ". Display Inventory" << endl;
    cout << i++ << ". Check book" << endl;
    // if admin
    if (userType == "admin")
    {
        cout << i++ << ". Add Book" << endl;
        cout << i++ << ". Remove Book" << endl;
    }
    cout << "Please choose: ";
    int choice;
    cin >> choice;

    if (choice == 1)
    {
        defLib.displayInventory(allBooks, availableBooks, notAvailableBooks);
    }
    else if (choice == 2)
    {
        std::cout << "ISBN: " << std::endl;
        std::string isbn_;
        std::cin >> isbn_;
        if (defLib.checkBook(isbn_, allBooks, availableBooks) == true)
        {
            if (defLib.checkAvailableBook(isbn_, availableBooks) == true)
            {
                std::cout << "Book is available!" << std::endl;
            }
            else
            {
                std::cout << "Book is borrowed by someone else!" << std::endl;
            }
        }
        else
        {
            std::cout << "Book is not available!" << std::endl;
        }
    }
    else if ((choice == 3) && (userType == "admin"))
    {
        std::cout << "Name: " << std::endl;
        std::string name_;
        std::cin >> name_;
        std::cout << "Author: " << std::endl;
        std::string author_;
        std::cin >> author_;
        std::cout << "Publisher: " << std::endl;
        std::string publisher_;
        std::cin >> publisher_;
        std::cout << "ISBN: " << std::endl;
        std::string isbn_;
        std::cin >> isbn_;
        std::cout << "Edition: " << std::endl;
        std::string edition_;
        std::cin >> edition_;
        std::cout << "Language: " << std::endl;
        std::string language_;
        std::cin >> language_;
        std::cout << "Pages: " << std::endl;
        std::string pages_;
        std::cin >> pages_;
        std::cout << "Price: " << std::endl;
        std::string price_;
        std::cin >> price_;
        std::cout << "Category: " << std::endl;
        std::string category_;
        std::cin >> category_;
        std::cout << "Publication Date: " << std::endl;
        std::string publicationDate_;
        std::cin >> publicationDate_;
        std::cout << "Description: " << std::endl;
        std::string description_;
        std::cin >> description_;
        std::cout << "Quantity: " << std::endl;
        std::string quantity_;
        std::cin >> quantity_;

        if (defLib.addBook(isbn_, ) == true)
        {
            std::cout << "Book added successfully!" << std::endl;
        }
        else
        {
            std::cout << "Book couldn't be added!" << std::endl;
        }
    }
    else if ((choice == 4) && (userType == "admin"))
    {
        std::cout << "ISBN: " << std::endl;
        std::string isbn_;
        std::cin >> isbn_;
        defLib.removeBook(isbn_, allBooks, availableBooks, notAvailableBooks);
    }
}

void userOperations()
{
}

void importData()
{
}

void exportData()
{
}