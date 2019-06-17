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
    QByteArrayData data[19];
    char stringdata0[189];
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
QT_MOC_LITERAL(3, 32, 9), // "iIoNumber"
QT_MOC_LITERAL(4, 42, 5), // "iCard"
QT_MOC_LITERAL(5, 48, 6), // "status"
QT_MOC_LITERAL(6, 55, 13), // "sig_logOutput"
QT_MOC_LITERAL(7, 69, 4), // "text"
QT_MOC_LITERAL(8, 74, 5), // "color"
QT_MOC_LITERAL(9, 80, 17), // "slot_sendChangeIO"
QT_MOC_LITERAL(10, 98, 14), // "slot_resetAxis"
QT_MOC_LITERAL(11, 113, 9), // "slot_load"
QT_MOC_LITERAL(12, 123, 9), // "slot_test"
QT_MOC_LITERAL(13, 133, 11), // "slot_unload"
QT_MOC_LITERAL(14, 145, 15), // "slot_MatrixMove"
QT_MOC_LITERAL(15, 161, 3), // "row"
QT_MOC_LITERAL(16, 165, 3), // "col"
QT_MOC_LITERAL(17, 169, 9), // "rowMargin"
QT_MOC_LITERAL(18, 179, 9) // "colMargin"

    },
    "Motion_thread\0sig_statusChange\0\0"
    "iIoNumber\0iCard\0status\0sig_logOutput\0"
    "text\0color\0slot_sendChangeIO\0"
    "slot_resetAxis\0slot_load\0slot_test\0"
    "slot_unload\0slot_MatrixMove\0row\0col\0"
    "rowMargin\0colMargin"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Motion_thread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   59,    2, 0x06 /* Public */,
       6,    2,   66,    2, 0x06 /* Public */,
       6,    1,   71,    2, 0x26 /* Public | MethodCloned */,

 // slots: name, argc, parameters, tag, flags
       9,    2,   74,    2, 0x0a /* Public */,
      10,    0,   79,    2, 0x0a /* Public */,
      11,    0,   80,    2, 0x0a /* Public */,
      12,    0,   81,    2, 0x0a /* Public */,
      13,    0,   82,    2, 0x0a /* Public */,
      14,    4,   83,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,    4,    5,
    QMetaType::Void, QMetaType::QString, QMetaType::QColor,    7,    8,
    QMetaType::Void, QMetaType::QString,    7,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Double, QMetaType::Double,   15,   16,   17,   18,

       0        // eod
};

void Motion_thread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Motion_thread *_t = static_cast<Motion_thread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sig_statusChange((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 1: _t->sig_logOutput((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QColor(*)>(_a[2]))); break;
        case 2: _t->sig_logOutput((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->slot_sendChangeIO((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->slot_resetAxis(); break;
        case 5: _t->slot_load(); break;
        case 6: _t->slot_test(); break;
        case 7: _t->slot_unload(); break;
        case 8: _t->slot_MatrixMove((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Motion_thread::*_t)(int , int , int );
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

// SIGNAL 0
void Motion_thread::sig_statusChange(int _t1, int _t2, int _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Motion_thread::sig_logOutput(QString _t1, QColor _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
