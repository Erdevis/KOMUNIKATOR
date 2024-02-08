#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <User.h>
#include <QSqlDatabase>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_logic(new MainWindowLogic(this))

{
    ui->setupUi(this);

    ui->txtLogin->setPlaceholderText("login");
    ui->txtHaslo->setPlaceholderText("password");
    ui->txtHaslo->setEchoMode(QLineEdit::Password);
    m_loggedInUser = nullptr;
    ui->logo->setFixedSize(50*1.578,50);
    QPixmap pix("images/Rekin.png");
    pix = pix.scaled(ui->logo->size(),Qt::KeepAspectRatio, Qt::SmoothTransformation);
    ui->logo->setScaledContents(true);
    ui->logo->setPixmap(pix);

}

MainWindow::~MainWindow()
{
    delete m_logic;
    delete ui;
}

QVector<User> MainWindow::loadAllFromDatabase()
{
    QVector<User> users;
    QSqlQuery query("SELECT * FROM users");
    while (query.next()) {
        QString username = query.value("username").toString();
        QString password = query.value("password").toString();
        users.append(User(username, password));
    }
    return users;
}

void MainWindow::on_btnLogin_clicked()
{
    QString login = ui->txtLogin->text();
    QString password = ui->txtHaslo->text();

    m_loggedInUser = m_logic->loginUser(login, password);

    if(!m_loggedInUser)
    {
        QMessageBox::warning(this, "Błąd", "Nieprawidłowy login lub hasło.");
    }
    else{
         m_logic->openProgramWindow(m_loggedInUser);
    }
}

void MainWindow::zajerestruj()
{
    this->show();
}

void MainWindow::on_btnRejestracja_clicked()
{
    m_logic->openRegisterWindow();
}

