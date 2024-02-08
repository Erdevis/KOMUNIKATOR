#include "registerwindow.h"
#include "ui_registerwindow.h"

RegisterWindow::RegisterWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RegisterWindow)
{
    ui->setupUi(this);
    ui->logintxt->setPlaceholderText("Login");
    ui->passwordtxt->setPlaceholderText("Password");
    ui->passwordtxt->setEchoMode(QLineEdit::Password);
    ui->repeatPasswordtxt->setPlaceholderText("Repeat password");
    ui->repeatPasswordtxt->setEchoMode(QLineEdit::Password);

    connect(&logic, &LogicRegisterWindow::nieRejestruj, this, &RegisterWindow::close);
    connect(&logic, &LogicRegisterWindow::zajerestruj, this, &RegisterWindow::zajerestruj);

}

RegisterWindow::~RegisterWindow()
{
    delete ui;
}

void RegisterWindow::on_cancel_clicked()
{
    // logic.on_cancel_clicked();
    emit nieRejestruj();
    this->close();
}

void RegisterWindow::on_zaloguj_clicked()
{
     QString login = ui->logintxt->text();
     QString password = ui->passwordtxt->text();
     QString repeatPassword = ui->repeatPasswordtxt->text();

     if(logic.on_zaloguj_clicked(login, password, repeatPassword))
     {
         this->close();
     }
}
