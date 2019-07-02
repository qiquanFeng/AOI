/****************************************************************************
** Meta object code from reading C++ file 'widconfig.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../widconfig.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widconfig.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_widconfig_t {
    QByteArrayData data[13];
    char stringdata0[161];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_widconfig_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_widconfig_t qt_meta_stringdata_widconfig = {
    {
QT_MOC_LITERAL(0, 0, 9), // "widconfig"
QT_MOC_LITERAL(1, 10, 13), // "sig_logOutput"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 4), // "text"
QT_MOC_LITERAL(4, 30, 5), // "color"
QT_MOC_LITERAL(5, 36, 25), // "slot_listWidDoubleClicked"
QT_MOC_LITERAL(6, 62, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(7, 79, 4), // "item"
QT_MOC_LITERAL(8, 84, 14), // "slot_configAdd"
QT_MOC_LITERAL(9, 99, 14), // "slot_configDel"
QT_MOC_LITERAL(10, 114, 15), // "slot_configSave"
QT_MOC_LITERAL(11, 130, 14), // "slot_configFit"
QT_MOC_LITERAL(12, 145, 15) // "slot_updatelist"

    },
    "widconfig\0sig_logOutput\0\0text\0color\0"
    "slot_listWidDoubleClicked\0QListWidgetItem*\0"
    "item\0slot_configAdd\0slot_configDel\0"
    "slot_configSave\0slot_configFit\0"
    "slot_updatelist"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_widconfig[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   54,    2, 0x06 /* Public */,
       1,    1,   59,    2, 0x26 /* Public | MethodCloned */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   62,    2, 0x0a /* Public */,
       8,    0,   65,    2, 0x0a /* Public */,
       9,    0,   66,    2, 0x0a /* Public */,
      10,    0,   67,    2, 0x0a /* Public */,
      11,    0,   68,    2, 0x0a /* Public */,
      12,    0,   69,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QColor,    3,    4,
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void widconfig::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        widconfig *_t = static_cast<widconfig *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sig_logOutput((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QColor(*)>(_a[2]))); break;
        case 1: _t->sig_logOutput((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->slot_listWidDoubleClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 3: _t->slot_configAdd(); break;
        case 4: _t->slot_configDel(); break;
        case 5: _t->slot_configSave(); break;
        case 6: _t->slot_configFit(); break;
        case 7: _t->slot_updatelist(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (widconfig::*_t)(QString , QColor );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&widconfig::sig_logOutput)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject widconfig::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_widconfig.data,
      qt_meta_data_widconfig,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *widconfig::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *widconfig::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_widconfig.stringdata0))
        return static_cast<void*>(const_cast< widconfig*>(this));
    return QDialog::qt_metacast(_clname);
}

int widconfig::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void widconfig::sig_logOutput(QString _t1, QColor _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
