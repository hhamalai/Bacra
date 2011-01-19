/********************************************************************************
** Form generated from reading ui file 'mainwindow.ui'
**
** Created: Fri Oct 30 11:08:08 2009
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListView>
#include <QtGui/QMainWindow>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTabWidget>
#include <QtGui/QTableView>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_5;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *stopLineEdit;
    QSpacerItem *horizontalSpacer;
    QPushButton *addStopButton;
    QTableView *stopsView;
    QWidget *tab_2;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *fromLineEdit;
    QLineEdit *toLineEdit;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *addRouteButton;
    QTableView *routesView;
    QWidget *departuresTab;
    QWidget *layoutWidget3;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *departureLabel;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *updateButton;
    QListView *departuresView;
    QProgressBar *progressBar;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(245, 350);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 0, 251, 341));
        verticalLayout_5 = new QVBoxLayout(layoutWidget);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setMargin(11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        tabWidget = new QTabWidget(layoutWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setEnabled(true);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        layoutWidget1 = new QWidget(tab);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(0, 0, 241, 311));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setSpacing(6);
        verticalLayout->setMargin(11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(layoutWidget1);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        stopLineEdit = new QLineEdit(layoutWidget1);
        stopLineEdit->setObjectName(QString::fromUtf8("stopLineEdit"));

        horizontalLayout->addWidget(stopLineEdit);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        addStopButton = new QPushButton(layoutWidget1);
        addStopButton->setObjectName(QString::fromUtf8("addStopButton"));

        horizontalLayout->addWidget(addStopButton);


        verticalLayout->addLayout(horizontalLayout);

        stopsView = new QTableView(layoutWidget1);
        stopsView->setObjectName(QString::fromUtf8("stopsView"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(stopsView->sizePolicy().hasHeightForWidth());
        stopsView->setSizePolicy(sizePolicy);
        stopsView->setStyleSheet(QString::fromUtf8("background-image: url(:/bacra/images/bacra.png);\n"
"background-position: bottom;\n"
"background-repeat: no-repeat;"));
        stopsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        stopsView->setShowGrid(false);
        stopsView->horizontalHeader()->setStretchLastSection(true);
        stopsView->verticalHeader()->setDefaultSectionSize(30);
        stopsView->verticalHeader()->setStretchLastSection(false);

        verticalLayout->addWidget(stopsView);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        layoutWidget2 = new QWidget(tab_2);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(0, 0, 241, 311));
        verticalLayout_3 = new QVBoxLayout(layoutWidget2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setMargin(11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        fromLineEdit = new QLineEdit(layoutWidget2);
        fromLineEdit->setObjectName(QString::fromUtf8("fromLineEdit"));

        verticalLayout_2->addWidget(fromLineEdit);

        toLineEdit = new QLineEdit(layoutWidget2);
        toLineEdit->setObjectName(QString::fromUtf8("toLineEdit"));

        verticalLayout_2->addWidget(toLineEdit);


        horizontalLayout_3->addLayout(verticalLayout_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        addRouteButton = new QPushButton(layoutWidget2);
        addRouteButton->setObjectName(QString::fromUtf8("addRouteButton"));

        horizontalLayout_3->addWidget(addRouteButton);


        verticalLayout_3->addLayout(horizontalLayout_3);

        routesView = new QTableView(layoutWidget2);
        routesView->setObjectName(QString::fromUtf8("routesView"));
        routesView->setStyleSheet(QString::fromUtf8("background-image: url(:/bacra/images/bacra.png);\n"
"background-position: bottom;\n"
"background-repeat: no-repeat;"));

        verticalLayout_3->addWidget(routesView);

        tabWidget->addTab(tab_2, QString());
        departuresTab = new QWidget();
        departuresTab->setObjectName(QString::fromUtf8("departuresTab"));
        departuresTab->setEnabled(false);
        layoutWidget3 = new QWidget(departuresTab);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(0, 0, 241, 311));
        verticalLayout_4 = new QVBoxLayout(layoutWidget3);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setMargin(11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        departureLabel = new QLabel(layoutWidget3);
        departureLabel->setObjectName(QString::fromUtf8("departureLabel"));

        horizontalLayout_4->addWidget(departureLabel);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        updateButton = new QPushButton(layoutWidget3);
        updateButton->setObjectName(QString::fromUtf8("updateButton"));

        horizontalLayout_4->addWidget(updateButton);


        verticalLayout_4->addLayout(horizontalLayout_4);

        departuresView = new QListView(layoutWidget3);
        departuresView->setObjectName(QString::fromUtf8("departuresView"));
        departuresView->setStyleSheet(QString::fromUtf8("background-image: url(:/bacra/images/bacra.png);\n"
"background-position: bottom;\n"
"background-repeat: no-repeat;"));
        departuresView->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        departuresView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        verticalLayout_4->addWidget(departuresView);

        tabWidget->addTab(departuresTab, QString());

        verticalLayout_5->addWidget(tabWidget);

        progressBar = new QProgressBar(layoutWidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setEnabled(true);
        QFont font;
        font.setPointSize(1);
        progressBar->setFont(font);
        progressBar->setAutoFillBackground(false);
        progressBar->setValue(24);
        progressBar->setTextVisible(false);

        verticalLayout_5->addWidget(progressBar);

        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Stop #", 0, QApplication::UnicodeUTF8));
        stopLineEdit->setText(QString());
        addStopButton->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Stops", 0, QApplication::UnicodeUTF8));
        addRouteButton->setText(QApplication::translate("MainWindow", "+", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Routes", 0, QApplication::UnicodeUTF8));
        departureLabel->setText(QString());
        updateButton->setText(QApplication::translate("MainWindow", "Update", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(departuresTab), QApplication::translate("MainWindow", "Departures", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(MainWindow);
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
