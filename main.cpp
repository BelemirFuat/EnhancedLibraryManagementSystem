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

User defUser("Def", "1234", "def@defmail.com", "+905554443322", "Turkey", "admin", "0",0);
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
    cout<<"Enter your username: ";
    string username;
    cin>>username;
    cout<<"Enter your password: ";
    char inputChar;
    string inputPassword = "";

    while (true) {
        inputChar = _getch(); // Read a character without displaying it
        if (inputChar == 13) // Enter key
            break;
        inputPassword += inputChar;
        cout << '*'; // Display an asterisk for each character entered
    }

    User user;
    int loginStatus = user.login(username, inputPassword, userList);
    switch (loginStatus)
    {
    case 0:
        menuAdmin();
        break;
    case 1:
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