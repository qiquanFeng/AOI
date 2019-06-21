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
    QByteArrayData data[33];
    char stringdata0[329];
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
QT_MOC_LITERAL(5, 48, 3), // "bIn"
QT_MOC_LITERAL(6, 52, 6), // "status"
QT_MOC_LITERAL(7, 59, 13), // "sig_logOutput"
QT_MOC_LITERAL(8, 73, 4), // "text"
QT_MOC_LITERAL(9, 78, 5), // "color"
QT_MOC_LITERAL(10, 84, 15), // "sig_updateImage"
QT_MOC_LITERAL(11, 100, 7), // "strPath"
QT_MOC_LITERAL(12, 108, 11), // "sig_predict"
QT_MOC_LITERAL(13, 120, 17), // "slot_sendChangeIO"
QT_MOC_LITERAL(14, 138, 14), // "slot_resetAxis"
QT_MOC_LITERAL(15, 153, 15), // "slot_writeOutIO"
QT_MOC_LITERAL(16, 169, 4), // "WORD"
QT_MOC_LITERAL(17, 174, 4), // "card"
QT_MOC_LITERAL(18, 179, 5), // "bitNo"
QT_MOC_LITERAL(19, 185, 12), // "slot_predict"
QT_MOC_LITERAL(20, 198, 9), // "slot_load"
QT_MOC_LITERAL(21, 208, 9), // "slot_test"
QT_MOC_LITERAL(22, 218, 11), // "slot_unload"
QT_MOC_LITERAL(23, 230, 9), // "slot_auto"
QT_MOC_LITERAL(24, 240, 14), // "slot_Suspended"
QT_MOC_LITERAL(25, 255, 15), // "slot_MatrixMove"
QT_MOC_LITERAL(26, 271, 3), // "row"
QT_MOC_LITERAL(27, 275, 3), // "col"
QT_MOC_LITERAL(28, 279, 9), // "rowMargin"
QT_MOC_LITERAL(29, 289, 9), // "colMargin"
QT_MOC_LITERAL(30, 299, 7), // "onReply"
QT_MOC_LITERAL(31, 307, 14), // "QNetworkReply*"
QT_MOC_LITERAL(32, 322, 6) // "pReply"

    },
    "Motion_thread\0sig_statusChange\0\0"
    "iIoNumber\0iCard\0bIn\0status\0sig_logOutput\0"
    "text\0color\0sig_updateImage\0strPath\0"
    "sig_predict\0slot_sendChangeIO\0"
    "slot_resetAxis\0slot_writeOutIO\0WORD\0"
    "card\0bitNo\0slot_predict\0slot_load\0"
    "slot_test\0slot_unload\0slot_auto\0"
    "slot_Suspended\0slot_MatrixMove\0row\0"
    "col\0rowMargin\0colMargin\0onReply\0"
    "QNetworkReply*\0pReply"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Motion_thread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    4,   94,    2, 0x06 /* Public */,
       7,    2,  103,    2, 0x06 /* Public */,
       7,    1,  108,    2, 0x26 /* Public | MethodCloned */,
      10,    1,  111,    2, 0x06 /* Public */,
      12,    0,  114,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      13,    2,  115,    2, 0x0a /* Public */,
      14,    0,  120,    2, 0x0a /* Public */,
      15,    3,  121,    2, 0x0a /* Public */,
      19,    0,  128,    2, 0x0a /* Public */,
      20,    0,  129,    2, 0x0a /* Public */,
      21,    0,  130,    2, 0x0a /* Public */,
      22,    0,  131,    2, 0x0a /* Public */,
      23,    0,  132,    2, 0x0a /* Public */,
      24,    0,  133,    2, 0x0a /* Public */,
      25,    4,  134,    2, 0x0a /* Public */,
      30,    1,  143,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Bool, QMetaType::Int,    3,    4,    5,    6,
    QMetaType::Void, QMetaType::QString, QMetaType::QColor,    8,    9,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void,
    QMetaType::Int, 0x80000000 | 16, 0x80000000 | 16, 0x80000000 | 16,   17,   18,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Double, QMetaType::Double,   26,   27,   28,   29,
    QMetaType::QString, 0x80000000 | 31,   32,

       0        // eod
};

void Motion_thread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Motion_thread *_t = static_cast<Motion_thread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sig_statusChange((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 1: _t->sig_logOutput((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QColor(*)>(_a[2]))); break;
        case 2: _t->sig_logOutput((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->sig_updateImage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->sig_predict(); break;
        case 5: _t->slot_sendChangeIO((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->slot_resetAxis(); break;
        case 7: { int _r = _t->slot_writeOutIO((*reinterpret_cast< WORD(*)>(_a[1])),(*reinterpret_cast< WORD(*)>(_a[2])),(*reinterpret_cast< WORD(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 8: _t->slot_predict(); break;
        case 9: _t->slot_load(); break;
        case 10: _t->slot_test(); break;
        case 11: _t->slot_unload(); break;
        case 12: _t->slot_auto(); break;
        case 13: _t->slot_Suspended(); break;
        case 14: _t->slot_MatrixMove((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4]))); break;
        case 15: { QString _r = _t->onReply((*reinterpret_cast< QNetworkReply*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 15:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Motion_thread::*_t)(int , int , bool , int );
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
        {
            typedef void (Motion_thread::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Motion_thread::sig_updateImage)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (Motion_thread::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Motion_thread::sig_predict)) {
                *result = 4;
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
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void Motion_thread::sig_statusChange(int _t1, int _t2, bool _t3, int _t4)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Motion_thread::sig_logOutput(QString _t1, QColor _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 3
void Motion_thread::sig_updateImage(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Motion_thread::sig_predict()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}
struct qt_meta_stringdata_Motion_thread1_t {
    QByteArrayData data[15];
    char stringdata0[146];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Motion_thread1_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Motion_thread1_t qt_meta_stringdata_Motion_thread1 = {
    {
QT_MOC_LITERAL(0, 0, 14), // "Motion_thread1"
QT_MOC_LITERAL(1, 15, 13), // "sig_logOutput"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 4), // "text"
QT_MOC_LITERAL(4, 35, 5), // "color"
QT_MOC_LITERAL(5, 41, 12), // "slot_predict"
QT_MOC_LITERAL(6, 54, 7), // "onReply"
QT_MOC_LITERAL(7, 62, 14), // "QNetworkReply*"
QT_MOC_LITERAL(8, 77, 6), // "pReply"
QT_MOC_LITERAL(9, 84, 13), // "slot_sendPost"
QT_MOC_LITERAL(10, 98, 22), // "QNetworkAccessManager*"
QT_MOC_LITERAL(11, 121, 3), // "buf"
QT_MOC_LITERAL(12, 125, 3), // "url"
QT_MOC_LITERAL(13, 129, 4), // "port"
QT_MOC_LITERAL(14, 134, 11) // "contentType"

    },
    "Motion_thread1\0sig_logOutput\0\0text\0"
    "color\0slot_predict\0onReply\0QNetworkReply*\0"
    "pReply\0slot_sendPost\0QNetworkAccessManager*\0"
    "buf\0url\0port\0contentType"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Motion_thread1[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   44,    2, 0x06 /* Public */,
       1,    1,   49,    2, 0x26 /* Public | MethodCloned */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   52,    2, 0x0a /* Public */,
       6,    1,   53,    2, 0x0a /* Public */,
       9,    4,   56,    2, 0x0a /* Public */,
       9,    3,   65,    2, 0x2a /* Public | MethodCloned */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QColor,    3,    4,
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::QString, 0x80000000 | 7,    8,
    0x80000000 | 10, QMetaType::QByteArray, QMetaType::QUrl, QMetaType::Int, QMetaType::QString,   11,   12,   13,   14,
    0x80000000 | 10, QMetaType::QByteArray, QMetaType::QUrl, QMetaType::Int,   11,   12,   13,

       0        // eod
};

void Motion_thread1::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Motion_thread1 *_t = static_cast<Motion_thread1 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sig_logOutput((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QColor(*)>(_a[2]))); break;
        case 1: _t->sig_logOutput((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->slot_predict(); break;
        case 3: { QString _r = _t->onReply((*reinterpret_cast< QNetworkReply*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 4: { QNetworkAccessManager* _r = _t->slot_sendPost((*reinterpret_cast< QByteArray(*)>(_a[1])),(*reinterpret_cast< QUrl(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< QNetworkAccessManager**>(_a[0]) = _r; }  break;
        case 5: { QNetworkAccessManager* _r = _t->slot_sendPost((*reinterpret_cast< QByteArray(*)>(_a[1])),(*reinterpret_cast< QUrl(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QNetworkAccessManager**>(_a[0]) = _r; }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Motion_thread1::*_t)(QString , QColor );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Motion_thread1::sig_logOutput)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject Motion_thread1::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_Motion_thread1.data,
      qt_meta_data_Motion_thread1,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Motion_thread1::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Motion_thread1::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Motion_thread1.stringdata0))
        return static_cast<void*>(const_cast< Motion_thread1*>(this));
    return QThread::qt_metacast(_clname);
}

int Motion_thread1::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void Motion_thread1::sig_logOutput(QString _t1, QColor _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
