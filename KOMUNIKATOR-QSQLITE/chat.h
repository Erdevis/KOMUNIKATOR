#ifndef CHAT_H
#define CHAT_H
#include "message.h"
#include "user.h"
#include <QVector>
#include <QString>
#include <QtNetwork/QTcpSocket>
#include <QFile>
#include <QTextStream>
#include <QDateTime>

class Server;


class Chat
{
private:
    size_t m_ID_chat;
    QVector<Message> m_chat_list;
     Server* server;

protected:
     QVector<User*> m_users;
    virtual void addUser(User* user);
public:
    //metoda
    Chat(size_t chatID, User* user1, User* user2, Server* server);
    //void send_Mes(const QByteArray &message);
    bool hasUser(qintptr userId);
    void writeToFile();
    void readFromFile();

    void send_Mes(const QByteArray &message);
    void addMessage(const Message& message);

};

#endif // CHAT_H







