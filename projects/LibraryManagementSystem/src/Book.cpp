//
// Created by abdo on 3/17/25.
//

#include "../include/Book.h"



int Book::getId() const {
    return this->id;
}

std::string Book::getTitle() const { return this->title; }

void Book::setStatusAsUnavailable() {
    this->availabilityStatus = false;
}

void Book::setStatusAsAvailable() {
    this->availabilityStatus = true;
}

bool Book::isBookAvailable() const { return this->availabilityStatus; }

