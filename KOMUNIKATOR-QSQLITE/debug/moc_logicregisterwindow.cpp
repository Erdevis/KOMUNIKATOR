/****************************************************************************
** Meta object code from reading C++ file 'logicregisterwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../logicregisterwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'logicregisterwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_LogicRegisterWindow_t {
    uint offsetsAndSizes[22];
    char stringdata0[20];
    char stringdata1[13];
    char stringdata2[1];
    char stringdata3[12];
    char stringdata4[5];
    char stringdata5[8];
    char stringdata6[18];
    char stringdata7[19];
    char stringdata8[6];
    char stringdata9[9];
    char stringdata10[15];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_LogicRegisterWindow_t::offsetsAndSizes) + ofs), len 
static const qt_meta_stringdata_LogicRegisterWindow_t qt_meta_stringdata_LogicRegisterWindow = {
    {
        QT_MOC_LITERAL(0, 19),  // "LogicRegisterWindow"
        QT_MOC_LITERAL(20, 12),  // "nieRejestruj"
        QT_MOC_LITERAL(33, 0),  // ""
        QT_MOC_LITERAL(34, 11),  // "zajerestruj"
        QT_MOC_LITERAL(46, 4),  // "User"
        QT_MOC_LITERAL(51, 7),  // "newUser"
        QT_MOC_LITERAL(59, 17),  // "on_cancel_clicked"
        QT_MOC_LITERAL(77, 18),  // "on_zaloguj_clicked"
        QT_MOC_LITERAL(96, 5),  // "login"
        QT_MOC_LITERAL(102, 8),  // "password"
        QT_MOC_LITERAL(111, 14)   // "repeatPassword"
    },
    "LogicRegisterWindow",
    "nieRejestruj",
    "",
    "zajerestruj",
    "User",
    "newUser",
    "on_cancel_clicked",
    "on_zaloguj_clicked",
    "login",
    "password",
    "repeatPassword"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LogicRegisterWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   38,    2, 0x06,    1 /* Public */,
       3,    1,   39,    2, 0x06,    2 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    0,   42,    2, 0x0a,    4 /* Public */,
       7,    3,   43,    2, 0x0a,    5 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Bool, QMetaType::QString, QMetaType::QString, QMetaType::QString,    8,    9,   10,

       0        // eod
};

void LogicRegisterWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<LogicRegisterWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->nieRejestruj(); break;
        case 1: _t->zajerestruj((*reinterpret_cast< std::add_pointer_t<User>>(_a[1]))); break;
        case 2: _t->on_cancel_clicked(); break;
        case 3: { bool _r = _t->on_zaloguj_clicked((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (LogicRegisterWindow::*)();
            if (_t _q_method = &LogicRegisterWindow::nieRejestruj; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (LogicRegisterWindow::*)(const User & );
            if (_t _q_method = &LogicRegisterWindow::zajerestruj; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject LogicRegisterWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_LogicRegisterWindow.offsetsAndSizes,
    qt_meta_data_LogicRegisterWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_LogicRegisterWindow_t
, QtPrivate::TypeAndForceComplete<LogicRegisterWindow, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const User &, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>


>,
    nullptr
} };


const QMetaObject *LogicRegisterWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LogicRegisterWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_LogicRegisterWindow.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int LogicRegisterWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void LogicRegisterWindow::nieRejestruj()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void LogicRegisterWindow::zajerestruj(const User & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
