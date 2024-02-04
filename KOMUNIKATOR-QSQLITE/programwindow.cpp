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
    ui->IpEdit->setPlaceholderText("Enter IP");

    socket = new QTcpSocket(this);
    connect(socket, SIGNAL(readyRead()), this, SLOT(readMessage()));
    connect(socket, &QTcpSocket::connected,this,&ProgramWindow::onConnected);

    //socket = new QTcpSocket(this);
    //connect(socket, SIGNAL(readyRead()), this, SLOT(readMessage()));
}
/*
void ProgramWindow::readMessage()
{
    while(socket->canReadLine()) {
        QString line = QString::fromUtf8(socket->readLine()).trimmed();
        // Dodaj obsługę błędów tutaj
        if(line.isEmpty() || line.isNull()) {
            qDebug() << "Otrzymano pustą linię lub błąd odczytu";
            continue;
        }
        ui->reading->append(line);
    }
}
*/
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

        // Determine whether the message is sent by the user or received
        bool isSentByUser = line.startsWith("You:");
        addMessage(line, isSentByUser);
    }
}


void ProgramWindow::addMessage(const QString &message, bool isSentByUser)
{
    // Utwórz nowy obiekt QTextCursor dla QTextEdit
    QTextCursor cursor(ui->reading->textCursor());

    // Ustaw kursor na koniec dokumentu
    cursor.movePosition(QTextCursor::End);

    // Dodaj nową linię przed nową wiadomością (jeśli nie jest to pierwsza wiadomość)
    if (cursor.blockNumber() > 0) {
        cursor.insertBlock();
    }

    // Utwórz format dla tekstu
    QTextCharFormat format;

    // Ustaw kolor tekstu na czarny
    format.setForeground(QColor("#000000"));

    // Ustaw białe tło wiadomości
    format.setBackground(QColor("#ffffff"));

    // Wstaw tekst z ustawionym formatem
    cursor.insertText(message, format);

    // Ustaw stronę dla tekstu w zależności od nadawcy/odbiorcy
    QTextBlockFormat blockFormat = cursor.blockFormat();
    blockFormat.setAlignment(isSentByUser ? Qt::AlignRight : Qt::AlignLeft);
    cursor.setBlockFormat(blockFormat);

    // Przesuń kursor na dół, aby pokazać najnowszą wiadomość
    ui->reading->setTextCursor(cursor);

    // Dodaj nową linię po wiadomości
    cursor.insertBlock();
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

    QString text = "You: " + ui->writing->toPlainText();
    text.append("\n");
    socket->write(text.toUtf8());
    addMessage(text, true);
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
        if (socket->state() != QAbstractSocket::UnconnectedState)
        {
            socket->waitForDisconnected();
        }
        qDebug() << "Disconnected from the server";
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
