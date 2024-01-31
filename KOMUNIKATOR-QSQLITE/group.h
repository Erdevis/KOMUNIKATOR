#ifndef GROUP_H
#define GROUP_H

#include "user.h"
#include "chat.h"
#include <QString>
#include <QVector>
class Group : public Chat
{
private:
    QString m_groupName;
    QVector<User*> m_user_list;

public:

public:
    Group(size_t chatID, User* user1, User* user2, Server* server, const QString& groupName);

    //metody
    void changeGroupName(const QString& newGroupName);
    void addUser(User* user) override;
    void removeUser(User* user);

};

#endif // GROUP_H


