#ifndef ROUTEFACTORY_H
#define ROUTEFACTORY_H

#include "route.h"

using namespace Qt;

namespace bacra {

class RouteFactory
{
public:

    //////////////////////////////////////////////////////////
    //
    // Factory function for creating route that represents
    // single stop.
    //
    // param: stopId - Stop number in HKL omatlahdot.fi service
    //
    // return: new instance of Route class
    //
    static Route * createStop(const QString &routeData);

    //////////////////////////////////////////////////////////
    // Factory function for creating route that represents
    // trip from point A to point B.
    //
    // param: start - Name or number of HKL stop
    //
    // return: new instance of Route class
    //
    // static Route * createRoute(QString &start, QString &stop);

private:

    //////////////////////////////////////////////////////////
    // Constructor is declared private because this is a
    // factory class and it provides only static factory
    // functions.
    //
    RouteFactory();

    //////////////////////////////////////////////////////////
    // Default compiler generated copy constructing is prohibited
    //
    RouteFactory(const RouteFactory&);

    //////////////////////////////////////////////////////////
    // Default compiler created assignment is prohibited
    //
    RouteFactory &operator = (const RouteFactory&);

    virtual ~RouteFactory() {}
};

}
#endif // ROUTEFACTORY_H
