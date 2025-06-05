//
// Created by abdo on 3/17/25.
//

#ifndef BOOKMANAGEMENT_H
#define BOOKMANAGEMENT_H
#include "Book.h"
#include <list>

class BookManagement {

    std::list<Book> Books;

public:

    BookManagement() = default;
    bool addBook(const Book& book);
    std::list<Book>::iterator getBook(int id);
    bool removeBook(int id);
    bool isBookExist(int id) const;
    const std::list<Book>& getBooks() const;

};


#endif //BOOKMANAGEMENT_H
