#ifndef PROGRAMWINDOW_H
#define PROGRAMWINDOW_H

#include <QDialog>
#include <QTcpServer>
#include <QtNetwork/QTcpServer>
#include <QtNetwork/QTcpSocket>

namespace Ui {
class ProgramWindow;
}

class ProgramWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ProgramWindow(QWidget *parent = nullptr);
    ~ProgramWindow();
public slots:
    void updateUserList(const QStringList &users);

private slots:
    void on_send_clicked();
    void on_znajomiBtn_clicked();

    void on_connectBtn_clicked();
    void readMessage();
    void onConnected();

private:
    Ui::ProgramWindow *ui;
    QTcpSocket *socket;
};

#endif // PROGRAMWINDOW_H
