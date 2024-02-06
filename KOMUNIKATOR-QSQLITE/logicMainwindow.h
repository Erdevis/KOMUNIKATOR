#ifndef LOGICMAINWINDOW_H
#define LOGICMAINWINDOW_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include "User.h"
#include <QObject>
#include "programwindow.h"


class MainWindow;

class MainWindowLogic : public QObject
{
    Q_OBJECT

public:
    MainWindowLogic(MainWindow* mainWindow);
    QVector<User> loadAllFromDatabase();
    User* loginUser(const QString& login, const QString& password);
    void openDatabase();
    void openProgramWindow(User* user);
    void openRegisterWindow();

private:
    QSqlDatabase db;
    ProgramWindow *m_oknoProgramW;
    MainWindow* m_mainWindow;
};

#endif // LOGICMAINWINDOW_H
