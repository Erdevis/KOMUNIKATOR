#ifndef MAINWINDOWLOGIC_H
#define MAINWINDOWLOGIC_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include "User.h"
#include <QObject>


class MainWindow;

class MainWindowLogic : public QObject
{
    Q_OBJECT

public:
    MainWindowLogic(MainWindow* mainWindow);
    QVector<User> loadAllFromDatabase();
    User* loginUser(const QString& login, const QString& password);
    void openDatabase();
    void openProgramWindow();
    void openRegisterWindow();

private:
    QSqlDatabase db;
     MainWindow* m_mainWindow;
};

#endif // MAINWINDOWLOGIC_H
