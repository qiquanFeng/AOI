/****************************************************************************
** Meta object code from reading C++ file 'aoi.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../aoi.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'aoi.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AOI_t {
    QByteArrayData data[15];
    char stringdata0[154];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AOI_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AOI_t qt_meta_stringdata_AOI = {
    {
QT_MOC_LITERAL(0, 0, 3), // "AOI"
QT_MOC_LITERAL(1, 4, 13), // "sig_logOutput"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 4), // "text"
QT_MOC_LITERAL(4, 24, 5), // "color"
QT_MOC_LITERAL(5, 30, 13), // "git_resetAxis"
QT_MOC_LITERAL(6, 44, 14), // "slot_outputLog"
QT_MOC_LITERAL(7, 59, 12), // "slot_butLoad"
QT_MOC_LITERAL(8, 72, 14), // "slot_butUnLoad"
QT_MOC_LITERAL(9, 87, 11), // "slot_butRun"
QT_MOC_LITERAL(10, 99, 13), // "slot_butReset"
QT_MOC_LITERAL(11, 113, 17), // "slot_IOChangeInfo"
QT_MOC_LITERAL(12, 131, 9), // "iIoNumber"
QT_MOC_LITERAL(13, 141, 5), // "iCard"
QT_MOC_LITERAL(14, 147, 6) // "status"

    },
    "AOI\0sig_logOutput\0\0text\0color\0"
    "git_resetAxis\0slot_outputLog\0slot_butLoad\0"
    "slot_butUnLoad\0slot_butRun\0slot_butReset\0"
    "slot_IOChangeInfo\0iIoNumber\0iCard\0"
    "status"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AOI[] = {

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
       1,    2,   59,    2, 0x06 /* Public */,
       1,    1,   64,    2, 0x26 /* Public | MethodCloned */,
       5,    0,   67,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    2,   68,    2, 0x0a /* Public */,
       7,    0,   73,    2, 0x0a /* Public */,
       8,    0,   74,    2, 0x0a /* Public */,
       9,    0,   75,    2, 0x0a /* Public */,
      10,    0,   76,    2, 0x0a /* Public */,
      11,    3,   77,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QColor,    3,    4,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QColor,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,   12,   13,   14,

       0        // eod
};

void AOI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AOI *_t = static_cast<AOI *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sig_logOutput((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QColor(*)>(_a[2]))); break;
        case 1: _t->sig_logOutput((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->git_resetAxis(); break;
        case 3: _t->slot_outputLog((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QColor(*)>(_a[2]))); break;
        case 4: _t->slot_butLoad(); break;
        case 5: _t->slot_butUnLoad(); break;
        case 6: _t->slot_butRun(); break;
        case 7: _t->slot_butReset(); break;
        case 8: _t->slot_IOChangeInfo((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (AOI::*_t)(QString , QColor );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AOI::sig_logOutput)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (AOI::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AOI::git_resetAxis)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject AOI::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_AOI.data,
      qt_meta_data_AOI,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *AOI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AOI::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_AOI.stringdata0))
        return static_cast<void*>(const_cast< AOI*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int AOI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void AOI::sig_logOutput(QString _t1, QColor _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 2
void AOI::git_resetAxis()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
