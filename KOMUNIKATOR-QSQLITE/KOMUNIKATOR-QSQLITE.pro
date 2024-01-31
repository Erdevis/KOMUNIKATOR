QT       += core gui network sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Server.cpp \
    chat.cpp \
    friend_list.cpp \
    group.cpp \
    main.cpp \
    mainwindow.cpp \
    message.cpp \
    messages.cpp \
    programwindow.cpp \
    registerwindow.cpp \
    user.cpp

HEADERS += \
    Server.h \
    chat.h \
    friend_list.h \
    group.h \
    mainwindow.h \
    message.h \
    messages.h \
    programwindow.h \
    registerwindow.h \
    ui_programwindow.h \
    ui_registerwindow.h \
    user.h

FORMS += \
    mainwindow.ui \
    programwindow.ui \
    registerwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
