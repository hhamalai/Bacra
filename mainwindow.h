#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include "routecontainer.h"
#include "stopdelegate.h"
#include "route.h"
#include "dataextractor.h"
namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void showDepartures(bacra::Route *route);
private slots:
    void addStopClicked();
    void addRouteClicked();
    void invalidStop();
    void invalidRoute();
    void stopAdded();
    void routeAdded();
    void updateDepartures();
    void commercialAnnouncement(int);

signals:
    void addStop(QString);
    void addRoute(QString, QString);
private:
    Ui::MainWindow *ui;
    bacra::RouteContainer *routeContainer;
    bacra::RouteContainer *stopContainer;
    bacra::DataExtractor *dataExtractor;
    bacra::DataExtractor *dataExtractor2;
    bacra::StopDelegate *stopDelegate;
    bacra::StopDelegate *routeDelegate;

 protected:
    void closeEvent(QCloseEvent*);

};

#endif // MAINWINDOW_H
