//
// Created by abdo on 3/17/25.
//

#include "../include/BookManagement.h"
#include <algorithm>

bool BookManagement::isBookExist(int id)const {
    return std::ranges::any_of(Books ,
        [id] (const auto & book) {return book.getId() == id;});

}

bool BookManagement::addBook(const Book &book) {
    if (isBookExist(book.getId()))
        return false;

    Books.push_back(book);
    return true;
}

std::list<Book>::iterator BookManagement::getBook(int id){
    return std::ranges::find_if(Books,
        [id](const Book& book) { return book.getId() == id; });
}

const std::list<Book>& BookManagement::getBooks() const{
    return Books;
}

bool BookManagement::removeBook(int id) {
     auto it = getBook(id);
     if (it == Books.end()) return false;

     Books.erase(it);
     return true;
}
