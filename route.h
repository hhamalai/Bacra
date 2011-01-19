#ifndef ROUTE_H
#define ROUTE_H

#include <QAbstractListModel>
#include "line.h"
using namespace Qt;

namespace bacra {

class Route : public QAbstractListModel
{
    Q_OBJECT
public:

    Route(QObject *parent = 0);
    ~Route();

    /* Methods for list model */
    //Route(const QString &str, QObject *parent = 0);
    bool parseLines(const QString &str);
    int rowCount ( const QModelIndex & parent = QModelIndex() ) const;
    QVariant data ( const QModelIndex & index, int role = Qt::DisplayRole ) const;
//r    QVariant headerData ( int section, Qt::Orientation orientation, int role = Qt::DisplayRole ) const;

    Qt::ItemFlags flags ( const QModelIndex & index ) const;
    void setName(QString &name);
    const QString &name() const;
    const QString &stopId() const;

    ///////////////////////////////////////////////////
    // Returns route as QString. NOTE you should delete
    // this pointer after you have used it!
     QString *asString();

     ///////////////////////////////////////////////////
     // We must provide assignment operator so this
     // object can be used in QList. If we don't do this
     // then compiler will create one.
     Route &operator = (const Route& rhs);

private:
    QString mStartPoint;
    QString mEndPoint;
    QString mName;
    QString mStopId;
    QList<Line *> mLines;


};

}
#endif // ROUTE_H
