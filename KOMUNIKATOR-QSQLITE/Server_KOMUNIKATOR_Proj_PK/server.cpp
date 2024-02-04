#include "server.h"

Server::Server(QObject *parent) :
    QTcpServer(parent)
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

    // Symulacja połączenia kilku użytkowników
    for (int i = 1; i <= 5; ++i) {
        incomingConnection(nextId);
    }

    // Symulacja rozłączenia kilku użytkowników
    for (int i = 1; i <= 3; ++i) {
        sockets.remove(i);
        emit updatedUserList(getUserList());
    }
}

void Server::incomingConnection(qintptr socketDescriptor)
{
    QTcpSocket *socket = new QTcpSocket(this);

 if (!socket->setSocketDescriptor(socketDescriptor)) {
        qWarning() << "Nie można ustawić deskryptora gniazda:" << socket->errorString();
        return;
    }
    //socket->setSocketDescriptor(socketDescriptor);

    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));

    qDebug() << socketDescriptor << " Klient połączony";

     sockets.insert(nextId++, socket);

    //sockets.insert(socketDescriptor, socket);

    emit updatedUserList(getUserList());
}

void Server::readyRead()
{
    QTcpSocket *socket = (QTcpSocket*)sender();
    QByteArray Data = socket->readAll();

    qDebug() << socket->socketDescriptor() << " Dane odebrane " << Data;

    // Tutaj możesz dodać logikę do obsługi danych przychodzących od klienta

    // Przesyłanie wiadomości do wszystkich innych klientów
    foreach(QTcpSocket *otherSocket, sockets.values()) {
        if(otherSocket != socket) {
            if(otherSocket->isOpen()) {
                otherSocket->write(Data);
            } else {
                qDebug() << "Socket is not open";
            }
        }
    }
    /*
    foreach(QTcpSocket *otherSocket, sockets.values()) {
        if(otherSocket != socket) {
            otherSocket->write(Data);
        }
    }*/
}

void Server::disconnected()
{
    QTcpSocket *socket = (QTcpSocket*)sender();
    qDebug() << socket->socketDescriptor() << " Klient rozłączony";

    // Usuwamy klienta z listy
    sockets.remove(socket->socketDescriptor());

    // Usuwamy gniazdo
    socket->deleteLater();

    emit updatedUserList(getUserList());
}

/*
void Server::disconnected()
{
    QTcpSocket *socket = (QTcpSocket*)sender();
    qDebug() << socket->socketDescriptor() << " Klient rozłączony";
    sockets.remove(socket->socketDescriptor()); // Usuwamy klienta z listy

     socket->deleteLater(); // Usuwamy gniazdo

    emit updatedUserList(getUserList());

     // Ponownie uruchamiamy nasłuchiwanie serwera
    if(!this->isListening()){

        if(!this->listen(QHostAddress::Any, 4500))
        {
           qDebug() << "Nie mozna uruchomic serwera";
        }
        else
        {
           qDebug() << "Serwer uruchomiony!";
        }
    }
}*/

QStringList Server::getUserList()
{
    QStringList userList;
    foreach (int id, sockets.keys()) { // Zmieniamy deskryptor gniazda na id
        userList << QString::number(id);
    }
    return userList;
    /*
    foreach (qintptr descriptor, sockets.keys()) {
        userList << QString::number(descriptor);
    }
    return userList;*/
}

void Server::addUser(const QString &username, const QString &password)
{
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT * FROM users WHERE username = :username");
    checkQuery.bindValue(":username", username);
    if (checkQuery.exec() && checkQuery.next()) {
        qDebug() << "User already exists: " << username;
        return;
    }

    QSqlQuery insertQuery;
    insertQuery.prepare("INSERT INTO users (username, password) VALUES (:username, :password)");
    insertQuery.bindValue(":username", username);
    insertQuery.bindValue(":password", password);
    if (!insertQuery.exec()) {
        qDebug() << "Error adding user: " << insertQuery.lastError();
    }
}

void Server::createDatabase(){

    DbConnection = QSqlDatabase::addDatabase("QSQLITE");
    DbConnection.setDatabaseName("UsersLogs.db");
    DbConnection.open();

    QSqlQuery query;
    query.prepare("CREATE TABLE IF NOT EXISTS users ("
                  "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                  "username TEXT UNIQUE NOT NULL, "
                  "password TEXT NOT NULL"
                  ")");
    if (!query.exec()) {
        qDebug() << "Error creating table: " << query.lastError();
    }
}

void Server::removeUser(const QString &username)
{
    QSqlQuery query;
    query.prepare("DELETE FROM users WHERE username = :username");
    query.bindValue(":username", username);
    if (!query.exec()) {
        qDebug() << "Error removing user: " << query.lastError();
    }
}
