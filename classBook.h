#ifndef CLASSBOOK_H
#define CLASSBOOK_H

#include <list>
#include <string>

class Book
{

public:
    std::string name;
    std::string author;
    std::string publisher;
    std::string isbn;
    std::string category;
    std::string edition;
    std::string price;
    std::string quantity;
    std::string language;
    std::string pages;
    std::string description;
    std::string publishedDate;

    Book(std::string name_, std::string author_, std::string publisher_, std::string isbn_, std::string category_,
         std::string edition_, std::string price_, std::string quantity_, std::string language_, std::string pages_,
         std::string description_, std::string publishedDate_)
    {
        name = name_;
        author = author_;
        publisher = publisher_;
        isbn = isbn_;
        category = category_;
        edition = edition_;
        price = price_;
        quantity = quantity_;
        language = language_;
        pages = pages_;
        description = description_;
        publishedDate = publishedDate_;
    }

    bool operator==(const Book &other) const
    {
        return isbn == other.isbn;
    }
};

#endif // CLASSBOOK_H