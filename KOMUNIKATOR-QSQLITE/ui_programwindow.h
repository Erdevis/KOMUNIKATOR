/********************************************************************************
** Form generated from reading UI file 'programwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROGRAMWINDOW_H
#define UI_PROGRAMWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ProgramWindow
{
public:
    QGridLayout *gridLayout_2;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QTextEdit *reading;
    QPushButton *send;
    QTextEdit *writing;
    QFrame *frame_5;
    QGridLayout *gridLayout;
    QListWidget *friendsList;
    QLineEdit *IpEdit;
    QPushButton *znajomiBtn;
    QPushButton *connectBtn;

    void setupUi(QDialog *ProgramWindow)
    {
        if (ProgramWindow->objectName().isEmpty())
            ProgramWindow->setObjectName(QString::fromUtf8("ProgramWindow"));
        ProgramWindow->resize(594, 485);
        gridLayout_2 = new QGridLayout(ProgramWindow);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        frame = new QFrame(ProgramWindow);
        frame->setObjectName(QString::fromUtf8("frame"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(50);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setMinimumSize(QSize(400, 0));
        frame->setStyleSheet(QString::fromUtf8("QWidget {\n"
"            background-color: #f0f8ff; /* Delikatny niebieski kolor t\305\202a */\n"
"            border-radius: 15px; /* Zaokr\304\205glenie rog\303\263w */\n"
"        }"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        reading = new QTextEdit(frame);
        reading->setObjectName(QString::fromUtf8("reading"));
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setPointSize(12);
        reading->setFont(font);
        reading->setStyleSheet(QString::fromUtf8("QTextEdit {\n"
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
"    border: 1px solid #555555; /* Ustaw obramowanie na kolor obramowania bez zmiany grubo\305\233ci */\n"
"    outline: none; /* Wy\305\202\304\205czanie pod\305\233wietlenia po aktywacji */\n"
"}"));

        verticalLayout->addWidget(reading);

        send = new QPushButton(frame);
        send->setObjectName(QString::fromUtf8("send"));
        send->setMinimumSize(QSize(10, 30));
        send->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        verticalLayout->addWidget(send);

        writing = new QTextEdit(frame);
        writing->setObjectName(QString::fromUtf8("writing"));
        writing->setFont(font);
        writing->setStyleSheet(QString::fromUtf8("QTextEdit {\n"
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

        verticalLayout->addWidget(writing);


        gridLayout_2->addWidget(frame, 0, 0, 2, 1);

        frame_5 = new QFrame(ProgramWindow);
        frame_5->setObjectName(QString::fromUtf8("frame_5"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame_5->sizePolicy().hasHeightForWidth());
        frame_5->setSizePolicy(sizePolicy1);
        frame_5->setMaximumSize(QSize(200, 16777215));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame_5);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        friendsList = new QListWidget(frame_5);
        friendsList->setObjectName(QString::fromUtf8("friendsList"));
        friendsList->setMinimumSize(QSize(150, 122));
        friendsList->setStyleSheet(QString::fromUtf8("QListWidget {\n"
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
"QListWidget:focus {\n"
"    border: 2px solid #1e90ff; /* Ustaw obramowanie na kolor obramowania bez zmiany grubo\305\233ci */\n"
"    outline: none; /* Wy\305\202\304\205czanie pod\305\233wietlenia po aktywacji */\n"
"}"));

        gridLayout->addWidget(friendsList, 3, 1, 1, 1);

        IpEdit = new QLineEdit(frame_5);
        IpEdit->setObjectName(QString::fromUtf8("IpEdit"));

        gridLayout->addWidget(IpEdit, 1, 1, 1, 1);

        znajomiBtn = new QPushButton(frame_5);
        znajomiBtn->setObjectName(QString::fromUtf8("znajomiBtn"));
        znajomiBtn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        gridLayout->addWidget(znajomiBtn, 2, 1, 1, 1);

        connectBtn = new QPushButton(frame_5);
        connectBtn->setObjectName(QString::fromUtf8("connectBtn"));

        gridLayout->addWidget(connectBtn, 0, 1, 1, 1);


        gridLayout_2->addWidget(frame_5, 0, 1, 2, 1);


        retranslateUi(ProgramWindow);

        QMetaObject::connectSlotsByName(ProgramWindow);
    } // setupUi

    void retranslateUi(QDialog *ProgramWindow)
    {
        ProgramWindow->setWindowTitle(QCoreApplication::translate("ProgramWindow", "Dialog", nullptr));
        send->setText(QCoreApplication::translate("ProgramWindow", "Send", nullptr));
        znajomiBtn->setText(QCoreApplication::translate("ProgramWindow", "Friends", nullptr));
        connectBtn->setText(QCoreApplication::translate("ProgramWindow", "Connect", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProgramWindow: public Ui_ProgramWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROGRAMWINDOW_H
