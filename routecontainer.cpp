#include "routecontainer.h"
#include "routefactory.h"
#include "route.h"
#include <iostream>
#include <QRegExp>
#include <QRegExpValidator>
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QMimeData>

bacra::RouteContainer::RouteContainer(bacra::DataExtractor *dataExtractor, QObject *parent)
        : QAbstractTableModel(parent)
{
    mDataExtractor = dataExtractor;

    connect(mDataExtractor, SIGNAL(stopDataReceived(const QString &)), this, SLOT(stopDataReceived(const QString&)));
    connect(mDataExtractor, SIGNAL(invalidStopData()), this, SLOT(invalidStopData()));
}


bacra::RouteContainer::~RouteContainer(){
    qDebug() << "RouteContainer destructed";
    delete this->mDataExtractor;
}

int bacra::RouteContainer::rowCount ( const QModelIndex & /* parent */) const
{
    //qDebug() << mRoutes.size();
    return mRoutes.size();
}

int bacra::RouteContainer::columnCount ( const QModelIndex & /* parent */) const
{
    return 2;
}

QVariant bacra::RouteContainer::data ( const QModelIndex & index, int role) const
{
    if (!index.isValid()) {
        return QVariant();
    }

    if (index.row() >= mRoutes.size()) {
        return QVariant();
    }
    if (role == Qt::DisplayRole) {
        if (mRoutes.at(index.row()) == NULL) {
            return QString("");
        }
        if (index.column() == 0) {
            return QString(tr("%1")).arg(mRoutes.at(index.row())->name());
        } else {
            return QString("");
        }
    }
    else {
        return QVariant();
    }
}

QVariant bacra::RouteContainer::headerData ( int /* section */, Qt::Orientation /* orientation */, int /* role */) const
{
    return QVariant(QString(""));
}
/*
bool bacra::RouteContainer::setData ( const QModelIndex & index, const QVariant & value, int  role )
{
    if (!index.isValid()) {
        return false;
    }
    if (index.row() >= mRoutes.size()) {
        return false;
    }
    QString str(value.toString());
    mRoutes.at(index.row())->setName(str);

    return true;
}
*/
Qt::ItemFlags bacra::RouteContainer::flags ( const QModelIndex & /* index */ ) const
{
    /*if (index.row() == 0) {
        return Qt::ItemIsEnabled | Qt::ItemIsEditable;
    }*/
    return Qt::ItemIsEnabled | Qt::ItemIsSelectable/* | Qt::ItemIsDragEnabled | Qt::ItemIsDropEnabled*/;
}
/*
Qt::DropActions bacra::RouteContainer::supportedDropActions() const
{
     return Qt::MoveAction;
}
*/
/*
 QStringList bacra::RouteContainer::mimeTypes() const
 {
     QStringList types;
     types << "application/vnd.text.list";
     return types;
 }

 QMimeData *bacra::RouteContainer::mimeData(const QModelIndexList &indexes) const
 {
     QMimeData *mimeData = new QMimeData();
     QByteArray encodedData;

     QDataStream stream(&encodedData, QIODevice::WriteOnly);

     foreach (QModelIndex index, indexes) {
         if (index.isValid()) {
             QString text = data(index, Qt::DisplayRole).toString();
             stream << text;
         }
     }

     mimeData->setData("application/vnd.text.list", encodedData);
     return mimeData;
 }
*/
/* public slots */

void bacra::RouteContainer::indexSelected(const QModelIndex & index)
{
    if (index.isValid() && index.row() < mRoutes.size()) {
        if (index.column() == 1) {
            std::cout << "1 index selected" << std::endl;
            removeItem(index.row());
        } else if (index.column() == 0) {
            std::cout << "0 index selected" << std::endl;
            emit showDepartures(mRoutes.at(index.row()));
        }
    }
}



void bacra::RouteContainer::addStopItem(QString stopId)
{
    if (stopId.trimmed().length() == 0) {
        emit invalidStop();
        return;
    }

    mDataExtractor->servCallOmatLahdot(stopId);


}

void bacra::RouteContainer::addRouteItem(QString from, QString to)
{
    if (from.trimmed().length() == 0 || to.trimmed().length() == 0) {
        emit invalidRoute();
        return;
    }

    /* fetch & process data */
    /* import data to model */
    /* if valid data */
    beginInsertRows(QModelIndex(), 0, 0);
    Route *r = new Route();
    if (!r->parseLines(from)) {
        delete r;
        emit invalidRoute();
        return;
    }
    mRoutes.prepend(r);
    endInsertRows();
    emit routeAdded();


    /* else nonvalid data */
    // emit invalidRoute();
}

void bacra::RouteContainer::removeItem(int index)
{
    qDebug() << "bacra::RouteContainer::removeItem: removed item " << index;
    beginRemoveRows(QModelIndex(), index, index);
    mRoutes.removeAt(index);
    endRemoveRows();
}

void bacra::RouteContainer::stopDataReceived(const QString &data)
{
    qDebug() << "RouteContainer::stopDataReceived()";
    QStringList stopNameAndLine = data.split(';');
    if (stopNameAndLine.size() != 2) {
        qDebug() << "invalid data";
        return;
    }
    QRegExp rx(".+[(](\\d{1,6})[)]");
    rx.indexIn(stopNameAndLine.at(0));
    QString stopId = rx.cap(1);
    QList<Route *>::ConstIterator it;
    bool routeUpdated = false;
    for (it = mRoutes.begin(); it != mRoutes.end(); it++) {
        qDebug() << "checking " << (*it)->stopId();
        if ((*it)->stopId() == stopId) {
              (*it)->parseLines(data);
              emit updatedDepartures();
              routeUpdated = true;
              qDebug() << "updating " << stopId;
        }
    }
    if (routeUpdated) {
        emit stopAdded();
        return;
    }

    Route *r = bacra::RouteFactory::createStop(data);
    if (!r->parseLines(data)) {
        qDebug() << "RouteContainer::stopDataReceived()";
        emit invalidStop();
        return;
    }

    beginInsertRows(QModelIndex(), 0, 0);
    mRoutes.prepend(r);
    endInsertRows();

    //ok for testing purpose save
    //saveRoutes("./savedata.txt");

    emit stopAdded();
}

void bacra::RouteContainer::invalidStopData()
{
    emit invalidStop();
}

void bacra::RouteContainer::saveRoutes(const QString &pathAndFileName){

    if(mRoutes.size() > 0){
         QFile file(pathAndFileName);

        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)){
            qDebug() << "bacra::RouteContainer::saveRoutes - SAVE FAILED: file " << pathAndFileName;
                return;
        }

        QTextStream out(&file);
        QList<bacra::Route*>::iterator iter;
        qDebug() << "routes!: " << mRoutes.size();

        for(iter = mRoutes.begin() ; iter != mRoutes.end() ; iter++){
            QString *string = (**iter).asString();
            qDebug() << "bacra::RouteContainer::saveRoutes - Saving: "+(*string);
            out << (*string) << "\n";
            delete string;
        }
        file.close();
        qDebug() << "bacra::RouteContainer::saveRoutes - SAVE SUCCEEDED";
    }
    else{
        qDebug() << "bacra::RouteContainer::saveRoutes - No routes to save";
    }


}

void bacra::RouteContainer::loadRoutes(const QString &pathAndFileName){
    QFile file(pathAndFileName);
     if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
            qDebug() << "bacra::RouteContainer::loadRoutes - No routes to load" << pathAndFileName;
            return;
     }

    QTextStream in(&file);
    uint loadCount = 0;
    while(!in.atEnd()){
        QString line = in.readLine();
        stopDataReceived(line);
        loadCount++;
    }
    qDebug() << "bacra::RouteContainer::loadRoutes - Loaded " << loadCount << " routes from disk";
    file.close();

}

