/****************************************************************************
** Meta object code from reading C++ file 'DialogEx.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../DialogEx.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DialogEx.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DialogEx_t {
    QByteArrayData data[13];
    char stringdata0[127];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DialogEx_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DialogEx_t qt_meta_stringdata_DialogEx = {
    {
QT_MOC_LITERAL(0, 0, 8), // "DialogEx"
QT_MOC_LITERAL(1, 9, 10), // "sig_commit"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 10), // "slot_clear"
QT_MOC_LITERAL(4, 32, 7), // "QLabel*"
QT_MOC_LITERAL(5, 40, 13), // "slot_setStyle"
QT_MOC_LITERAL(6, 54, 3), // "inx"
QT_MOC_LITERAL(7, 58, 8), // "strStyle"
QT_MOC_LITERAL(8, 67, 7), // "strText"
QT_MOC_LITERAL(9, 75, 17), // "slot_closeWindown"
QT_MOC_LITERAL(10, 93, 11), // "slot_commit"
QT_MOC_LITERAL(11, 105, 11), // "slot_setLot"
QT_MOC_LITERAL(12, 117, 9) // "lotNumber"

    },
    "DialogEx\0sig_commit\0\0slot_clear\0QLabel*\0"
    "slot_setStyle\0inx\0strStyle\0strText\0"
    "slot_closeWindown\0slot_commit\0slot_setLot\0"
    "lotNumber"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DialogEx[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   52,    2, 0x0a /* Public */,
       5,    3,   55,    2, 0x0a /* Public */,
       3,    0,   62,    2, 0x0a /* Public */,
       9,    0,   63,    2, 0x0a /* Public */,
      10,    0,   64,    2, 0x0a /* Public */,
      11,    1,   65,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QStringList,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::QString,    6,    7,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   12,

       0        // eod
};

void DialogEx::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DialogEx *_t = static_cast<DialogEx *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sig_commit((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 1: _t->slot_clear((*reinterpret_cast< QLabel*(*)>(_a[1]))); break;
        case 2: _t->slot_setStyle((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 3: _t->slot_clear(); break;
        case 4: _t->slot_closeWindown(); break;
        case 5: _t->slot_commit(); break;
        case 6: _t->slot_setLot((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QLabel* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (DialogEx::*_t)(QStringList );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DialogEx::sig_commit)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject DialogEx::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_DialogEx.data,
      qt_meta_data_DialogEx,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *DialogEx::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DialogEx::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_DialogEx.stringdata0))
        return static_cast<void*>(const_cast< DialogEx*>(this));
    return QDialog::qt_metacast(_clname);
}

int DialogEx::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
void DialogEx::sig_commit(QStringList _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
