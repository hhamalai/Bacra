#include "routefactory.h"
#include "route.h"
#include <QDebug>

bacra::Route * bacra::RouteFactory::createStop(const QString &routeData)
{
    bacra::Route *newStop = 0;

    try{
        newStop = new bacra::Route();
    }
    catch(std::bad_alloc &e){
        qDebug() << "bacra::RouteFactory::createStop failed to allocate space from heap";
        return NULL;
    }

    qDebug() << "bacra::RouteFactory::createStop: " << routeData;
    return newStop;
}
/*
bacra::Route * bacra::RouteFactory::createRoute(QString &start, QString &stop)
{
    return NULL;
}
*/
