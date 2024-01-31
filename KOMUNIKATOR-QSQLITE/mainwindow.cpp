#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <User.h>
#include <QSqlDatabase>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //server = new Server(this);
    ui->txtLogin->setPlaceholderText("login");
    ui->txtHaslo->setPlaceholderText("password");
    m_loggedInUser = nullptr;
    ui->logo->setFixedSize(50*1.578,50);
    QPixmap pix("images/logo.png");
    pix = pix.scaled(ui->logo->size(),Qt::KeepAspectRatio, Qt::SmoothTransformation);
    ui->logo->setScaledContents(true);
    ui->logo->setPixmap(pix);

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("Server_KOMUNIKATOR_Proj_PK\\UsersLogs.db");
    bool db_ok = db.open();

    db.open();
    if(db_ok)
        qDebug()<<"Jest smiga";
    else
        qDebug()<<";(((( katastrofa";

    /*QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("UsersLogs.db");
    db.open();
    if(db_ok)
        qDebug()<<"oadss";
    else
        qDebug()<<";((((";*/
}

MainWindow::~MainWindow()
{
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


    QString login = ui->txtLogin->toPlainText();
    QString password = ui->txtHaslo->toPlainText();

    // Odczytaj użytkowników z bazy danych
    QVector<User> users = loadAllFromDatabase();

    bool sukces = false;
    for(auto i: users)
    {
        if(login == i.getLogin()&& password == i.getPassword())
        {
            sukces = true;

            m_loggedInUser = new User(i);
            break;
        }
    }

    if(!sukces)
    {
        QMessageBox::warning(this, "Błąd", "Nieprawidłowy login lub hasło.");
    }
    else{

        m_oknoProgramW = new ProgramWindow(nullptr);
        this->hide();
        m_oknoProgramW->exec();
        delete m_oknoProgramW;
        m_oknoProgramW = nullptr;
    }
}


/*
void MainWindow::on_btnLogin_clicked()
{
    server->startServer();

    QString login = ui->txtLogin->toPlainText();
    QString password = ui->txtHaslo->toPlainText();

    // Odczytaj użytkownika z pliku
    User existingUser = User::loadFromFile("user.txt");
    QVector<User>users = User::loadAllFromFile("user.txt");

    bool sukces = false;
    for(auto i: users)
    {
        if(login == i.getLogin()&& password == i.getPassword())
        {
            sukces = true;

                m_loggedInUser = new User(existingUser);
            break;
        }
    }

    if(!sukces)
    {
        QMessageBox::warning(this, "Błąd", "Nieprawidłowy login lub hasło.");
    }
    else{

        m_oknoProgramW = new ProgramWindow(nullptr);
        this->hide();
        m_oknoProgramW->exec();
        delete m_oknoProgramW;
        m_oknoProgramW = nullptr;

    }
}*/

void MainWindow::zajerestruj()
{
    this->show();
}


void MainWindow::on_btnRejestracja_clicked()
{
    m_oknoRegister = new RegisterWindow(nullptr);
    connect(m_oknoRegister, &RegisterWindow::zajerestruj,this,&MainWindow::zajerestruj);
    connect(m_oknoRegister, &RegisterWindow::nieRejestruj,this,&MainWindow::show);
    this->hide();
    m_oknoRegister->exec();
    delete m_oknoRegister;
    m_oknoRegister = nullptr;

}

