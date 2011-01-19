/****************************************************************************
** Meta object code from reading C++ file 'dataextractor.h'
**
** Created: Fri Mar 19 16:04:59 2010
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "dataextractor.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dataextractor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_bacra__DataExtractor[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // signals: signature, parameters, type, tag, flags
      22,   21,   21,   21, 0x05,
      45,   21,   21,   21, 0x05,
      71,   21,   21,   21, 0x05,

 // slots: signature, parameters, type, tag, flags
      94,   89,   21,   21, 0x0a,
     118,  112,   21,   21, 0x08,
     159,  112,   21,   21, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_bacra__DataExtractor[] = {
    "bacra::DataExtractor\0\0infoResponseReady(int)\0"
    "stopDataReceived(QString)\0invalidStopData()\0"
    "data\0testData(QString)\0reply\0"
    "handleOmatLahdotResponse(QNetworkReply*)\0"
    "handleReittiopasResponse(QNetworkReply*)\0"
};

const QMetaObject bacra::DataExtractor::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_bacra__DataExtractor,
      qt_meta_data_bacra__DataExtractor, 0 }
};

const QMetaObject *bacra::DataExtractor::metaObject() const
{
    return &staticMetaObject;
}

void *bacra::DataExtractor::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_bacra__DataExtractor))
        return static_cast<void*>(const_cast< DataExtractor*>(this));
    return QObject::qt_metacast(_clname);
}

int bacra::DataExtractor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: infoResponseReady((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: stopDataReceived((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: invalidStopData(); break;
        case 3: testData((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: handleOmatLahdotResponse((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 5: handleReittiopasResponse((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void bacra::DataExtractor::infoResponseReady(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void bacra::DataExtractor::stopDataReceived(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void bacra::DataExtractor::invalidStopData()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
