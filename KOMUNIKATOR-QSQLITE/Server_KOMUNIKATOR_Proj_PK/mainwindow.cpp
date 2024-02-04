#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    server.createDatabase();  

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
