#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <cassert>
#include <iostream>
#include <QtGui>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{

    // NOTE: these dataextractors are deleted by
    // routecontainer class instance.
    dataExtractor = new bacra::DataExtractor();
    dataExtractor->initialize();
    dataExtractor2 = new bacra::DataExtractor();
    dataExtractor2->initialize();


    routeContainer = new bacra::RouteContainer(dataExtractor, this);
    stopContainer = new bacra::RouteContainer(dataExtractor2, this);
    stopDelegate = new bacra::StopDelegate(this);
    routeDelegate = new bacra::StopDelegate(this);



    ui->setupUi(this);



    QRegExp rx("\\d{0,6}");
    QValidator *validator = new QRegExpValidator(rx, this);
    ui->stopLineEdit->setValidator(validator);

    ui->routesView->setModel(routeContainer);
    ui->routesView->setItemDelegate(new bacra::StopDelegate());

    ui->stopsView->setModel(stopContainer);
    ui->stopsView->setItemDelegate(new bacra::StopDelegate());

    ui->tab_2->setDisabled(true);

    ui->progressBar->setVisible(false);

    //ui->stopsView->setStyleSheet("QTableView {background: url(:/bacra/images/bacra.png); background-attachment: fixed; background-position: bottom-center;}");
    //ui->departuresView->setStyleSheet("QTableView {background: url(:/bacra/images/bacra.png); background-attachment: fixed; background-position: bottom-center;}");
    //ui->routesView->setStyleSheet("QTableView {background: url(:/bacra/images/bacra.png); background-attachment: fixed; background-position: bottom-center;}");
    ui->addStopButton->setIcon(QIcon(":/bacra/images/add.png"));

    ui->stopsView->setDragEnabled(true);
    ui->stopsView->setAcceptDrops(true);

    connect(stopContainer, SIGNAL(updatedDepartures()), ui->departuresView, SLOT(setFocus()));

    connect(dataExtractor, SIGNAL(infoResponseReady(int)), ui->progressBar, SLOT(setValue(int)));
    connect(dataExtractor2, SIGNAL(infoResponseReady(int)), ui->progressBar, SLOT(setValue(int)));

    connect(ui->tabWidget, SIGNAL(currentChanged(int)), this, SLOT(commercialAnnouncement(int)));

    connect(ui->fromLineEdit, SIGNAL(returnPressed()), ui->toLineEdit, SLOT(setFocus()));
    connect(ui->toLineEdit, SIGNAL(returnPressed()), ui->addRouteButton, SLOT(click()));
    connect(ui->addRouteButton, SIGNAL(clicked()), this, SLOT(addRouteClicked()));
    connect(this, SIGNAL(addRoute(QString, QString)), routeContainer, SLOT(addRouteItem(QString, QString)));

    connect(ui->stopLineEdit, SIGNAL(returnPressed()), ui->addStopButton, SLOT(click()));
    connect(ui->addStopButton, SIGNAL(clicked()), this, SLOT(addStopClicked()));
    connect(this, SIGNAL(addStop(QString)), stopContainer, SLOT(addStopItem(QString)));
    connect(ui->stopsView, SIGNAL(clicked(QModelIndex)), stopContainer, SLOT(indexSelected(QModelIndex)));
    connect(ui->routesView, SIGNAL(clicked(QModelIndex)), routeContainer, SLOT(indexSelected(QModelIndex)));

    connect(ui->updateButton, SIGNAL(clicked()), this, SLOT(updateDepartures()));
    
    connect(stopContainer, SIGNAL(dataChanged(QModelIndex,QModelIndex)), ui->stopsView, SLOT(dataChanged(QModelIndex,QModelIndex)));

    connect(routeContainer, SIGNAL(routeAdded()), this, SLOT(routeAdded()));
    connect(stopContainer, SIGNAL(stopAdded()), this, SLOT(stopAdded()));

    connect(stopContainer, SIGNAL(showDepartures(bacra::Route*)), this, SLOT(showDepartures(bacra::Route*)));

    connect(stopContainer, SIGNAL(invalidStop()), this, SLOT(invalidStop()));
    connect(routeContainer, SIGNAL(invalidRoute()), this, SLOT(invalidRoute()));

     //Loading routes from disk
     //setting ui so loaded stops display themselves
    //correctly
//    ui->stopsView->setColumnWidth(0, 170);
 //   ui->stopsView->setColumnWidth(1, 40);
    ui->stopsView->setColumnWidth(0, 180);
    ui->stopsView->setColumnWidth(1, 30);
    stopContainer->loadRoutes("./savedata.txt");
}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::addStopClicked()
{
    ui->stopsView->setColumnWidth(0, 190);
    ui->stopsView->setColumnWidth(1, 30);
    ui->progressBar->setVisible(true);
    ui->progressBar->setValue(25);
    emit addStop(ui->stopLineEdit->text());
}

void MainWindow::addRouteClicked()
{
    ui->routesView->setColumnWidth(0, 170);
    ui->routesView->setColumnWidth(1, 40);
   // std::cout << "points:" << qPrintable(ui->fromLineEdit->text()) << " " << qPrintable(ui->toLineEdit->text())<< std::endl;
    emit addRoute(ui->fromLineEdit->text(), ui->toLineEdit->text());
}

void MainWindow::invalidStop()
{
    ui->stopLineEdit->setStyleSheet("QLineEdit {border: 2px solid red;}");
    ui->progressBar->setVisible(false);
}

void MainWindow::invalidRoute()
{
    ui->fromLineEdit->setStyleSheet("QLineEdit {border: 2px solid red;}");
    ui->toLineEdit->setStyleSheet("QLineEdit {border: 2px solid red;}");
    ui->progressBar->setVisible(false);
}

void MainWindow::stopAdded()
{
    ui->stopLineEdit->setStyleSheet("");
    ui->stopLineEdit->clear();
    ui->progressBar->setVisible(false);
}

void MainWindow::routeAdded()
{
    ui->fromLineEdit->setStyleSheet("");
    ui->toLineEdit->setStyleSheet("");
    ui->fromLineEdit->clear();
    ui->toLineEdit->clear();
    ui->progressBar->setVisible(false);
}

void MainWindow::showDepartures(bacra::Route *route)
{
    //std::cout << "Show routes on: " << qPrintable(*route->name()) << std::endl;
    ui->departuresTab->setEnabled(true);
    ui->departureLabel->setText(route->name());
    ui->departuresView->setModel(route);
    ui->tabWidget->setCurrentIndex(2);
}

 void MainWindow::closeEvent(QCloseEvent *event)
 {
    stopContainer->saveRoutes("./savedata.txt");
    event->accept();
 }


void MainWindow::updateDepartures()
{
    qDebug() << "updateDepartures()" << ((bacra::Route*)ui->departuresView->model())->stopId();
    stopContainer->addStopItem(((bacra::Route*)ui->departuresView->model())->stopId());
    ui->progressBar->setVisible(true);
    ui->progressBar->setValue(25);
}

void MainWindow::commercialAnnouncement(int i)
{
    if (i == 1) {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Help to develop BaCRA");
        msgBox.setText("This feature can be unlocked with professional version of BaCRA.<br />Contact your friendly BaCRA developers: <blockquote>hhamalai@iki.fi<br />kajkarhu@gmail.com</blockquote>Bacra - Better and Cooler Route Application");
        msgBox.exec();
    }
}
