#include "message.h"

size_t Message::liczba_instancji=0;

Message::Message(const QString& userName,const QString& text, const QDateTime& timestamp = QDateTime::currentDateTime())
    : m_userName(userName), m_text(text), m_timestamp(timestamp)
{
    m_ID_mess=liczba_instancji;
    liczba_instancji++;
}



