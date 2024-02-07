#include "registerwindow.h"
#include "ui_registerwindow.h"

RegisterWindow::RegisterWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RegisterWindow)
{
    ui->setupUi(this);
    ui->logintxt->setPlaceholderText("Login");
    ui->passwordtxt->setPlaceholderText("Password");
    ui->repeatPasswordtxt->setPlaceholderText("Repeat password");

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

     //logic.on_zaloguj_clicked(login, password, repeatPassword);
}



/*User* RegisterWindow::createUserFromInput()
{
    QString login = ui->logintxt->toPlainText();
    QString password = ui->passwordtxt->toPlainText();
    QString repeatPassword = ui->repeatPasswordtxt->toPlainText();

    if(password != repeatPassword)
    {
        QMessageBox mesBox;
        mesBox.setText("NIEPRAWIDLOWE HASLO");
        mesBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Close);
        mesBox.setIcon(QMessageBox::Warning);
        mesBox.exec();
        return nullptr;
    }
    return new User(login,password);

}

void RegisterWindow::on_zaloguj_clicked()
{
    User* newUser = createUserFromInput();

    if(newUser != nullptr)
    {
        if(newUser->saveToDatabase())
        {
            emit zajerestruj(*newUser);
            this->close();
        }
    }
}*/
