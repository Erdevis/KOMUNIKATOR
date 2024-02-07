#include "programwindow.h"
#include "logicprogramwindow.h"
#include <qtcpsocket>
#include <QtNetwork/QTcpServer>
#include <QtNetwork/qtcpsocket>
#include "qregularexpression.h"
#include "ui_programwindow.h"

ProgramWindow::ProgramWindow( QWidget *parent, const QString &loggedInUser)
    : QDialog(parent),
    ui(new Ui::ProgramWindow),
    currentUsername(loggedInUser),
    logicProgramWindow(new LogicProgramWindow(this))
{
    ui->setupUi(this);
    ui->reading->setReadOnly(true);
    ui->writing->setPlaceholderText("message");
    ui->friendsList->hide();
    ui->IpEdit->setPlaceholderText("Enter IP");

    connect(logicProgramWindow, SIGNAL(messageReceived(QString, bool)), this, SLOT(addMessage(QString, bool)));
    connect(logicProgramWindow, SIGNAL(connected()), this, SLOT(onConnected()));
}

void ProgramWindow::addMessage(const QString &message, bool isSentByUser)
{
    qDebug()<< message;
    QString formattedMessage;

    // Get the current date and time
    QDateTime currentDateTime = QDateTime::currentDateTime();
    QString dateTimeString = currentDateTime.toString("yyyy-MM-dd hh:mm:ss");

    // Format the message based on the user role (sender/receiver)
    if (isSentByUser)
    {
        // Wiadomość wysłana przez użytkownika (po prawej stronie)
        formattedMessage = "<span style='font-size: 10px; color: #000069;'>(" + dateTimeString + ")</span><br>"
                           + "<b> Me </b> : " + message + "<br>";
    }
    else
    {
        // Wiadomość odebrana (po lewej stronie)
        formattedMessage = "<span style='font-size: 10px; color: #000069;'>(" + dateTimeString + ")</span><br>"
                           + "<b> Friend </b> : " + message + "<br>";
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
    QString text = ui->writing->toPlainText();
    logicProgramWindow->sendMessage(text);
    ui->writing->clear();
}

void ProgramWindow::on_connectBtn_clicked()
{
    QString serverIp = ui->IpEdit->text();
    if (!serverIp.isEmpty())
    {
        logicProgramWindow->connectToServer(serverIp, 4500);
    }
}

void ProgramWindow::on_disconectBtn_clicked()
{
    logicProgramWindow->disconnectFromServer();
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

void ProgramWindow::updateUserList(const QStringList &users)
{
    // Tutaj możesz dodać logikę do aktualizacji listy użytkowników
}
