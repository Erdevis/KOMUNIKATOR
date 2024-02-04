#include "user.h"
#include "qdebug.h"
#include "qsqldatabase.h"
#include "qsqlerror.h"
#include "qsqlquery.h"
#include <QFile>
#include <QTextStream>

size_t User::liczba_instancji = 0;

User::User(QString login,QString haslo)
    :m_login(login),m_haslo(haslo)
{
    m_ID_user = liczba_instancji;
    liczba_instancji++;
}

bool User::log_in(const QString &login, const QString &haslo)const
{
    return (m_login == login && m_haslo == haslo);
}

bool User::saveToFile(const QString &fileName) const
{
    QFile file(fileName);
    if (!file.open(QIODevice::Append | QIODevice::Text))
        return false;

    QTextStream out(&file);
    out << m_login << "\n";
    out << m_haslo << "\n";


    file.close();
    return true;
}

User User::loadFromFile(const QString &fileName)
{
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return User("", ""); // Zwróć pusty obiekt User w przypadku błędu odczytu

    QTextStream in(&file);
    QString login = in.readLine();
    QString haslo = in.readLine();


    file.close();
    return User(login, haslo);
}

QVector<User> User::loadAllFromFile(const QString &fileName)
{
    QVector<User> users;

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return users; // Zwróć pusty wektor w przypadku błędu odczytu

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString login = in.readLine();
        QString haslo = in.readLine();
        // Odczytaj pozostałe dane i utwórz obiekt User
        User user(login, haslo);
        // Dodaj użytkownika do wektora
        users.append(user);

    }

    file.close();
    return users;
}

bool User::userExists(const QVector<User> &users, const QString &login, const QString &haslo)
{
    for (const User &user : users)
    {
        if (user.log_in(login, haslo))
        {
            return true;
        }
    }
    return false;
}


bool User::saveToDatabase()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("Server_KOMUNIKATOR_Proj_PK\\UsersLogs.db");
    if (!db.open())
    {
        qDebug() << "Error: connection with database fail";
        return false;
    }
    else
    {
        qDebug() << "Database: connection ok";
    }

    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT * FROM users WHERE username = :username");
    checkQuery.bindValue(":username", m_login);
    if (checkQuery.exec() && checkQuery.next()) {
        qDebug() << "User already exists: " << m_login;
        return false;
    }

    QSqlQuery query;
    query.prepare("INSERT INTO users (username, password) "
                  "VALUES (:username, :password)");
    query.bindValue(":username", m_login);
    query.bindValue(":password", m_haslo);

    if(!query.exec())
    {
        qDebug() << "Error: " << query.lastError();
        db.close();
        return false;
    }

    //db.close();
    return true;
}



User::~User()
{
}
