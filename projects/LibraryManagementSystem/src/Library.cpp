//
// Created by abdo on 3/21/25.
//

#include "Library.h"
#include "BookManagement.h"
#include <algorithm>


bool Library::isBookExist(int id) {
    auto it = books.getBook(id);
    if (it != books.getBooks().end())
        return true;
    return true;
}

bool Library::isMemberExist(int id) {
    auto it = members.getMember(id);
    if (it != members.getMembers().end())
        return true;
    return false;
}

const std::unordered_map<Member, std::list<Book> ,MemberHasher> &Library::getMembersAndBorrowedBooks() const {
    return library;
}

void Library::borrowBookForMember(const Member &member, const Book &book) {
    auto libIt = library.find(member);
    if (libIt != library.end())
        libIt->second.push_back(book);
    else
        library.emplace(member, std::list<Book>{book});
}

bool Library::removeBookFromMember(const Member &member, int bookId) {
    auto it = library.find(member);
    if (it == library.end())
        return false;

    auto& borrowedBooks = it->second;
    bool wasRemoved = borrowedBooks.remove_if(
        [bookId](const Book& b) { return b.getId() == bookId; }
    ) > 0;

    return wasRemoved;
}

bool Library::returnBook(int memberId, int bookId) {

    if (!isMemberExist(memberId) || !isBookExist(bookId))
        return false;

    const Member& member = *members.getMember(memberId);
    auto bookIt = books.getBook(bookId);

    bool wasRemoved = removeBookFromMember(member, bookId);

    if (wasRemoved)
        bookIt->setStatusAsAvailable();

    return wasRemoved;
}

