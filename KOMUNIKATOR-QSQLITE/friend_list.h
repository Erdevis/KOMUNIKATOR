#ifndef FRIEND_LIST_H
#define FRIEND_LIST_H

#include <QVector>


class Friend_list
{
private:
    size_t m_ID_user;
    QVector<size_t> m_ID_friend;


public:
    Friend_list() = default;
    Friend_list(size_t userID);

     //metody
    void addFriend(size_t friendID);
    void deleteFirend(size_t friendID);

};

#endif // FRIEND_LIST_H


