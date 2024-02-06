#include "logicregisterwindow.h"
#include <QMessageBox>

LogicRegisterWindow::LogicRegisterWindow(QObject *parent) : QObject(parent)
{
}

User* LogicRegisterWindow::createUserFromInput(const QString &login, const QString &password, const QString &repeatPassword)
{
    if(password != repeatPassword)
    {
        QMessageBox mesBox;
        mesBox.setText("NIEPRAWIDLOWE HASLO");
        mesBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Close);
        mesBox.setIcon(QMessageBox::Warning);
        mesBox.exec();
        return nullptr;
    }
    return new User(login,password);
}

void LogicRegisterWindow::on_cancel_clicked()
{
    emit nieRejestruj();
}


bool LogicRegisterWindow::on_zaloguj_clicked(const QString &login, const QString &password, const QString &repeatPassword)
{
    User* newUser = createUserFromInput(login, password, repeatPassword);

    if(newUser != nullptr)
    {
        if(newUser->saveToDatabase())
        {
            emit zajerestruj(*newUser);
            return true; // Rejestracja powiodła się
        }
    }
    return false; // Rejestracja nie powiodła się
}


/*
void LogicRegisterWindow::on_zaloguj_clicked(const QString &login, const QString &password, const QString &repeatPassword)
{
    User* newUser = createUserFromInput(login, password, repeatPassword);

    if(newUser != nullptr)
    {
        if(newUser->saveToDatabase())
        {
            emit zajerestruj(*newUser);
        }
    }
}*/
