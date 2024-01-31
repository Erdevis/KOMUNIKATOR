#include "chat.h"
#include "Server.h"

Chat::Chat(size_t chatID, User* user1, User* user2, Server* server)
    : m_ID_chat(chatID), server(server)
{
    m_users.push_back(user1);
    m_users.push_back(user2);
}

void Chat::addUser(User* user)
{
    m_users.push_back(user);
}

bool Chat::hasUser(qintptr userId) {
    for (User* user : m_users) {
        if (user->getId() == userId) {
            return true;
        }
    }
    return false;
}

void Chat::send_Mes(const QByteArray &message) {
    for (User* user : m_users) {
        QTcpSocket* socket = server->findSocketForUser(user->getId());
        if (socket) {
            socket->write(message);
        }
    }
}

// Dodaj implementację funkcji addMessage do klasy Chat w pliku Chat.cpp
void Chat::addMessage(const Message& message) {
    m_chat_list.push_back(message);
}


void Chat::writeToFile(){
    QFile file("logs.txt");
    if(file.open(QIODevice::WriteOnly | QIODevice::Text)){
        QTextStream out(&file);
        for (const Message& message : m_chat_list) {
            out << message.getUserName() << "\n";
            out << message.getText() << "\n";
            out << message.getTimestamp().toString("dd-MM-yyyy HH:mm") << "\n";
        }
    }
    file.close();
}

void Chat::readFromFile(){

    QFile file("logs.txt");
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString userName = in.readLine();
            QString text = in.readLine();
            QString dateTimeStr = in.readLine();
            QDateTime dateTime = QDateTime::fromString(dateTimeStr, "dd-MM-yyyy HH:mm");
            Message message(userName,text, dateTime);
            m_chat_list.push_back(message);
        }
        file.close();
    }
}




