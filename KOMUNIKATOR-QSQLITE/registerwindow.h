#ifndef REGISTERWINDOW_H
#define REGISTERWINDOW_H

#include <QDialog>

#include <user.h>
#include <QMessageBox>
#include "logicregisterwindow.h"

namespace Ui {
class RegisterWindow;
}

class RegisterWindow : public QDialog
{
    Q_OBJECT

public:
    explicit RegisterWindow(QWidget *parent = nullptr);

    ~RegisterWindow();

signals:
    void nieRejestruj();
    void zajerestruj(const User& newUser);

private slots:
    void on_cancel_clicked();
    void on_zaloguj_clicked();

private:
    Ui::RegisterWindow *ui;
    LogicRegisterWindow logic;

};

#endif // REGISTERWINDOW_H
