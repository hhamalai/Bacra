#include "line.h"
#include <QStringList>
#include <QDebug>

bacra::Line::Line()
{}

bacra::Line::Line(QString const &lineName)
{
    //qDebug() << "bacra::Line::lineName: " <<lineName;
  QStringList splitted = lineName.split(',');
  if(splitted.size() == 3){
    mTime_ = splitted.at(0);
    mLineName_ = splitted.at(1);
    mLineEnd_ = splitted.at(2);
    asString_ = lineName;
    asString_.append("#");
  }
  else{
    //something has gone wrong
      qDebug() << "Argh, I failed to create new Line sire! You should be punished for providing me invalid data";
      qDebug() << "Received: " << lineName;
  }
}

bacra::Line::Line(QString const &lineName, QString const &time)
{
    mLineName_ = lineName;
    mTime_ = time;
}

bacra::Line::Line(QString const &lineName, QString const &lineTime, QString const &lineEnd){
    mLineName_ = lineName;
    mLineEnd_ = lineEnd;
    mTime_ = lineTime;
}

bacra::Line::~Line()
{

}

const QString &bacra::Line::time() const
{
    return mTime_;
}

const QString &bacra::Line::lineName() const
{
    return mLineName_;
}

const QString &bacra::Line::lineEnd() const
{
    return mLineEnd_;
}

const QString &bacra::Line::asString() const{
    return asString_;
}
