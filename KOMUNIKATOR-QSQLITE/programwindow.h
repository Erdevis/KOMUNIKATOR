#ifndef PROGRAMWINDOW_H
#define PROGRAMWINDOW_H

#include "logicprogramwindow.h"
#include "qlistwidget.h"
#include <QDialog>
#include <QTcpServer>
#include <QtNetwork/QTcpServer>
#include <QtNetwork/QTcpSocket>
#include <QListWidgetItem>
#include <QDateTime>

namespace Ui {
class ProgramWindow;
}

class ProgramWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ProgramWindow(QWidget *parent, const QString &loggedInUser);
    ~ProgramWindow();

public slots:

private slots:
    void on_send_clicked();
    void on_znajomiBtn_clicked();
    void on_connectBtn_clicked();
    void on_friendsList_itemClicked(QListWidgetItem *item);
    void on_disconectBtn_clicked();
    void addMessage(const QString &message, bool isSentByUser);

private:
    Ui::ProgramWindow *ui;
    LogicProgramWindow *logicProgramWindow;
    QStringList friendsIPList;
    QString currentUsername;

    QStringList friendList;
    void saveToFriendList(const QString &ipAddress);
    void updateFriendListUI();
};

#endif // PROGRAMWINDOW_H
