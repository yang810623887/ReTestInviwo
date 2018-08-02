/****************************************************************************
** Meta object code from reading C++ file 'MyInvowo.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MyInvowo.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MyInvowo.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MyInvowo_t {
    QByteArrayData data[11];
    char stringdata0[179];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyInvowo_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyInvowo_t qt_meta_stringdata_MyInvowo = {
    {
QT_MOC_LITERAL(0, 0, 8), // "MyInvowo"
QT_MOC_LITERAL(1, 9, 12), // "newWorkspace"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 13), // "openWorkSpace"
QT_MOC_LITERAL(4, 37, 19), // "openRecentWorkspace"
QT_MOC_LITERAL(5, 57, 24), // "clearRecentWorkspaceMenu"
QT_MOC_LITERAL(6, 82, 13), // "saveWorkspace"
QT_MOC_LITERAL(7, 96, 15), // "saveWorkspaceAs"
QT_MOC_LITERAL(8, 112, 19), // "saveWorkspaceAsCopy"
QT_MOC_LITERAL(9, 132, 24), // "fillExampleWorkspaceMenu"
QT_MOC_LITERAL(10, 157, 21) // "fillTestWorkspaceMenu"

    },
    "MyInvowo\0newWorkspace\0\0openWorkSpace\0"
    "openRecentWorkspace\0clearRecentWorkspaceMenu\0"
    "saveWorkspace\0saveWorkspaceAs\0"
    "saveWorkspaceAsCopy\0fillExampleWorkspaceMenu\0"
    "fillTestWorkspaceMenu"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyInvowo[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x0a /* Public */,
       3,    0,   60,    2, 0x0a /* Public */,
       4,    0,   61,    2, 0x0a /* Public */,
       5,    0,   62,    2, 0x0a /* Public */,
       6,    0,   63,    2, 0x0a /* Public */,
       7,    0,   64,    2, 0x0a /* Public */,
       8,    0,   65,    2, 0x0a /* Public */,
       9,    0,   66,    2, 0x0a /* Public */,
      10,    0,   67,    2, 0x0a /* Public */,

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

       0        // eod
};

void MyInvowo::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MyInvowo *_t = static_cast<MyInvowo *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->newWorkspace(); break;
        case 1: _t->openWorkSpace(); break;
        case 2: _t->openRecentWorkspace(); break;
        case 3: _t->clearRecentWorkspaceMenu(); break;
        case 4: _t->saveWorkspace(); break;
        case 5: _t->saveWorkspaceAs(); break;
        case 6: _t->saveWorkspaceAsCopy(); break;
        case 7: _t->fillExampleWorkspaceMenu(); break;
        case 8: _t->fillTestWorkspaceMenu(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject MyInvowo::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MyInvowo.data,
      qt_meta_data_MyInvowo,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MyInvowo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyInvowo::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MyInvowo.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MyInvowo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
