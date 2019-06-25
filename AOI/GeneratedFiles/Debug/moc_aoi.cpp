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
    QByteArrayData data[33];
    char stringdata0[351];
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
QT_MOC_LITERAL(5, 30, 13), // "sig_resetAxis"
QT_MOC_LITERAL(6, 44, 8), // "sig_load"
QT_MOC_LITERAL(7, 53, 10), // "sig_unload"
QT_MOC_LITERAL(8, 64, 8), // "sig_test"
QT_MOC_LITERAL(9, 73, 8), // "sig_auto"
QT_MOC_LITERAL(10, 82, 13), // "sig_Suspended"
QT_MOC_LITERAL(11, 96, 14), // "slot_outputLog"
QT_MOC_LITERAL(12, 111, 12), // "slot_butLoad"
QT_MOC_LITERAL(13, 124, 14), // "slot_butUnLoad"
QT_MOC_LITERAL(14, 139, 11), // "slot_butRun"
QT_MOC_LITERAL(15, 151, 13), // "slot_butReset"
QT_MOC_LITERAL(16, 165, 12), // "slot_butAuto"
QT_MOC_LITERAL(17, 178, 17), // "slot_butSuspended"
QT_MOC_LITERAL(18, 196, 17), // "slot_IOChangeInfo"
QT_MOC_LITERAL(19, 214, 9), // "iIoNumber"
QT_MOC_LITERAL(20, 224, 5), // "iCard"
QT_MOC_LITERAL(21, 230, 3), // "bIn"
QT_MOC_LITERAL(22, 234, 6), // "status"
QT_MOC_LITERAL(23, 241, 11), // "slot_Option"
QT_MOC_LITERAL(24, 253, 16), // "slot_updateImage"
QT_MOC_LITERAL(25, 270, 7), // "strPath"
QT_MOC_LITERAL(26, 278, 12), // "slot_butStop"
QT_MOC_LITERAL(27, 291, 14), // "slot_setStatus"
QT_MOC_LITERAL(28, 306, 8), // "strStyle"
QT_MOC_LITERAL(29, 315, 20), // "slot_setCameraResult"
QT_MOC_LITERAL(30, 336, 3), // "row"
QT_MOC_LITERAL(31, 340, 3), // "col"
QT_MOC_LITERAL(32, 344, 6) // "result"

    },
    "AOI\0sig_logOutput\0\0text\0color\0"
    "sig_resetAxis\0sig_load\0sig_unload\0"
    "sig_test\0sig_auto\0sig_Suspended\0"
    "slot_outputLog\0slot_butLoad\0slot_butUnLoad\0"
    "slot_butRun\0slot_butReset\0slot_butAuto\0"
    "slot_butSuspended\0slot_IOChangeInfo\0"
    "iIoNumber\0iCard\0bIn\0status\0slot_Option\0"
    "slot_updateImage\0strPath\0slot_butStop\0"
    "slot_setStatus\0strStyle\0slot_setCameraResult\0"
    "row\0col\0result"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AOI[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      21,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,  119,    2, 0x06 /* Public */,
       1,    1,  124,    2, 0x26 /* Public | MethodCloned */,
       5,    0,  127,    2, 0x06 /* Public */,
       6,    0,  128,    2, 0x06 /* Public */,
       7,    0,  129,    2, 0x06 /* Public */,
       8,    0,  130,    2, 0x06 /* Public */,
       9,    0,  131,    2, 0x06 /* Public */,
      10,    0,  132,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    2,  133,    2, 0x0a /* Public */,
      12,    0,  138,    2, 0x0a /* Public */,
      13,    0,  139,    2, 0x0a /* Public */,
      14,    0,  140,    2, 0x0a /* Public */,
      15,    0,  141,    2, 0x0a /* Public */,
      16,    0,  142,    2, 0x0a /* Public */,
      17,    0,  143,    2, 0x0a /* Public */,
      18,    4,  144,    2, 0x0a /* Public */,
      23,    0,  153,    2, 0x0a /* Public */,
      24,    1,  154,    2, 0x0a /* Public */,
      26,    0,  157,    2, 0x0a /* Public */,
      27,    2,  158,    2, 0x0a /* Public */,
      29,    3,  163,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QColor,    3,    4,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QColor,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Bool, QMetaType::Int,   19,   20,   21,   22,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   25,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   22,   28,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,   30,   31,   32,

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
        case 2: _t->sig_resetAxis(); break;
        case 3: _t->sig_load(); break;
        case 4: _t->sig_unload(); break;
        case 5: _t->sig_test(); break;
        case 6: _t->sig_auto(); break;
        case 7: _t->sig_Suspended(); break;
        case 8: _t->slot_outputLog((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QColor(*)>(_a[2]))); break;
        case 9: _t->slot_butLoad(); break;
        case 10: _t->slot_butUnLoad(); break;
        case 11: _t->slot_butRun(); break;
        case 12: _t->slot_butReset(); break;
        case 13: _t->slot_butAuto(); break;
        case 14: _t->slot_butSuspended(); break;
        case 15: _t->slot_IOChangeInfo((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 16: _t->slot_Option(); break;
        case 17: _t->slot_updateImage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 18: _t->slot_butStop(); break;
        case 19: _t->slot_setStatus((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 20: _t->slot_setCameraResult((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
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
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AOI::sig_resetAxis)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (AOI::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AOI::sig_load)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (AOI::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AOI::sig_unload)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (AOI::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AOI::sig_test)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (AOI::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AOI::sig_auto)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (AOI::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AOI::sig_Suspended)) {
                *result = 7;
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
        if (_id < 21)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 21;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 21)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 21;
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
void AOI::sig_resetAxis()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void AOI::sig_load()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void AOI::sig_unload()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void AOI::sig_test()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}

// SIGNAL 6
void AOI::sig_auto()
{
    QMetaObject::activate(this, &staticMetaObject, 6, Q_NULLPTR);
}

// SIGNAL 7
void AOI::sig_Suspended()
{
    QMetaObject::activate(this, &staticMetaObject, 7, Q_NULLPTR);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
