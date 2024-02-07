/****************************************************************************
** Meta object code from reading C++ file 'programwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../programwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'programwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ProgramWindow_t {
    uint offsetsAndSizes[28];
    char stringdata0[14];
    char stringdata1[15];
    char stringdata2[1];
    char stringdata3[6];
    char stringdata4[16];
    char stringdata5[22];
    char stringdata6[22];
    char stringdata7[27];
    char stringdata8[17];
    char stringdata9[5];
    char stringdata10[24];
    char stringdata11[11];
    char stringdata12[8];
    char stringdata13[13];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_ProgramWindow_t::offsetsAndSizes) + ofs), len 
static const qt_meta_stringdata_ProgramWindow_t qt_meta_stringdata_ProgramWindow = {
    {
        QT_MOC_LITERAL(0, 13),  // "ProgramWindow"
        QT_MOC_LITERAL(14, 14),  // "updateUserList"
        QT_MOC_LITERAL(29, 0),  // ""
        QT_MOC_LITERAL(30, 5),  // "users"
        QT_MOC_LITERAL(36, 15),  // "on_send_clicked"
        QT_MOC_LITERAL(52, 21),  // "on_znajomiBtn_clicked"
        QT_MOC_LITERAL(74, 21),  // "on_connectBtn_clicked"
        QT_MOC_LITERAL(96, 26),  // "on_friendsList_itemClicked"
        QT_MOC_LITERAL(123, 16),  // "QListWidgetItem*"
        QT_MOC_LITERAL(140, 4),  // "item"
        QT_MOC_LITERAL(145, 23),  // "on_disconectBtn_clicked"
        QT_MOC_LITERAL(169, 10),  // "addMessage"
        QT_MOC_LITERAL(180, 7),  // "message"
        QT_MOC_LITERAL(188, 12)   // "isSentByUser"
    },
    "ProgramWindow",
    "updateUserList",
    "",
    "users",
    "on_send_clicked",
    "on_znajomiBtn_clicked",
    "on_connectBtn_clicked",
    "on_friendsList_itemClicked",
    "QListWidgetItem*",
    "item",
    "on_disconectBtn_clicked",
    "addMessage",
    "message",
    "isSentByUser"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ProgramWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   56,    2, 0x0a,    1 /* Public */,
       4,    0,   59,    2, 0x08,    3 /* Private */,
       5,    0,   60,    2, 0x08,    4 /* Private */,
       6,    0,   61,    2, 0x08,    5 /* Private */,
       7,    1,   62,    2, 0x08,    6 /* Private */,
      10,    0,   65,    2, 0x08,    8 /* Private */,
      11,    2,   66,    2, 0x08,    9 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QStringList,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,   12,   13,

       0        // eod
};

void ProgramWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ProgramWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->updateUserList((*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[1]))); break;
        case 1: _t->on_send_clicked(); break;
        case 2: _t->on_znajomiBtn_clicked(); break;
        case 3: _t->on_connectBtn_clicked(); break;
        case 4: _t->on_friendsList_itemClicked((*reinterpret_cast< std::add_pointer_t<QListWidgetItem*>>(_a[1]))); break;
        case 5: _t->on_disconectBtn_clicked(); break;
        case 6: _t->addMessage((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject ProgramWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_ProgramWindow.offsetsAndSizes,
    qt_meta_data_ProgramWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_ProgramWindow_t
, QtPrivate::TypeAndForceComplete<ProgramWindow, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QStringList &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QListWidgetItem *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>


>,
    nullptr
} };


const QMetaObject *ProgramWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ProgramWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ProgramWindow.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int ProgramWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
