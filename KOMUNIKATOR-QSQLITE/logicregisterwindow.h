#ifndef LOGICREGISTERWINDOW_H
#define LOGICREGISTERWINDOW_H

#include <QObject>
#include "user.h"

class LogicRegisterWindow : public QObject
{
    Q_OBJECT
public:
    explicit LogicRegisterWindow(QObject *parent = nullptr);
    User* createUserFromInput(const QString &login, const QString &password, const QString &repeatPassword);

signals:
    void nieRejestruj();
    void zajerestruj(const User& newUser);

public slots:
    void on_cancel_clicked();
    bool on_zaloguj_clicked(const QString &login, const QString &password, const QString &repeatPassword);
};

#endif // LOGICREGISTERWINDOW_H
