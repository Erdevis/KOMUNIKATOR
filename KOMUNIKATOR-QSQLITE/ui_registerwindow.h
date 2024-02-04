/********************************************************************************
** Form generated from reading UI file 'registerwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERWINDOW_H
#define UI_REGISTERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_RegisterWindow
{
public:
    QGridLayout *gridLayout_2;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QTextEdit *logintxt;
    QTextEdit *passwordtxt;
    QTextEdit *repeatPasswordtxt;
    QFrame *frame_2;
    QGridLayout *gridLayout;
    QPushButton *zaloguj;
    QPushButton *cancel;

    void setupUi(QDialog *RegisterWindow)
    {
        if (RegisterWindow->objectName().isEmpty())
            RegisterWindow->setObjectName("RegisterWindow");
        RegisterWindow->resize(536, 494);
        gridLayout_2 = new QGridLayout(RegisterWindow);
        gridLayout_2->setObjectName("gridLayout_2");
        frame = new QFrame(RegisterWindow);
        frame->setObjectName("frame");
        frame->setStyleSheet(QString::fromUtf8("QWidget {\n"
"            background-color: #f0f8ff; /* Delikatny niebieski kolor t\305\202a */\n"
"            border-radius: 15px; /* Zaokr\304\205glenie rog\303\263w */\n"
"        }"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setObjectName("verticalLayout");
        logintxt = new QTextEdit(frame);
        logintxt->setObjectName("logintxt");
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setPointSize(12);
        logintxt->setFont(font);
        logintxt->setStyleSheet(QString::fromUtf8("QTextEdit {\n"
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

        verticalLayout->addWidget(logintxt);

        passwordtxt = new QTextEdit(frame);
        passwordtxt->setObjectName("passwordtxt");
        passwordtxt->setFont(font);
        passwordtxt->setStyleSheet(QString::fromUtf8("QTextEdit {\n"
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

        verticalLayout->addWidget(passwordtxt);

        repeatPasswordtxt = new QTextEdit(frame);
        repeatPasswordtxt->setObjectName("repeatPasswordtxt");
        repeatPasswordtxt->setFont(font);
        repeatPasswordtxt->setStyleSheet(QString::fromUtf8("QTextEdit {\n"
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

        verticalLayout->addWidget(repeatPasswordtxt);

        frame_2 = new QFrame(frame);
        frame_2->setObjectName("frame_2");
        QFont font1;
        font1.setPointSize(12);
        frame_2->setFont(font1);
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame_2);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setHorizontalSpacing(65);
        gridLayout->setVerticalSpacing(0);
        gridLayout->setContentsMargins(-1, 25, -1, -1);
        zaloguj = new QPushButton(frame_2);
        zaloguj->setObjectName("zaloguj");
        zaloguj->setMinimumSize(QSize(0, 40));
        zaloguj->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        zaloguj->setIconSize(QSize(20, 20));

        gridLayout->addWidget(zaloguj, 0, 0, 1, 1);

        cancel = new QPushButton(frame_2);
        cancel->setObjectName("cancel");
        cancel->setMinimumSize(QSize(0, 40));
        cancel->setBaseSize(QSize(0, 0));
        cancel->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #ffffff; /* Kolor t\305\202a - czerwony */\n"
"    color: #000000; /* Kolor tekstu - czarny */\n"
"    border: none; /* Usuni\304\231cie obramowania */\n"
"    border-radius: 15px; /* Zaokr\304\205glenie rog\303\263w */\n"
"    padding: 10px; /* Wewn\304\231trzny odst\304\231p */\n"
"    transition: background-color 0.3s ease; /* Dodanie p\305\202ynnej animacji pod\305\233wietlenia */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #ff0000; /* Kolor t\305\202a po najechaniu mysz\304\205 - czerwony */\n"
"    color: #ffffff; /* Zmiana koloru tekstu po najechaniu myszk\304\205 - bia\305\202y */\n"
"    border: 2px solid #ffffff; /* Dodanie bia\305\202ego obramowania po najechaniu myszk\304\205 */\n"
"}"));
        cancel->setIconSize(QSize(20, 20));

        gridLayout->addWidget(cancel, 0, 1, 1, 1);


        verticalLayout->addWidget(frame_2);


        gridLayout_2->addWidget(frame, 0, 0, 1, 1);


        retranslateUi(RegisterWindow);

        QMetaObject::connectSlotsByName(RegisterWindow);
    } // setupUi

    void retranslateUi(QDialog *RegisterWindow)
    {
        RegisterWindow->setWindowTitle(QCoreApplication::translate("RegisterWindow", "Dialog", nullptr));
        logintxt->setHtml(QCoreApplication::translate("RegisterWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Arial','sans-serif'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Segoe UI'; font-size:9pt;\"><br /></p></body></html>", nullptr));
        passwordtxt->setHtml(QCoreApplication::translate("RegisterWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Arial','sans-serif'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Segoe UI'; font-size:9pt;\"><br /></p></body></html>", nullptr));
        repeatPasswordtxt->setHtml(QCoreApplication::translate("RegisterWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Arial','sans-serif'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Segoe UI'; font-size:9pt;\"><br /></p></body></html>", nullptr));
        zaloguj->setText(QCoreApplication::translate("RegisterWindow", "Sing up", nullptr));
        cancel->setText(QCoreApplication::translate("RegisterWindow", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegisterWindow: public Ui_RegisterWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERWINDOW_H
