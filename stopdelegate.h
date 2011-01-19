#ifndef STOPDELEGATE_H
#define STOPDELEGATE_H

#include <QItemDelegate>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QIcon>
using namespace Qt;

namespace bacra {

class StopDelegate : public QItemDelegate
{
    Q_OBJECT
public:
    StopDelegate(QObject *parent = 0);


    void setEditorData(QWidget *editor, const QModelIndex &index) const;
    void setModelData(QWidget *editor, QAbstractItemModel *model,
                       const QModelIndex &index) const;

    void updateEditorGeometry(QWidget *editor,
         const QStyleOptionViewItem &option, const QModelIndex &index) const;
    void paint( QPainter *painter,const QStyleOptionViewItem &option, const QModelIndex &index ) const;

    QSize sizeHint ( const QStyleOptionViewItem & option, const QModelIndex & index ) const;
signals:

    void sizeHintChanged (const QModelIndex &index) const;

};
}

#endif // STOPDELEGATE_H
