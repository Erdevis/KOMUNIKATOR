#include "logicprogramwindow.h"
#include <qtcpsocket>

LogicProgramWindow::LogicProgramWindow(QObject *parent)
    : QObject(parent),
    socket(new QTcpSocket(this))
{
    connect(socket, SIGNAL(readyRead()), this, SLOT(readMessage()));
}

void LogicProgramWindow::readMessage()
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
        emit messageReceived(line, false);
    }
}

void LogicProgramWindow::sendMessage(const QString &message)
{
    if (!socket || !socket->isOpen())
    {
        qDebug() << "Socket is not open or does not exist";
        return;
    }

    QString text = message;
    text.append("\n");
    socket->write(text.toUtf8());

    qDebug()<< "wysylajacy";
    emit messageReceived(message, true);
}

void LogicProgramWindow::connectToServer(const QString &serverIp, int port)
{
    socket->abort();
    socket->connectToHost(serverIp, port);
    connect(socket, &QTcpSocket::connected, this, &LogicProgramWindow::connected);
}

void LogicProgramWindow::disconnectFromServer()
{
    if (socket && socket->state() == QAbstractSocket::ConnectedState)
    {
        qDebug() << "Before disconnectFromHost()";
        socket->disconnectFromHost();

        if (!socket->waitForDisconnected(4500))
        {
            qWarning() << "Error disconnecting: " << socket->errorString();
        }

        qDebug() << "Disconnected from the server";
    }
    else
    {
        qDebug() << "Not connected to the server";
        return;
    }

    // Usuń połączenie sygnału z metodą readMessage()
    disconnect(socket, SIGNAL(readyRead()), this, SLOT(readMessage()));
    disconnect(socket, &QTcpSocket::connected, this, &LogicProgramWindow::connected);

    qDebug() << "Before deleteLater()";
    socket->deleteLater();
    qDebug() << "After deleteLater()";

    socket = new QTcpSocket(this);
    connect(socket, SIGNAL(readyRead()), this, SLOT(readMessage()));
}
