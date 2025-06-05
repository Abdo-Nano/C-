//
// Created by abdo on 3/17/25.
//

#include "Member.h"


bool Member::operator==(const Member &other) const {
    return other.getId() == id;
}

int Member::getId() const {
    return this->id;
}

