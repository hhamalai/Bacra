# -------------------------------------------------
# Project created by QtCreator 2009-10-26T14:05:33
# -------------------------------------------------
QT += network \
    xml \
    xmlpatterns \
    webkit \
    network
TARGET = Bacra
TEMPLATE = app
SOURCES += main.cpp \
    mainwindow.cpp \
    routecontainer.cpp \
    route.cpp \
    routefactory.cpp \
    line.cpp \
    stopdelegate.cpp \
    dataextractor.cpp \
    log.cpp
HEADERS += mainwindow.h \
    routecontainer.h \
    route.h \
    routefactory.h \
    line.h \
    stopdelegate.h \
    dataextractor.h \
    log.h
FORMS += mainwindow.ui
RESOURCES += common.qrc
OTHER_FILES += Trash.txt
