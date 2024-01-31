#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    DbConnection = QSqlDatabase::addDatabase("QSQLITE");
    DbConnection.setDatabaseName("UsersLogs.db");
    DbConnection.open();

    QSqlQuery query;
    query.prepare("CREATE TABLE IF NOT EXISTS users ("
                  "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                  "username TEXT UNIQUE NOT NULL, "
                  "password TEXT NOT NULL"
                  ")");
    if (!query.exec()) {
        qDebug() << "Error creating table: " << query.lastError();
    }

    server.addUser("user1","pass1");

    connect(&server, &Server::updatedUserList, this, &MainWindow::updateUserList);
    server.startServer();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateUserList(const QStringList &users)
{
    ui->connectedUsersList->clear();
    ui->connectedUsersList->addItems(users);
}
