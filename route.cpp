#include "route.h"
#include <iostream>
#include "log.h"
#include <QDebug>
#include <QStringList>
#include <QRegExpValidator>
#include <QRegExp>
#include "line.h"
bacra::Route::Route(QObject *parent)
        : QAbstractListModel(parent){  
}

bool bacra::Route::parseLines(const QString &str)
{
    // case for single stop
    // format for single stop is
    // <stop name>[1..1];<line comma separated>[1..n]

    //first is stop name and last are lines
     QStringList stopNameAndLine = str.split(';');
     mLines.clear();
     if(stopNameAndLine.size() == 2){
        QString stopName = stopNameAndLine.at(0);
        mName = stopName;
        QRegExp rx(".+[(](\\d{1,6})[)]");
        if (rx.indexIn(stopName) != -1) {
            qDebug() << "got stopID" << rx.cap(1);
            mStopId = rx.cap(1);
        } else {
            qDebug() << "Unable to get stopID";
        }
        qDebug() << "creating stop" << stopName;
        QString str = stopNameAndLine.at(1);
        QStringList lines = str.split('#');
        //rx.setPattern("\\d{2}:\\d{2}\\s*\\S*,\\S{1,5},\\S+");
        rx.setPattern("\\d{2}:\\d{2}\\s*\\S*,\\S{1,5},\\S+\\s{0,1}\\S+");
        QRegExpValidator v(rx, 0);
        if(lines.size() >= 1){
            //Ok we have some lines
             QList<QString>::const_iterator lineIterator;
             for (lineIterator = lines.begin(); lineIterator != lines.end(); lineIterator++){
                //single line is comma separated and contains
                // line time, lineNumber and Endpoint
                 //13:55,68,Rautatientori

                QString data = *lineIterator;

                int pos = 0;

                if (v.validate(data, pos) != QValidator::Acceptable) {
                    qDebug() << "invalid data: " << data;
                    continue;
                }

                bacra::Line *line = new bacra::Line(data);
                mLines.append(line);
             }
             return true;
         }
     }
     return false;
}

bacra::Route &bacra::Route::operator = (const Route &rhs){
    mStartPoint = rhs.mStartPoint;
    mEndPoint = rhs.mEndPoint;
    mName = rhs.mName;
    mStopId = rhs.mStopId;
    mLines.append(rhs.mLines);

    return *this;
}

bacra::Route::~Route(){
    qDebug() << "Route destructed";
}




int bacra::Route::rowCount ( const QModelIndex &/* parent */) const
{
    return mLines.size();
}

QVariant bacra::Route::data ( const QModelIndex & index, int role) const
{
    if (!index.isValid()) {
        return QVariant();
    }

    if (index.row() >= mLines.size()) {
        return QVariant();
    }
    if (role == Qt::DisplayRole) {
        return QString(tr("%1 - %2 - %3"))
                .arg(mLines.at(index.row())->time())
                .arg(mLines.at(index.row())->lineName())
                .arg(mLines.at(index.row())->lineEnd());
    }
    else {
        return QVariant();
    }
}

//QVariant bacra::Route::headerData ( int /* section */, Qt::Orientation /* orientation */, int /* role */) const
//{//
//}

Qt::ItemFlags bacra::Route::flags ( const QModelIndex & /* index */ ) const
{
    return Qt::ItemIsEnabled;
}

const QString &bacra::Route::name() const
{
    return mName;
}

void bacra::Route::setName(QString &name)
{
        mName = name;
}

 QString *bacra::Route::asString(){
    //This returns string representation for
    // single route and its lines
    QList<bacra::Line*>::const_iterator iter;
    QString *stringRep = new QString(mName);
    stringRep->append(";");
    for(iter = mLines.begin() ;iter != mLines.end(); iter++){
        bacra::Line *line = (*iter);
        stringRep->append(line->asString());
    }

    return stringRep;
}

const QString &bacra::Route::stopId() const
{
    return mStopId;
}
