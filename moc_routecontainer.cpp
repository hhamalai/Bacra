/****************************************************************************
** Meta object code from reading C++ file 'routecontainer.h'
**
** Created: Fri Mar 19 16:04:57 2010
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "routecontainer.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'routecontainer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_bacra__RouteContainer[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // signals: signature, parameters, type, tag, flags
      29,   23,   22,   22, 0x05,
      52,   22,   22,   22, 0x05,
      64,   22,   22,   22, 0x05,
      77,   22,   22,   22, 0x05,
      92,   22,   22,   22, 0x05,
     106,   22,   22,   22, 0x05,
     136,   22,   22,   22, 0x05,

 // slots: signature, parameters, type, tag, flags
     156,   23,   22,   22, 0x0a,
     183,   22,   22,   22, 0x0a,
     206,  204,   22,   22, 0x0a,
     236,   23,   22,   22, 0x0a,
     252,   22,   22,   22, 0x0a,
     270,   22,   22,   22, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_bacra__RouteContainer[] = {
    "bacra::RouteContainer\0\0index\0"
    "removeItemAtIndex(int)\0stopAdded()\0"
    "routeAdded()\0invalidRoute()\0invalidStop()\0"
    "showDepartures(bacra::Route*)\0"
    "updatedDepartures()\0indexSelected(QModelIndex)\0"
    "addStopItem(QString)\0,\0"
    "addRouteItem(QString,QString)\0"
    "removeItem(int)\0invalidStopData()\0"
    "stopDataReceived(QString)\0"
};

const QMetaObject bacra::RouteContainer::staticMetaObject = {
    { &QAbstractTableModel::staticMetaObject, qt_meta_stringdata_bacra__RouteContainer,
      qt_meta_data_bacra__RouteContainer, 0 }
};

const QMetaObject *bacra::RouteContainer::metaObject() const
{
    return &staticMetaObject;
}

void *bacra::RouteContainer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_bacra__RouteContainer))
        return static_cast<void*>(const_cast< RouteContainer*>(this));
    return QAbstractTableModel::qt_metacast(_clname);
}

int bacra::RouteContainer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractTableModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: removeItemAtIndex((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: stopAdded(); break;
        case 2: routeAdded(); break;
        case 3: invalidRoute(); break;
        case 4: invalidStop(); break;
        case 5: showDepartures((*reinterpret_cast< bacra::Route*(*)>(_a[1]))); break;
        case 6: updatedDepartures(); break;
        case 7: indexSelected((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 8: addStopItem((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: addRouteItem((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 10: removeItem((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: invalidStopData(); break;
        case 12: stopDataReceived((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void bacra::RouteContainer::removeItemAtIndex(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void bacra::RouteContainer::stopAdded()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void bacra::RouteContainer::routeAdded()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void bacra::RouteContainer::invalidRoute()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void bacra::RouteContainer::invalidStop()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}

// SIGNAL 5
void bacra::RouteContainer::showDepartures(bacra::Route * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void bacra::RouteContainer::updatedDepartures()
{
    QMetaObject::activate(this, &staticMetaObject, 6, 0);
}
QT_END_MOC_NAMESPACE
