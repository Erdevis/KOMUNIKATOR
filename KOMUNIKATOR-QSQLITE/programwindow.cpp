#include "programwindow.h"
#include <qtcpsocket>
#include <QtNetwork/QTcpServer>
#include <QtNetwork/qtcpsocket>
#include "ui_programwindow.h"

ProgramWindow::ProgramWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ProgramWindow)
{
    ui->setupUi(this);
    ui->reading->setReadOnly(true);
    ui->writing->setPlaceholderText("message");
    ui->friendsList->hide();

    socket = new QTcpSocket(this);
    connect(socket, SIGNAL(readyRead()), this, SLOT(readMessage()));

    //socket = new QTcpSocket(this);
    //connect(socket, SIGNAL(readyRead()), this, SLOT(readMessage()));
}

void ProgramWindow::readMessage()
{
    while(socket->canReadLine()) {
        QString line = QString::fromUtf8(socket->readLine()).trimmed();
        ui->reading->append(line);
    }
}

ProgramWindow::~ProgramWindow()
{
    delete ui;
}

void ProgramWindow::on_send_clicked()
{
    if(!socket) {
        qDebug() << "Socket is not initialized";
        return;
    }
    QString text=ui->writing->toPlainText();
    text.append("\n");
    if(socket && socket->isOpen()) {
        socket->write(text.toUtf8());
        ui->reading->append(text);
        ui->writing->clear();
    } else {
        qDebug() << "Socket is not open or does not exist";
    }
}

void ProgramWindow::on_znajomiBtn_clicked()
{
    if(ui->znajomiBtn->text()=="Friends"){
        ui->znajomiBtn->setText("Select friend");
        ui->friendsList->show();
    }
    else{
        ui->friendsList->hide();
        ui->znajomiBtn->setText("Friends");
    }
 }

void ProgramWindow::updateUserList(const QStringList &users)
{
    // Tutaj możesz dodać logikę do aktualizacji listy użytkowników
}


void ProgramWindow::on_connectBtn_clicked()
{
    if(socket && socket->state() == QAbstractSocket::ConnectedState) {
        qDebug() << "Already connected to the server";
        return;
    }
    QString serverIp = ui->IpEdit->text();

    //socket = new QTcpSocket(this);
    //connect(socket, SIGNAL(readyRead()), this, SLOT(readMessage()));

    socket->connectToHost(serverIp, 4500); // Załóżmy, że serwer nasłuchuje na porcie 4500

    connect(socket, &QTcpSocket::connected, this, &ProgramWindow::onConnected);

    /*
    QString serverIp = ui->IpEdit->text();
    socket->connectToHost(serverIp, 4500); // Załóżmy, że serwer nasłuchuje na porcie 4500

     connect(socket, &QTcpSocket::connected, this, &ProgramWindow::onConnected);
     */



    /*if(socket->state() == QAbstractSocket::ConnectedState) {
        qDebug() << "Connected to the server";
    } else {
        qDebug() << "Not connected to the server";
    }*/
}

void ProgramWindow::onConnected()
{
     qDebug() << "Connected to the server";
}
