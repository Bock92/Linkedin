/****************************************************************************
** Meta object code from reading C++ file 'userwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "userwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'userwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_UserWindow_t {
    QByteArrayData data[16];
    char stringdata[218];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UserWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UserWindow_t qt_meta_stringdata_UserWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "UserWindow"
QT_MOC_LITERAL(1, 11, 13), // "pf_modClicked"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 12), // "pf_okClicked"
QT_MOC_LITERAL(4, 39, 12), // "l_insClicked"
QT_MOC_LITERAL(5, 52, 15), // "l_removeClicked"
QT_MOC_LITERAL(6, 68, 16), // "studi_insClicked"
QT_MOC_LITERAL(7, 85, 19), // "studi_removeClicked"
QT_MOC_LITERAL(8, 105, 14), // "esp_insClicked"
QT_MOC_LITERAL(9, 120, 14), // "esp_modClicked"
QT_MOC_LITERAL(10, 135, 7), // "esp_add"
QT_MOC_LITERAL(11, 143, 10), // "esp_remove"
QT_MOC_LITERAL(12, 154, 12), // "contatti_add"
QT_MOC_LITERAL(13, 167, 15), // "contatti_remove"
QT_MOC_LITERAL(14, 183, 16), // "ok_searchClicked"
QT_MOC_LITERAL(15, 200, 17) // "restoreUserWindow"

    },
    "UserWindow\0pf_modClicked\0\0pf_okClicked\0"
    "l_insClicked\0l_removeClicked\0"
    "studi_insClicked\0studi_removeClicked\0"
    "esp_insClicked\0esp_modClicked\0esp_add\0"
    "esp_remove\0contatti_add\0contatti_remove\0"
    "ok_searchClicked\0restoreUserWindow"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UserWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x08 /* Private */,
       3,    0,   85,    2, 0x08 /* Private */,
       4,    0,   86,    2, 0x08 /* Private */,
       5,    0,   87,    2, 0x08 /* Private */,
       6,    0,   88,    2, 0x08 /* Private */,
       7,    0,   89,    2, 0x08 /* Private */,
       8,    0,   90,    2, 0x08 /* Private */,
       9,    0,   91,    2, 0x08 /* Private */,
      10,    0,   92,    2, 0x08 /* Private */,
      11,    0,   93,    2, 0x08 /* Private */,
      12,    0,   94,    2, 0x08 /* Private */,
      13,    0,   95,    2, 0x08 /* Private */,
      14,    0,   96,    2, 0x08 /* Private */,
      15,    0,   97,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void UserWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        UserWindow *_t = static_cast<UserWindow *>(_o);
        switch (_id) {
        case 0: _t->pf_modClicked(); break;
        case 1: _t->pf_okClicked(); break;
        case 2: _t->l_insClicked(); break;
        case 3: _t->l_removeClicked(); break;
        case 4: _t->studi_insClicked(); break;
        case 5: _t->studi_removeClicked(); break;
        case 6: _t->esp_insClicked(); break;
        case 7: _t->esp_modClicked(); break;
        case 8: _t->esp_add(); break;
        case 9: _t->esp_remove(); break;
        case 10: _t->contatti_add(); break;
        case 11: _t->contatti_remove(); break;
        case 12: _t->ok_searchClicked(); break;
        case 13: _t->restoreUserWindow(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject UserWindow::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_UserWindow.data,
      qt_meta_data_UserWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *UserWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UserWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_UserWindow.stringdata))
        return static_cast<void*>(const_cast< UserWindow*>(this));
    return QWidget::qt_metacast(_clname);
}

int UserWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
