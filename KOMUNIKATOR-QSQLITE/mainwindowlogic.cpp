#include "mainwindowlogic.h"
#include "mainwindow.h"

MainWindowLogic::MainWindowLogic(MainWindow* mainWindow): m_mainWindow(mainWindow)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("Server_KOMUNIKATOR_Proj_PK\\UsersLogs.db");
    bool db_ok = db.open();
    if(db_ok)
        qDebug()<<"smiga";
    else
        qDebug()<<"kaaramba";
}


void MainWindowLogic::openDatabase() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("Server_KOMUNIKATOR_Proj_PK\\UsersLogs.db");
    bool db_ok = db.open();
    if(db_ok)
        qDebug()<<"Database opened successfully";
    else
        qDebug()<<"Failed to open the database";
}

QVector<User> MainWindowLogic::loadAllFromDatabase() {
    QVector<User> users;
    QSqlQuery query("SELECT * FROM users");
    while (query.next()) {
        QString username = query.value("username").toString();
        QString password = query.value("password").toString();
        users.append(User(username, password));
    }
    return users;
}


User* MainWindowLogic::loginUser(const QString& login, const QString& password) {
    QVector<User> users = loadAllFromDatabase();
    for(auto i: users) {
        if(login == i.getLogin()&& password == i.getPassword()) {
            return new User(i);
        }
    }
    return nullptr;
}


// MainWindowLogic.cpp
void MainWindowLogic::openProgramWindow()
{
    m_mainWindow->hide();

    ProgramWindow *m_oknoProgramW = new ProgramWindow(nullptr);
    m_oknoProgramW->exec();
    delete m_oknoProgramW;
    m_oknoProgramW = nullptr;
}

void MainWindowLogic::openRegisterWindow()
{
    m_mainWindow->hide();
    RegisterWindow *m_oknoRegister = new RegisterWindow(nullptr);
    connect(m_oknoRegister, &RegisterWindow::zajerestruj, m_mainWindow, &MainWindow::zajerestruj);
    connect(m_oknoRegister, &RegisterWindow::nieRejestruj, m_mainWindow, &MainWindow::show);
    m_oknoRegister->exec();
    delete m_oknoRegister;
    m_oknoRegister = nullptr;
}

