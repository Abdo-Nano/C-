//
// Created by abdo on 3/24/25.
//

#ifndef MEMBER_H
#define MEMBER_H

#include <iostream>

class Member {
    std::string name;
    int phoneNumber{};
    int id{};

public:

    Member() = default;

    Member(const std::string & name , int phoneNumber , int id):
    name(name) , phoneNumber(phoneNumber) ,id(id){}

    int getId()const;
    bool operator==(const Member &member) const;
};

#endif //MEMBER_H
