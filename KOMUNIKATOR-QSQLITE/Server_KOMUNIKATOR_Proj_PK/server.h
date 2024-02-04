#ifndef SERVER_H
#define SERVER_H

#include <QtNetwork/QTcpServer>
#include <QtNetwork/QTcpSocket>
#include <QMap>
#include <QtSql>
#include "qsqlerror.h"
#include "qsqlquery.h"

class Server : public QTcpServer
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = nullptr);
    void startServer();
    void addUser(const QString &username, const QString &password);
    void createDatabase();
    void removeUser(const QString &username);


signals:
    void updatedUserList(const QStringList &users);

protected:
    void incomingConnection(qintptr socketDescriptor) override;

private slots:
    void readyRead();
    void disconnected();

private:
    QStringList getUserList();
    QMap<int, QTcpSocket*> sockets; // Zmieniamy klucz na int
    int nextId = 1; // Dodajemy licznik
    QSqlDatabase DbConnection;

};

#endif // SERVER_H
