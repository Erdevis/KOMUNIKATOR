#include "friend_list.h"

Friend_list::Friend_list(size_t userID)
    :m_ID_user(userID)
{

}

void Friend_list::addFriend(size_t friendID)
{
    m_ID_friend.push_back(friendID);
}

void Friend_list::deleteFirend(size_t friendID)
{
    int index = m_ID_friend.indexOf(friendID);

    if(index != -1)
        m_ID_friend.remove(index);
}


