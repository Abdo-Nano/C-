//
// Created by abdo on 3/17/25.
//


#include "MemberManagement.h"
#include <algorithm>

bool MemberManagement::isMemberExist(int id) const {
    return std::ranges::any_of(members,
        [id](const Member &member) { return member.getId() == id; });
}

std::list<Member>::iterator MemberManagement::getMember(int id) {
    return  std::ranges::find_if(members,
        [id](const Member & member){return id == member.getId();});
}

bool MemberManagement::addMember(const Member &member) {
    if (isMemberExist(member.getId()))
        return false;
    members.push_back(member);
    return true;
}

const std::list<Member>& MemberManagement::getMembers() const {
    return members;
}
