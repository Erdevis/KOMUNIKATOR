#include "group.h"

Group::Group(size_t chatID, User* user1, User* user2, Server* server, const QString& groupName)
    : Chat(chatID, user1, user2,server), m_groupName(groupName)
{

}

void Group::changeGroupName(const QString& newGroupName)
{
    m_groupName = newGroupName;
}

void Group::addUser(User* user)
{
    m_users.push_back(user);
}

void Group::removeUser(User* user)
{
    int index = m_users.indexOf(user);
    if (index != -1)
    {
        m_users.remove(index);
    }
}



