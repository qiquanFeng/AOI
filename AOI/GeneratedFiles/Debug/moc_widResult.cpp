/****************************************************************************
** Meta object code from reading C++ file 'widResult.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../widResult.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widResult.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_widResult_t {
    QByteArrayData data[12];
    char stringdata0[108];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_widResult_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_widResult_t qt_meta_stringdata_widResult = {
    {
QT_MOC_LITERAL(0, 0, 9), // "widResult"
QT_MOC_LITERAL(1, 10, 11), // "slot_update"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 7), // "bresult"
QT_MOC_LITERAL(4, 31, 7), // "iPannel"
QT_MOC_LITERAL(5, 39, 7), // "iSample"
QT_MOC_LITERAL(6, 47, 11), // "timeProcess"
QT_MOC_LITERAL(7, 59, 7), // "strPath"
QT_MOC_LITERAL(8, 67, 6), // "strMD5"
QT_MOC_LITERAL(9, 74, 11), // "slot_butMD5"
QT_MOC_LITERAL(10, 86, 8), // "__inline"
QT_MOC_LITERAL(11, 95, 12) // "slot_butPath"

    },
    "widResult\0slot_update\0\0bresult\0iPannel\0"
    "iSample\0timeProcess\0strPath\0strMD5\0"
    "slot_butMD5\0__inline\0slot_butPath"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_widResult[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    6,   29,    2, 0x0a /* Public */,
       9,    0,   42,   10, 0x0a /* Public */,
      11,    0,   43,   10, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::QString, QMetaType::QString,    3,    4,    5,    6,    7,    8,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void widResult::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        widResult *_t = static_cast<widResult *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slot_update((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6]))); break;
        case 1: _t->slot_butMD5(); break;
        case 2: _t->slot_butPath(); break;
        default: ;
        }
    }
}

const QMetaObject widResult::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_widResult.data,
      qt_meta_data_widResult,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *widResult::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *widResult::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_widResult.stringdata0))
        return static_cast<void*>(const_cast< widResult*>(this));
    return QWidget::qt_metacast(_clname);
}

int widResult::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
