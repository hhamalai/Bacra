#ifndef LINE_H
#define LINE_H
#include <QVariant>
#include <QString>

namespace bacra {

class Line
{

public:
    Line();
    Line(QString const&);
    Line(QString const&, QString const&);
    Line(QString const &lineName, QString const &lineTime, QString const &lineEnd);
    virtual ~Line();
    QString const &time() const;
    QString const &lineName() const;
    QString const &lineEnd() const;
    QString const &asString() const;
private:
    QString mTime_;
    QString mLineName_;
    QString mLineEnd_;
    QString asString_;
};

}

#endif // LINE_H
