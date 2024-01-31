#ifndef SERVER_H
#define SERVER_H

#include <QtNetwork/QTcpServer>
#include <QtNetwork/QTcpSocket>
#include <QMap>
#include "user.h"
#include "chat.h"

class Server : public QTcpServer
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = 0);
    void startServer();
    Chat* findChatForUser(qintptr userId);
    QTcpSocket* findSocketForUser(qintptr userId);
    QString findUserNameForId(qintptr userId);

protected:
    void incomingConnection(qintptr socketDescriptor);

private slots:
    void readyRead();
    void disconnected();

private:
    QMap<qintptr, QTcpSocket*> sockets;
    QVector<User*> users;
    QVector<Chat*> chats;

    void createChat(User* user1, User* user2);
    void sendMessage(qintptr senderId, qintptr receiverId, const QByteArray& message);
    Chat* findChatForUsers(qintptr userId1, qintptr userId2);
    size_t chatIdCounter;

};


#endif // SERVER_H
