#ifndef REGISTERWINDOW_H
#define REGISTERWINDOW_H

#include <QDialog>

#include <user.h>
#include <QMessageBox>

namespace Ui {
class RegisterWindow;
}

class RegisterWindow : public QDialog
{
    Q_OBJECT

public:
    explicit RegisterWindow(QWidget *parent = nullptr);
    User* createUserFromInput();//new
    ~RegisterWindow();

signals:
    void nieRejestruj();
    void zajerestruj(const User& newUser);

private slots:
    void on_cancel_clicked();
    void on_zaloguj_clicked();

private:
    Ui::RegisterWindow *ui;

};

#endif // REGISTERWINDOW_H
