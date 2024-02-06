#ifndef PROGRAMWINDOW_H
#define PROGRAMWINDOW_H

#include "qlistwidget.h"
#include <QDialog>
#include <QTcpServer>
#include <QtNetwork/QTcpServer>
#include <QtNetwork/QTcpSocket>
#include "registerwindow.h"
#include <QListWidgetItem>

namespace Ui {
class ProgramWindow;
}

class ProgramWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ProgramWindow( QWidget *parent , const QString &loggedInUser);
    ~ProgramWindow();
public slots:
    void updateUserList(const QStringList &users);

private slots:
    void on_send_clicked();
    void on_znajomiBtn_clicked();

    void on_connectBtn_clicked();
    void readMessage();
    void onConnected();
    void on_friendsList_itemClicked(QListWidgetItem *item);
    void on_disconectBtn_clicked();


private:
    Ui::ProgramWindow *ui;
    QTcpSocket *socket;
    QStringList friendsIPList;

    QString currentUsername;

    void addMessage(const QString &message, bool isSentByUser);
};

#endif // PROGRAMWINDOW_H
