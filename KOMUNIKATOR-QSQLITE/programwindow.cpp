#include "programwindow.h"
#include <qtcpsocket>
#include <QtNetwork/QTcpServer>
#include <QtNetwork/qtcpsocket>
#include "qregularexpression.h"
#include "ui_programwindow.h"

ProgramWindow::ProgramWindow(const QString &loggedInUser, QWidget *parent)
    : QDialog(parent),
    ui(new Ui::ProgramWindow),
    currentUsername(loggedInUser)
{
    ui->setupUi(this);
    ui->reading->setReadOnly(true);
    ui->writing->setPlaceholderText("message");
    ui->friendsList->hide();
    ui->IpEdit->setPlaceholderText("Enter IP");

    socket = new QTcpSocket(this);
    connect(socket, SIGNAL(readyRead()), this, SLOT(readMessage()));
    connect(socket, &QTcpSocket::connected, this, &ProgramWindow::onConnected);
}

void ProgramWindow::readMessage()
{
    while (socket->canReadLine())
    {
        QString line = QString::fromUtf8(socket->readLine()).trimmed();
        if (line.isEmpty() || line.isNull())
        {
            qDebug() << "Received an empty line or read error";
            continue;
        }

        qDebug() << "otrzymujacy";  // Wyświetl otrzymaną wiadomość w konsoli
        addMessage(line, false);
    }
}


void ProgramWindow::addMessage(const QString &message, bool isSentByUser)
{
    qDebug()<< message;
    QString formattedMessage;

    // Format the message based on the user role (sender/receiver)
    if (isSentByUser)
    {
        // Wiadomość wysłana przez użytkownika (po prawej stronie)
         formattedMessage = "<b> Me: </b>" + message;
    }
    else
    {
        // Wiadomość odebrana (po lewej stronie)
         formattedMessage = "<b> Friend: </b>" + message;
    }

    // Dodaj sformatowaną wiadomość do interfejsu użytkownika
    ui->reading->append(formattedMessage);
}

ProgramWindow::~ProgramWindow()
{
    delete ui;
}

void ProgramWindow::on_send_clicked()
{
    if (!socket || !socket->isOpen())
    {
        qDebug() << "Socket is not open or does not exist";
        return;
    }

    QString text;
    text = ui->writing->toPlainText();
    addMessage(text, true);
    text.append("\n");
    socket->write(text.toUtf8());

    qDebug()<< "wysylajacy";


    ui->writing->clear();
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
    if (socket && socket->state() == QAbstractSocket::ConnectedState)
    {
        qDebug() << "Already connected to the server";
        return;
    }

    QString serverIp = ui->IpEdit->text();

    if (!serverIp.isEmpty())
    {
        friendsIPList.append(serverIp); // Add the IP to the list

        // Update the friendsList widget with the new list of IPs
        ui->friendsList->addItem(serverIp);

        // Rest of the code remains unchanged
        socket->connectToHost(serverIp, 4500);
        //connect(socket, &QTcpSocket::connected, this, &ProgramWindow::onConnected);
    }

    //socket = new QTcpSocket(this);
    //connect(socket, SIGNAL(readyRead()), this, SLOT(readMessage()));
    //socket->connectToHost(serverIp, 4500); // Załóżmy, że serwer nasłuchuje na porcie 4500
    //connect(socket, &QTcpSocket::connected, this, &ProgramWindow::onConnected);
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

void ProgramWindow::on_disconectBtn_clicked()
{

    if (socket && socket->state() == QAbstractSocket::ConnectedState)
    {
        socket->disconnectFromHost();
        qDebug() << "Disconnected from the server";

        // Usuń połączenie sygnału z metody readMessage()
        disconnect(socket, SIGNAL(readyRead()), this, SLOT(readMessage()));
    }
    else
    {
        qDebug() << "Not connected to the server";
    }
    /*
    if (socket && socket->state() == QAbstractSocket::ConnectedState)
    {
        socket->disconnectFromHost();
        qDebug() << "Disconnected from the server";
    }
    else
    {
        qDebug() << "Not connected to the server";
    }*/
}

void ProgramWindow::onConnected()
{
    qDebug() << "Connected to the server";
}

void ProgramWindow::on_friendsList_itemClicked(QListWidgetItem *item)
{
    if (item)
    {
        QString selectedIP = item->text();
        ui->IpEdit->setText(selectedIP);
        ui->friendsList->hide();
        ui->znajomiBtn->setText("Friends");
    }
}
