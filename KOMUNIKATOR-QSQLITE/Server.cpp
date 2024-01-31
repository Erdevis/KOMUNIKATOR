#include "Server.h"

Server::Server(QObject *parent) :
    QTcpServer(parent), chatIdCounter(1)
{
}

void Server::startServer()
{
    if(!this->listen(QHostAddress::Any, 4500))
    {
        qDebug() << "Nie mozna uruchomic serwera";
    }
    else
    {
        qDebug() << "Serwer uruchomiony!";
    }
}

void Server::incomingConnection(qintptr socketDescriptor)
{
    QTcpSocket *socket = new QTcpSocket(this);
    socket->setSocketDescriptor(socketDescriptor);

    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));

    qDebug() << socketDescriptor << " Klient połączony";

    sockets.insert(socketDescriptor, socket);
}

Chat* Server::findChatForUser(qintptr userId)
{
    for (Chat* chat : chats) {
        if (chat->hasUser(userId)) {
            return chat;
        }
    }
    return nullptr;
}


QTcpSocket* Server::findSocketForUser(qintptr userId) {
    if(sockets.contains(userId)) {
        return sockets.value(userId);
    }
    return nullptr;
}


void Server::readyRead()
{
    QTcpSocket *socket = (QTcpSocket*)sender();
    QByteArray Data = socket->readAll();

    qDebug() << socket->socketDescriptor() << " Dane odebrane " << Data;

    // Zakładamy, że dane są w formacie "login;haslo;imie;nazwisko"
    QStringList userData = QString(Data).split(";");

    if (userData.size() == 4) {
        QString login = userData[0];
        QString haslo = userData[1];
       // QString imie = userData[2];
        //QString nazwisko = userData[3];

        // Tworzymy nowego użytkownika dla tego połączenia
        User *user = new User(login, haslo);
        users.append(user);


        // Stwórz czat między nowym użytkownikiem a innym użytkownikiem (jeśli istnieje)
        // Tu trzeba dostosować - na razie zakładamy, że drugi użytkownik istnieje w liście users
        if (users.size() > 1) {
            User* secondUser = users.at(0);  // Pobierz drugiego użytkownika (zmień to, jeśli potrzebujesz innego podejścia)
            createChat(user, secondUser);
        }
    }

    QStringList chatData = QString(Data).split(";");
    if (chatData.size() == 3) {
        qintptr senderId = chatData[0].toInt();
        qintptr receiverId = chatData[1].toInt();
        QByteArray messageText = chatData[2].toUtf8();

        sendMessage(senderId, receiverId, messageText);
    }
}



void Server::createChat(User* user1, User* user2) {
    Chat* chat = new Chat(chatIdCounter++, user1, user2, this);
    chats.append(chat);
}

void Server::sendMessage(qintptr senderId, qintptr receiverId, const QByteArray& message) {
    Chat* chat = findChatForUsers(senderId, receiverId);
    if (chat) {
        chat->send_Mes(message);
    }
}

Chat* Server::findChatForUsers(qintptr userId1, qintptr userId2) {
    for (Chat* chat : chats) {
        if (chat->hasUser(userId1) && chat->hasUser(userId2)) {
            return chat;
        }
    }
    return nullptr;
}


QString Server::findUserNameForId(qintptr userId) {
    for (User* user : users) {
        if (user->getId() == userId) {
           // return user->getFullName();
        }
    }
    return QString();
}

void Server::disconnected()
{
    QTcpSocket *socket = (QTcpSocket*)sender();
    qDebug() << socket->socketDescriptor() << " Rozłączono";
    sockets.remove(socket->socketDescriptor());
}
