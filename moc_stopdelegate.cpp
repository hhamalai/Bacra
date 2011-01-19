/****************************************************************************
** Meta object code from reading C++ file 'stopdelegate.h'
**
** Created: Fri Mar 19 16:04:58 2010
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "stopdelegate.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'stopdelegate.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_bacra__StopDelegate[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // signals: signature, parameters, type, tag, flags
      27,   21,   20,   20, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_bacra__StopDelegate[] = {
    "bacra::StopDelegate\0\0index\0"
    "sizeHintChanged(QModelIndex)\0"
};

const QMetaObject bacra::StopDelegate::staticMetaObject = {
    { &QItemDelegate::staticMetaObject, qt_meta_stringdata_bacra__StopDelegate,
      qt_meta_data_bacra__StopDelegate, 0 }
};

const QMetaObject *bacra::StopDelegate::metaObject() const
{
    return &staticMetaObject;
}

void *bacra::StopDelegate::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_bacra__StopDelegate))
        return static_cast<void*>(const_cast< StopDelegate*>(this));
    return QItemDelegate::qt_metacast(_clname);
}

int bacra::StopDelegate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QItemDelegate::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: sizeHintChanged((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void bacra::StopDelegate::sizeHintChanged(const QModelIndex & _t1)const
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(const_cast< bacra::StopDelegate *>(this), &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
