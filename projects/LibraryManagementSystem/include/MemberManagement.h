//
// Created by abdo on 3/17/25.
//

#ifndef MEMBERMANAGEMENT_H
#define MEMBERMANAGEMENT_H

#include <list>
#include "Member.h"


class MemberManagement {

    std::list<Member> members;

public:

    MemberManagement() = default;
    bool addMember(const Member & member);
    std::list<Member>::iterator getMember(int id);
    [[nodiscard]] bool isMemberExist(int id)const ;
    [[nodiscard]] const std::list<Member>& getMembers() const ;
};



#endif //MEMBERMANAGEMENT_H
