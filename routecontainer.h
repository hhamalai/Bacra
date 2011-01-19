#ifndef ROUTECONTAINER_H
#define ROUTECONTAINER_H

#include <QAbstractListModel>
#include <QMutex>

#include "route.h"
#include "dataextractor.h"

using namespace Qt;

namespace bacra {

class RouteContainer : public QAbstractTableModel
{
    Q_OBJECT
public:
    RouteContainer(DataExtractor *, QObject *parent=0);
    ~RouteContainer();

    int rowCount ( const QModelIndex & parent = QModelIndex() ) const;
    int columnCount ( const QModelIndex & parent = QModelIndex() ) const;
    QVariant data ( const QModelIndex & index, int role = Qt::DisplayRole ) const;
    QVariant headerData ( int section, Qt::Orientation orientation, int role = Qt::DisplayRole ) const;
    Qt::ItemFlags flags ( const QModelIndex & index ) const;
    //Qt::DropActions supportedDropActions() const;
    //QMimeData *mimeData(const QModelIndexList &indexes) const;
    //QStringList mimeTypes() const;

    ///////////////////////////////////////////////////////
    // Stores routes into external file
    void saveRoutes(const QString &pathAndFileName);

    ///////////////////////////////////////////////////////
    // Loads routes from stored text file
    void loadRoutes(const QString &pathAdnFileName);

public slots:
    void indexSelected(const QModelIndex & index);
    void addStopItem(QString);
    void addRouteItem(QString, QString);
    void removeItem(int index);
    void invalidStopData();

signals:
    void removeItemAtIndex(int index);
    void stopAdded();
    void routeAdded();
    void invalidRoute();
    void invalidStop();
    void showDepartures(bacra::Route *);
    void updatedDepartures();
private slots:
    void stopDataReceived(const QString &);
private:
    QList<Route *> mRoutes;
    DataExtractor *mDataExtractor;
};

}

#endif // ROUTECONTAINER_H
