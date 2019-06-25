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
    QByteArrayData data[40];
    char stringdata0[396];
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
QT_MOC_LITERAL(13, 120, 13), // "sig_setStatus"
QT_MOC_LITERAL(14, 134, 14), // "sig_testResult"
QT_MOC_LITERAL(15, 149, 3), // "row"
QT_MOC_LITERAL(16, 153, 3), // "col"
QT_MOC_LITERAL(17, 157, 6), // "result"
QT_MOC_LITERAL(18, 164, 17), // "slot_sendChangeIO"
QT_MOC_LITERAL(19, 182, 14), // "slot_resetAxis"
QT_MOC_LITERAL(20, 197, 15), // "slot_writeOutIO"
QT_MOC_LITERAL(21, 213, 4), // "WORD"
QT_MOC_LITERAL(22, 218, 4), // "card"
QT_MOC_LITERAL(23, 223, 5), // "bitNo"
QT_MOC_LITERAL(24, 229, 6), // "bReset"
QT_MOC_LITERAL(25, 236, 12), // "slot_predict"
QT_MOC_LITERAL(26, 249, 5), // "boxID"
QT_MOC_LITERAL(27, 255, 8), // "pannelID"
QT_MOC_LITERAL(28, 264, 8), // "sampleID"
QT_MOC_LITERAL(29, 273, 9), // "slot_load"
QT_MOC_LITERAL(30, 283, 9), // "slot_test"
QT_MOC_LITERAL(31, 293, 11), // "slot_unload"
QT_MOC_LITERAL(32, 305, 9), // "slot_auto"
QT_MOC_LITERAL(33, 315, 14), // "slot_Suspended"
QT_MOC_LITERAL(34, 330, 15), // "slot_MatrixMove"
QT_MOC_LITERAL(35, 346, 9), // "rowMargin"
QT_MOC_LITERAL(36, 356, 9), // "colMargin"
QT_MOC_LITERAL(37, 366, 7), // "onReply"
QT_MOC_LITERAL(38, 374, 14), // "QNetworkReply*"
QT_MOC_LITERAL(39, 389, 6) // "pReply"

    },
    "Motion_thread\0sig_statusChange\0\0"
    "iIoNumber\0iCard\0bIn\0status\0sig_logOutput\0"
    "text\0color\0sig_updateImage\0strPath\0"
    "sig_predict\0sig_setStatus\0sig_testResult\0"
    "row\0col\0result\0slot_sendChangeIO\0"
    "slot_resetAxis\0slot_writeOutIO\0WORD\0"
    "card\0bitNo\0bReset\0slot_predict\0boxID\0"
    "pannelID\0sampleID\0slot_load\0slot_test\0"
    "slot_unload\0slot_auto\0slot_Suspended\0"
    "slot_MatrixMove\0rowMargin\0colMargin\0"
    "onReply\0QNetworkReply*\0pReply"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Motion_thread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    4,  109,    2, 0x06 /* Public */,
       7,    2,  118,    2, 0x06 /* Public */,
       7,    1,  123,    2, 0x26 /* Public | MethodCloned */,
      10,    1,  126,    2, 0x06 /* Public */,
      12,    0,  129,    2, 0x06 /* Public */,
      13,    2,  130,    2, 0x06 /* Public */,
      14,    3,  135,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      18,    2,  142,    2, 0x0a /* Public */,
      19,    0,  147,    2, 0x0a /* Public */,
      20,    4,  148,    2, 0x0a /* Public */,
      20,    3,  157,    2, 0x2a /* Public | MethodCloned */,
      25,    3,  164,    2, 0x0a /* Public */,
      29,    0,  171,    2, 0x0a /* Public */,
      30,    0,  172,    2, 0x0a /* Public */,
      31,    0,  173,    2, 0x0a /* Public */,
      32,    0,  174,    2, 0x0a /* Public */,
      33,    0,  175,    2, 0x0a /* Public */,
      34,    6,  176,    2, 0x0a /* Public */,
      37,    1,  189,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Bool, QMetaType::Int,    3,    4,    5,    6,
    QMetaType::Void, QMetaType::QString, QMetaType::QColor,    8,    9,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,   15,   16,   17,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void,
    QMetaType::Int, 0x80000000 | 21, 0x80000000 | 21, 0x80000000 | 21, QMetaType::Bool,   22,   23,    6,   24,
    QMetaType::Int, 0x80000000 | 21, 0x80000000 | 21, 0x80000000 | 21,   22,   23,    6,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int,   26,   27,   28,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Double, QMetaType::Double, QMetaType::QString, QMetaType::Int,   15,   16,   35,   36,   26,   27,
    QMetaType::QString, 0x80000000 | 38,   39,

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
        case 5: _t->sig_setStatus((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 6: _t->sig_testResult((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 7: _t->slot_sendChangeIO((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 8: _t->slot_resetAxis(); break;
        case 9: { int _r = _t->slot_writeOutIO((*reinterpret_cast< WORD(*)>(_a[1])),(*reinterpret_cast< WORD(*)>(_a[2])),(*reinterpret_cast< WORD(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 10: { int _r = _t->slot_writeOutIO((*reinterpret_cast< WORD(*)>(_a[1])),(*reinterpret_cast< WORD(*)>(_a[2])),(*reinterpret_cast< WORD(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 11: _t->slot_predict((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 12: _t->slot_load(); break;
        case 13: _t->slot_test(); break;
        case 14: _t->slot_unload(); break;
        case 15: _t->slot_auto(); break;
        case 16: _t->slot_Suspended(); break;
        case 17: _t->slot_MatrixMove((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6]))); break;
        case 18: { QString _r = _t->onReply((*reinterpret_cast< QNetworkReply*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 18:
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
        {
            typedef void (Motion_thread::*_t)(QString , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Motion_thread::sig_setStatus)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (Motion_thread::*_t)(int , int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Motion_thread::sig_testResult)) {
                *result = 6;
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
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
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

// SIGNAL 5
void Motion_thread::sig_setStatus(QString _t1, QString _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void Motion_thread::sig_testResult(int _t1, int _t2, int _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
struct qt_meta_stringdata_Motion_thread1_t {
    QByteArrayData data[22];
    char stringdata0[200];
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
QT_MOC_LITERAL(5, 41, 14), // "sig_testResult"
QT_MOC_LITERAL(6, 56, 3), // "row"
QT_MOC_LITERAL(7, 60, 3), // "col"
QT_MOC_LITERAL(8, 64, 6), // "result"
QT_MOC_LITERAL(9, 71, 12), // "slot_predict"
QT_MOC_LITERAL(10, 84, 5), // "boxID"
QT_MOC_LITERAL(11, 90, 8), // "pannelID"
QT_MOC_LITERAL(12, 99, 8), // "sampleID"
QT_MOC_LITERAL(13, 108, 7), // "onReply"
QT_MOC_LITERAL(14, 116, 14), // "QNetworkReply*"
QT_MOC_LITERAL(15, 131, 6), // "pReply"
QT_MOC_LITERAL(16, 138, 13), // "slot_sendPost"
QT_MOC_LITERAL(17, 152, 22), // "QNetworkAccessManager*"
QT_MOC_LITERAL(18, 175, 3), // "buf"
QT_MOC_LITERAL(19, 179, 3), // "url"
QT_MOC_LITERAL(20, 183, 4), // "port"
QT_MOC_LITERAL(21, 188, 11) // "contentType"

    },
    "Motion_thread1\0sig_logOutput\0\0text\0"
    "color\0sig_testResult\0row\0col\0result\0"
    "slot_predict\0boxID\0pannelID\0sampleID\0"
    "onReply\0QNetworkReply*\0pReply\0"
    "slot_sendPost\0QNetworkAccessManager*\0"
    "buf\0url\0port\0contentType"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Motion_thread1[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   49,    2, 0x06 /* Public */,
       1,    1,   54,    2, 0x26 /* Public | MethodCloned */,
       5,    3,   57,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    3,   64,    2, 0x0a /* Public */,
      13,    1,   71,    2, 0x0a /* Public */,
      16,    4,   74,    2, 0x0a /* Public */,
      16,    3,   83,    2, 0x2a /* Public | MethodCloned */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QColor,    3,    4,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    6,    7,    8,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int,   10,   11,   12,
    QMetaType::QString, 0x80000000 | 14,   15,
    0x80000000 | 17, QMetaType::QByteArray, QMetaType::QUrl, QMetaType::Int, QMetaType::QString,   18,   19,   20,   21,
    0x80000000 | 17, QMetaType::QByteArray, QMetaType::QUrl, QMetaType::Int,   18,   19,   20,

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
        case 2: _t->sig_testResult((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 3: _t->slot_predict((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 4: { QString _r = _t->onReply((*reinterpret_cast< QNetworkReply*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 5: { QNetworkAccessManager* _r = _t->slot_sendPost((*reinterpret_cast< QByteArray(*)>(_a[1])),(*reinterpret_cast< QUrl(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< QNetworkAccessManager**>(_a[0]) = _r; }  break;
        case 6: { QNetworkAccessManager* _r = _t->slot_sendPost((*reinterpret_cast< QByteArray(*)>(_a[1])),(*reinterpret_cast< QUrl(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QNetworkAccessManager**>(_a[0]) = _r; }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 4:
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
        {
            typedef void (Motion_thread1::*_t)(int , int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Motion_thread1::sig_testResult)) {
                *result = 2;
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
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void Motion_thread1::sig_logOutput(QString _t1, QColor _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 2
void Motion_thread1::sig_testResult(int _t1, int _t2, int _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
