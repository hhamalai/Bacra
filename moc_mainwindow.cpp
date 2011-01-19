/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Fri Mar 19 16:04:56 2010
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,
      31,   29,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      63,   57,   11,   11, 0x0a,
      93,   11,   11,   11, 0x08,
     110,   11,   11,   11, 0x08,
     128,   11,   11,   11, 0x08,
     142,   11,   11,   11, 0x08,
     157,   11,   11,   11, 0x08,
     169,   11,   11,   11, 0x08,
     182,   11,   11,   11, 0x08,
     201,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0addStop(QString)\0,\0"
    "addRoute(QString,QString)\0route\0"
    "showDepartures(bacra::Route*)\0"
    "addStopClicked()\0addRouteClicked()\0"
    "invalidStop()\0invalidRoute()\0stopAdded()\0"
    "routeAdded()\0updateDepartures()\0"
    "commercialAnnouncement(int)\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
};

const QMetaObject *MainWindow::metaObject() const
{
    return &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: addStop((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: addRoute((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 2: showDepartures((*reinterpret_cast< bacra::Route*(*)>(_a[1]))); break;
        case 3: addStopClicked(); break;
        case 4: addRouteClicked(); break;
        case 5: invalidStop(); break;
        case 6: invalidRoute(); break;
        case 7: stopAdded(); break;
        case 8: routeAdded(); break;
        case 9: updateDepartures(); break;
        case 10: commercialAnnouncement((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::addStop(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::addRoute(QString _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
