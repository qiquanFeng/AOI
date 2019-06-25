/****************************************************************************
** Meta object code from reading C++ file 'DialogEx_thread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../DialogEx_thread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DialogEx_thread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DialogEx_thread_t {
    QByteArrayData data[8];
    char stringdata0[75];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DialogEx_thread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DialogEx_thread_t qt_meta_stringdata_DialogEx_thread = {
    {
QT_MOC_LITERAL(0, 0, 15), // "DialogEx_thread"
QT_MOC_LITERAL(1, 16, 13), // "sig_sendClose"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 9), // "sig_clear"
QT_MOC_LITERAL(4, 41, 3), // "inx"
QT_MOC_LITERAL(5, 45, 12), // "sig_setStyle"
QT_MOC_LITERAL(6, 58, 8), // "strStyle"
QT_MOC_LITERAL(7, 67, 7) // "strText"

    },
    "DialogEx_thread\0sig_sendClose\0\0sig_clear\0"
    "inx\0sig_setStyle\0strStyle\0strText"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DialogEx_thread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,
       3,    1,   35,    2, 0x06 /* Public */,
       5,    3,   38,    2, 0x06 /* Public */,
       5,    2,   45,    2, 0x26 /* Public | MethodCloned */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::QString,    4,    6,    7,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    4,    6,

       0        // eod
};

void DialogEx_thread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DialogEx_thread *_t = static_cast<DialogEx_thread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sig_sendClose(); break;
        case 1: _t->sig_clear((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->sig_setStyle((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 3: _t->sig_setStyle((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (DialogEx_thread::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DialogEx_thread::sig_sendClose)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (DialogEx_thread::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DialogEx_thread::sig_clear)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (DialogEx_thread::*_t)(int , QString , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DialogEx_thread::sig_setStyle)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject DialogEx_thread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_DialogEx_thread.data,
      qt_meta_data_DialogEx_thread,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *DialogEx_thread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DialogEx_thread::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_DialogEx_thread.stringdata0))
        return static_cast<void*>(const_cast< DialogEx_thread*>(this));
    return QThread::qt_metacast(_clname);
}

int DialogEx_thread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void DialogEx_thread::sig_sendClose()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void DialogEx_thread::sig_clear(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void DialogEx_thread::sig_setStyle(int _t1, QString _t2, QString _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
