#include <QtGui/QApplication>
#include "mainwindow.h"
#include "dataextractor.h"

#include "route.h"
#include "line.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Q_INIT_RESOURCE(common);
    MainWindow w;
    w.setWindowTitle("BaCRA");
    w.show();
    return a.exec();
}
