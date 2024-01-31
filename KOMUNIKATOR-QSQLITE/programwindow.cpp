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
}

ProgramWindow::~ProgramWindow()
{
    delete ui;
}

void ProgramWindow::on_send_clicked()
{
    QString text=ui->writing->toPlainText();
    ui->reading->append(text);
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
    QString serverIp = ui->IpEdit->text();
    socket->connectToHost(serverIp, 4500); // Załóżmy, że serwer nasłuchuje na porcie 4500
}

