#ifndef LOGICPROGRAMWINDOW_H
#define LOGICPROGRAMWINDOW_H

#include <QObject>
#include <QTcpSocket>

class LogicProgramWindow : public QObject
{
    Q_OBJECT
public:
    explicit LogicProgramWindow(QObject *parent = nullptr);
    void sendMessage(const QString &message);
    void connectToServer(const QString &serverIp, int port);
    void disconnectFromServer();

signals:
    void messageReceived(const QString &message, bool isSentByUser);
    void connected();

private slots:
    void readMessage();

private:
    QTcpSocket *socket;
};

#endif // LOGICPROGRAMWINDOW_H
