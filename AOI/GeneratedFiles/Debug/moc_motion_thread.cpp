/****************************************************************************
** Meta object code from reading C++ file 'motion_thread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../motion_thread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'motion_thread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Motion_thread_t {
    QByteArrayData data[9];
    char stringdata0[91];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Motion_thread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Motion_thread_t qt_meta_stringdata_Motion_thread = {
    {
QT_MOC_LITERAL(0, 0, 13), // "Motion_thread"
QT_MOC_LITERAL(1, 14, 16), // "sig_statusChange"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 13), // "sig_logOutput"
QT_MOC_LITERAL(4, 46, 4), // "text"
QT_MOC_LITERAL(5, 51, 5), // "color"
QT_MOC_LITERAL(6, 57, 17), // "slot_sendChangeIO"
QT_MOC_LITERAL(7, 75, 9), // "iIoNumber"
QT_MOC_LITERAL(8, 85, 5) // "iCard"

    },
    "Motion_thread\0sig_statusChange\0\0"
    "sig_logOutput\0text\0color\0slot_sendChangeIO\0"
    "iIoNumber\0iCard"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Motion_thread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,
       3,    2,   35,    2, 0x06 /* Public */,
       3,    1,   40,    2, 0x26 /* Public | MethodCloned */,

 // slots: name, argc, parameters, tag, flags
       6,    2,   43,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QColor,    4,    5,
    QMetaType::Void, QMetaType::QString,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    7,    8,

       0        // eod
};

void Motion_thread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Motion_thread *_t = static_cast<Motion_thread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sig_statusChange(); break;
        case 1: _t->sig_logOutput((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QColor(*)>(_a[2]))); break;
        case 2: _t->sig_logOutput((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->slot_sendChangeIO((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Motion_thread::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Motion_thread::sig_statusChange)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Motion_thread::*_t)(QString , QColor );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Motion_thread::sig_logOutput)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject Motion_thread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_Motion_thread.data,
      qt_meta_data_Motion_thread,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Motion_thread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Motion_thread::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Motion_thread.stringdata0))
        return static_cast<void*>(const_cast< Motion_thread*>(this));
    return QThread::qt_metacast(_clname);
}

int Motion_thread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void Motion_thread::sig_statusChange()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void Motion_thread::sig_logOutput(QString _t1, QColor _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
