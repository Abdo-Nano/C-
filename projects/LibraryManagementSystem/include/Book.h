//
// Created by abdo on 3/17/25.
//

#ifndef BOOK_H
#define BOOK_H

#include <iostream>

class Book {

    int id{};
    std::string title;
    std::string author;
    std::string publisher;
    bool availabilityStatus{};

public:

    Book() = default;
    Book(int id , const std::string &title , const std::string & author ,
        const std::string & publisher):
    id(id) , title(title) , author(author) , publisher(publisher) , availabilityStatus(true){}

    [[nodiscard]] int getId() const;
    [[nodiscard]] std::string getTitle() const;
    void setStatusAsUnavailable();
    void setStatusAsAvailable();
    [[nodiscard]] bool isBookAvailable() const;

};



#endif //BOOK_H
