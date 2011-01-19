#include "stopdelegate.h"
#include <iostream>
#include <QtGui>

#include "log.h"

bacra::StopDelegate::StopDelegate(QObject *parent)
        : QItemDelegate(parent)
{
}

/*
QWidget *bacra::StopDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                       const QModelIndex &index) const
{
    if (index.row() == 0) {
        if (index.column() == 0) {
            std::cout << "StopDelegate::createEditor" << std::endl;
            bacra::Log::debug("StopDelegate::createEditor");
            QLineEdit *editor = new QLineEdit(parent);
            editor->setObjectName(QString("delegateEditor"));
            return editor;
        } else if (index.column() == 1) {
            QPushButton *okButton = new QPushButton("+", parent);
            return okButton;
        }
    }
}
*/

void bacra::StopDelegate::setEditorData(QWidget *, const QModelIndex &) const
{

}

void bacra::StopDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,
                   const QModelIndex &index) const
{
    if (index.column() == 0) {
        QLineEdit *lineEdit = static_cast<QLineEdit*>(editor);
        model->setData(index, lineEdit->text(), Qt::EditRole);
    }
}

void bacra::StopDelegate::updateEditorGeometry(QWidget *editor,
     const QStyleOptionViewItem &option, const QModelIndex &index) const
{
   // editor->setGeometry(option.rect);
    QRect r(option.rect);
    r.setHeight(option.rect.height());
    editor->setGeometry(r);
    QModelIndex changedIndex(index);
    emit sizeHintChanged (index);
}

void bacra::StopDelegate::paint( QPainter *painter,const QStyleOptionViewItem &option, const QModelIndex &index ) const
{
    if (index.column() == 0) {
         QItemDelegate::paint(painter, option, index);
    }
    if (index.column() == 1)
    {
         QStyleOptionButton button;
         button.rect = option.rect;
         button.rect.setWidth(button.rect.width() -10);
//         button.text = QString::fromUtf8("-");
         button.icon = QIcon(":/bacra/images/remove.png");
         button.state=QStyle::State_Raised | QStyle::State_Enabled;
         QApplication::style()->drawControl(QStyle::CE_PushButton,&button, painter);
    }
}
QSize bacra::StopDelegate::sizeHint ( const QStyleOptionViewItem &, const QModelIndex & ) const
{
    QSize size(200, 40);
    return size;
}
