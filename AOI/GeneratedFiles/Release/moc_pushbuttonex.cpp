/****************************************************************************
** Meta object code from reading C++ file 'pushbuttonex.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../pushbuttonex.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pushbuttonex.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PushButtonEx_t {
    QByteArrayData data[7];
    char stringdata0[70];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PushButtonEx_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PushButtonEx_t qt_meta_stringdata_PushButtonEx = {
    {
QT_MOC_LITERAL(0, 0, 12), // "PushButtonEx"
QT_MOC_LITERAL(1, 13, 10), // "sig_sendIO"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 8), // "ioNumber"
QT_MOC_LITERAL(4, 34, 4), // "card"
QT_MOC_LITERAL(5, 39, 12), // "slot_pressed"
QT_MOC_LITERAL(6, 52, 17) // "slot_statusChange"

    },
    "PushButtonEx\0sig_sendIO\0\0ioNumber\0"
    "card\0slot_pressed\0slot_statusChange"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PushButtonEx[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   34,    2, 0x0a /* Public */,
       6,    1,   35,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,

       0        // eod
};

void PushButtonEx::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PushButtonEx *_t = static_cast<PushButtonEx *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sig_sendIO((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->slot_pressed(); break;
        case 2: _t->slot_statusChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (PushButtonEx::*_t)(int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PushButtonEx::sig_sendIO)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject PushButtonEx::staticMetaObject = {
    { &QPushButton::staticMetaObject, qt_meta_stringdata_PushButtonEx.data,
      qt_meta_data_PushButtonEx,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *PushButtonEx::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PushButtonEx::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_PushButtonEx.stringdata0))
        return static_cast<void*>(const_cast< PushButtonEx*>(this));
    return QPushButton::qt_metacast(_clname);
}

int PushButtonEx::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPushButton::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void PushButtonEx::sig_sendIO(int _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
