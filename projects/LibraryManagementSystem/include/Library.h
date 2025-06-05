//
// Created by abdo on 3/21/25.
//

#ifndef LIBRARY_H
#define LIBRARY_H


#include <list>
#include <unordered_map>
#include "Book.h"
#include "Member.h"
#include "BookManagement.h"
#include "MemberManagement.h"
#include <algorithm>


/*
 * ========= Some Edited Mistakes =============
 * - Use the Initializer List for efficient code
 * - Exit = get out while Exists means found
 * - when you come to use a user defined object a the key in hash table , Then you have two choices:
 *  - Either you create a separate class/struct(Functor) (preferred (readable , easier)
 *      - and define inside it the hash function
 *  - or use the lambda expression , but it should be static and initialized outside th class
 *      - static auto hash = [](const Member& m) { return std::hash<int>{}(m.getId()); };
 *
 */


struct MemberHasher {
    size_t operator()(const Member& m) const {
        return std::hash<int>{}(m.getId());
    }
};

class Library {

    std::unordered_map<Member, std::list<Book> , MemberHasher> library;
    BookManagement books;
    MemberManagement members;
    bool removeBookFromMember(const Member & member , int bookId);

public:

    Library(BookManagement& books,MemberManagement&  members)
        : books(books), members(members){}

    bool isBookExist(int id);
    bool isMemberExist(int id);
    void borrowBookForMember(const Member & member ,const Book & book) ;
    const std::unordered_map<Member , std::list<Book> , MemberHasher>& getMembersAndBorrowedBooks() const;
    bool returnBook(int memberId , int bookId);

};


#endif //LIBRARY_H
