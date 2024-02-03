#ifndef USER_H
#define USER_H
#include "friend_list.h"
#include <QString>

class User
{

private:
    static size_t liczba_instancji;
    size_t m_ID_user;
    QString m_imie;
    QString m_nazwisko;
    QString m_login;
    QString m_haslo;
    Friend_list m_friend_list;
public:
    User(QString m_login, QString m_haslo);
    size_t getId(){return m_ID_user;}
    QString getLogin() const { return m_login; }
    QString getPassword() const { return m_haslo; }

    //metody
    bool log_in(const QString& login,const QString& haslo)const;

    void addFriend(size_t friendID);
    void deleteFirend(size_t friendID);

    //zapis do pliku
    bool saveToFile(const QString &fileName) const;
    bool saveToDatabase();

    static User loadFromFile(const QString &fileName);
   // QVector<User>loadAllFromFile(const QString &fileName);
    static QVector<User> loadAllFromFile(const QString &fileName);
    static bool userExists(const QVector<User> &users, const QString &login,const QString &haslo);

    ~User();
};

#endif // USER_H
