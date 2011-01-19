#include "log.h"
#include <QDebug>
#include <iostream>

void bacra::Log::debug(QString const debugText){
     qDebug() << debugText;
     //std::cout << qPrintable(debugText) << std::endl;
}

void bacra::Log::debugByRef(QString const &debugText){
    qDebug() << debugText;
}
