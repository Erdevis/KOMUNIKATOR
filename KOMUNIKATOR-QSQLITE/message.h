#ifndef MESSAGE_H
#define MESSAGE_H


#include <QString>
#include <QVector>
#include <QDateTime>

class Message
{
private:
    static size_t liczba_instancji;
    size_t m_ID_mess;
    QString m_text;
    QDateTime m_timestamp;
    QString m_userName;

public:
    Message(const QString& userName,const QString& text,const QDateTime& timestamp);
    QString getText() const {return m_text;}
    QDateTime getTimestamp() const {return m_timestamp;}
    QString getUserName()const {return m_userName;}
    //metody
};

#endif // MESSAGE_H




