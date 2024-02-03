/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QFrame *frame;
    QVBoxLayout *verticalLayout_2;
    QTextEdit *txtLogin;
    QTextEdit *txtHaslo;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout;
    QPushButton *btnLogin;
    QPushButton *btnRejestracja;
    QFrame *frame_3;
    QHBoxLayout *horizontalLayout;
    QFrame *frame_4;
    QLabel *logo;
    QFrame *frame_5;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(795, 452);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setStyleSheet(QString::fromUtf8("QWidget {\n"
"            background-color: #f0f8ff; /* Delikatny niebieski kolor t\305\202a */\n"
"            border-radius: 15px; /* Zaokr\304\205glenie rog\303\263w */\n"
"        }"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame);
        verticalLayout_2->setObjectName("verticalLayout_2");
        txtLogin = new QTextEdit(frame);
        txtLogin->setObjectName("txtLogin");
        txtLogin->setStyleSheet(QString::fromUtf8("QTextEdit {\n"
"    background-color: #ffffff; /* Kolor t\305\202a - bia\305\202y */\n"
"    color: #000000; /* Kolor tekstu - czarny */\n"
"    border: 1px solid #555555; /* Grubo\305\233\304\207 i kolor obramowania */\n"
"    border-radius: 15px; /* Zaokr\304\205glenie rog\303\263w - dostosuj wed\305\202ug potrzeb */\n"
"    padding: 10px; /* Wewn\304\231trzny odst\304\231p */\n"
"    font-family: Arial, sans-serif; /* Rodzina czcionek */\n"
"    font-size: 12pt; /* Rozmiar czcionki */\n"
"    line-height: 1.5; /* Wysoko\305\233\304\207 linii dla odst\304\231pu mi\304\231dzy wierszami */\n"
"    min-height: 100px; /* Minimalna wysoko\305\233\304\207 pola */\n"
"}\n"
"\n"
"QTextEdit:focus {\n"
"    border: 2px solid #1e90ff; /* Grubo\305\233\304\207 i kolor obramowania po aktywacji - niebieski */\n"
"    outline: none; /* Wy\305\202\304\205czanie pod\305\233wietlenia po aktywacji */\n"
"}"));
        txtLogin->setReadOnly(false);

        verticalLayout_2->addWidget(txtLogin);

        txtHaslo = new QTextEdit(frame);
        txtHaslo->setObjectName("txtHaslo");
        txtHaslo->setStyleSheet(QString::fromUtf8("QTextEdit {\n"
"    background-color: #ffffff; /* Kolor t\305\202a - bia\305\202y */\n"
"    color: #000000; /* Kolor tekstu - czarny */\n"
"    border: 1px solid #555555; /* Grubo\305\233\304\207 i kolor obramowania */\n"
"    border-radius: 15px; /* Zaokr\304\205glenie rog\303\263w - dostosuj wed\305\202ug potrzeb */\n"
"    padding: 10px; /* Wewn\304\231trzny odst\304\231p */\n"
"    font-family: Arial, sans-serif; /* Rodzina czcionek */\n"
"    font-size: 12pt; /* Rozmiar czcionki */\n"
"    line-height: 1.5; /* Wysoko\305\233\304\207 linii dla odst\304\231pu mi\304\231dzy wierszami */\n"
"    min-height: 100px; /* Minimalna wysoko\305\233\304\207 pola */\n"
"}\n"
"\n"
"QTextEdit:focus {\n"
"    border: 2px solid #1e90ff; /* Grubo\305\233\304\207 i kolor obramowania po aktywacji - niebieski */\n"
"    outline: none; /* Wy\305\202\304\205czanie pod\305\233wietlenia po aktywacji */\n"
"}"));

        verticalLayout_2->addWidget(txtHaslo);

        frame_2 = new QFrame(frame);
        frame_2->setObjectName("frame_2");
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame_2);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(-1, 35, -1, -1);
        btnLogin = new QPushButton(frame_2);
        btnLogin->setObjectName("btnLogin");
        btnLogin->setMinimumSize(QSize(0, 40));
        btnLogin->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #ffffff; /* Kolor t\305\202a - bia\305\202y */\n"
"    color: #000000; /* Kolor tekstu - czarny */\n"
"    border: none; /* Usuni\304\231cie obramowania */\n"
"    border-radius: 15px; /* Zaokr\304\205glenie rog\303\263w */\n"
"    padding: 10px; /* Wewn\304\231trzny odst\304\231p */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #1e90ff; /* Kolor t\305\202a po najechaniu mysz\304\205 - niebieski */\n"
"    color: #ffffff; /* Zmiana koloru tekstu po najechaniu mysz\304\205 - bia\305\202y */\n"
"}"));

        verticalLayout->addWidget(btnLogin);

        btnRejestracja = new QPushButton(frame_2);
        btnRejestracja->setObjectName("btnRejestracja");
        btnRejestracja->setMinimumSize(QSize(0, 40));
        btnRejestracja->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #ffffff; /* Kolor t\305\202a - bia\305\202y */\n"
"    color: #000000; /* Kolor tekstu - czarny */\n"
"    border: none; /* Usuni\304\231cie obramowania */\n"
"    border-radius: 15px; /* Zaokr\304\205glenie rog\303\263w */\n"
"    padding: 10px; /* Wewn\304\231trzny odst\304\231p */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #1e90ff; /* Kolor t\305\202a po najechaniu mysz\304\205 - niebieski */\n"
"    color: #ffffff; /* Zmiana koloru tekstu po najechaniu mysz\304\205 - bia\305\202y */\n"
"}"));

        verticalLayout->addWidget(btnRejestracja);


        verticalLayout_2->addWidget(frame_2);


        gridLayout->addWidget(frame, 1, 0, 1, 1);

        frame_3 = new QFrame(centralwidget);
        frame_3->setObjectName("frame_3");
        frame_3->setMinimumSize(QSize(0, 60));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame_3);
        horizontalLayout->setObjectName("horizontalLayout");
        frame_4 = new QFrame(frame_3);
        frame_4->setObjectName("frame_4");
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);

        horizontalLayout->addWidget(frame_4);

        logo = new QLabel(frame_3);
        logo->setObjectName("logo");
        logo->setScaledContents(true);

        horizontalLayout->addWidget(logo);

        frame_5 = new QFrame(frame_3);
        frame_5->setObjectName("frame_5");
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);

        horizontalLayout->addWidget(frame_5);


        gridLayout->addWidget(frame_3, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 795, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        txtLogin->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Arial','sans-serif'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Segoe UI'; font-size:9pt;\"><br /></p></body></html>", nullptr));
        txtHaslo->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Arial','sans-serif'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Segoe UI'; font-size:9pt;\"><br /></p></body></html>", nullptr));
        btnLogin->setText(QCoreApplication::translate("MainWindow", "Sign in", nullptr));
        btnRejestracja->setText(QCoreApplication::translate("MainWindow", "Sign up", nullptr));
        logo->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
