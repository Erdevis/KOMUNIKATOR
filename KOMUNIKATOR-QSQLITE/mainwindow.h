#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//#include "Server.h"
#include "programwindow.h"
#include "registerwindow.h"
#include "mainwindowlogic.h"
#include <QtSql>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void zajerestruj();
    void zaloguj(const User& user);
    QVector<User> loadAllFromDatabase();

private slots:
    void on_btnLogin_clicked();
    void on_btnRejestracja_clicked();

private:
    Ui::MainWindow *ui;
    //Server *server;
    RegisterWindow *m_oknoRegister;
    ProgramWindow *m_oknoProgramW;   
    MainWindowLogic *m_logic;

    User* m_loggedInUser;  // pole przechowujące informacje o zalogowanym użytkowniku

};
#endif // MAINWINDOW_H
