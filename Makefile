#############################################################################
# Makefile for building: Bacra
# Generated by qmake (2.01a) (Qt 4.6.3) on: Tue Aug 10 18:40:18 2010
# Project:  Bacra.pro
# Template: app
# Command: /usr/bin/qmake-qt4 -spec /usr/share/qt4/mkspecs/linux-g++ -unix CONFIG+=debug -o Makefile Bacra.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_WEBKIT_LIB -DQT_XMLPATTERNS_LIB -DQT_XML_LIB -DQT_GUI_LIB -DQT_NETWORK_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++ -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtNetwork -I/usr/include/qt4/QtGui -I/usr/include/qt4/QtXml -I/usr/include/qt4/QtXmlPatterns -I/usr/include/qt4/QtWebKit -I/usr/include/qt4 -I. -I.
LINK          = g++
LFLAGS        = 
LIBS          = $(SUBLIBS)  -L/usr/lib -lQtWebKit -lQtXmlPatterns -lQtXml -lQtGui -lQtNetwork -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/bin/qmake-qt4
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = main.cpp \
		mainwindow.cpp \
		routecontainer.cpp \
		route.cpp \
		routefactory.cpp \
		line.cpp \
		stopdelegate.cpp \
		dataextractor.cpp \
		log.cpp moc_mainwindow.cpp \
		moc_routecontainer.cpp \
		moc_route.cpp \
		moc_stopdelegate.cpp \
		moc_dataextractor.cpp \
		qrc_common.cpp
OBJECTS       = main.o \
		mainwindow.o \
		routecontainer.o \
		route.o \
		routefactory.o \
		line.o \
		stopdelegate.o \
		dataextractor.o \
		log.o \
		moc_mainwindow.o \
		moc_routecontainer.o \
		moc_route.o \
		moc_stopdelegate.o \
		moc_dataextractor.o \
		qrc_common.o
DIST          = /usr/share/qt4/mkspecs/common/g++.conf \
		/usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/debug.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		Bacra.pro
QMAKE_TARGET  = Bacra
DESTDIR       = 
TARGET        = Bacra

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET): ui_mainwindow.h $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: Bacra.pro  /usr/share/qt4/mkspecs/linux-g++/qmake.conf /usr/share/qt4/mkspecs/common/g++.conf \
		/usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/debug.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		/usr/lib/libQtWebKit.prl \
		/usr/lib/libQtXmlPatterns.prl \
		/usr/lib/libQtXml.prl \
		/usr/lib/libQtGui.prl \
		/usr/lib/libQtNetwork.prl \
		/usr/lib/libQtCore.prl
	$(QMAKE) -spec /usr/share/qt4/mkspecs/linux-g++ -unix CONFIG+=debug -o Makefile Bacra.pro
/usr/share/qt4/mkspecs/common/g++.conf:
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/debug.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/share/qt4/mkspecs/features/include_source_dir.prf:
/usr/lib/libQtWebKit.prl:
/usr/lib/libQtXmlPatterns.prl:
/usr/lib/libQtXml.prl:
/usr/lib/libQtGui.prl:
/usr/lib/libQtNetwork.prl:
/usr/lib/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -spec /usr/share/qt4/mkspecs/linux-g++ -unix CONFIG+=debug -o Makefile Bacra.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/Bacra1.0.0 || $(MKDIR) .tmp/Bacra1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/Bacra1.0.0/ && $(COPY_FILE) --parents mainwindow.h routecontainer.h route.h routefactory.h line.h stopdelegate.h dataextractor.h log.h .tmp/Bacra1.0.0/ && $(COPY_FILE) --parents common.qrc .tmp/Bacra1.0.0/ && $(COPY_FILE) --parents main.cpp mainwindow.cpp routecontainer.cpp route.cpp routefactory.cpp line.cpp stopdelegate.cpp dataextractor.cpp log.cpp .tmp/Bacra1.0.0/ && $(COPY_FILE) --parents mainwindow.ui .tmp/Bacra1.0.0/ && (cd `dirname .tmp/Bacra1.0.0` && $(TAR) Bacra1.0.0.tar Bacra1.0.0 && $(COMPRESS) Bacra1.0.0.tar) && $(MOVE) `dirname .tmp/Bacra1.0.0`/Bacra1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/Bacra1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_mainwindow.cpp moc_routecontainer.cpp moc_route.cpp moc_stopdelegate.cpp moc_dataextractor.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_mainwindow.cpp moc_routecontainer.cpp moc_route.cpp moc_stopdelegate.cpp moc_dataextractor.cpp
moc_mainwindow.cpp: routecontainer.h \
		route.h \
		line.h \
		dataextractor.h \
		stopdelegate.h \
		mainwindow.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) mainwindow.h -o moc_mainwindow.cpp

moc_routecontainer.cpp: route.h \
		line.h \
		dataextractor.h \
		routecontainer.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) routecontainer.h -o moc_routecontainer.cpp

moc_route.cpp: line.h \
		route.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) route.h -o moc_route.cpp

moc_stopdelegate.cpp: stopdelegate.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) stopdelegate.h -o moc_stopdelegate.cpp

moc_dataextractor.cpp: dataextractor.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) dataextractor.h -o moc_dataextractor.cpp

compiler_rcc_make_all: qrc_common.cpp
compiler_rcc_clean:
	-$(DEL_FILE) qrc_common.cpp
qrc_common.cpp: common.qrc \
		dataextraction/jquery-1.3.2.min.js \
		dataextraction/omatlahdot.js \
		bacra.png \
		add.png \
		remove.png
	/usr/bin/rcc -name common common.qrc -o qrc_common.cpp

compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_mainwindow.h
compiler_uic_clean:
	-$(DEL_FILE) ui_mainwindow.h
ui_mainwindow.h: mainwindow.ui
	/usr/bin/uic-qt4 mainwindow.ui -o ui_mainwindow.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_rcc_clean compiler_uic_clean 

####### Compile

main.o: main.cpp mainwindow.h \
		routecontainer.h \
		route.h \
		line.h \
		dataextractor.h \
		stopdelegate.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

mainwindow.o: mainwindow.cpp mainwindow.h \
		routecontainer.h \
		route.h \
		line.h \
		dataextractor.h \
		stopdelegate.h \
		ui_mainwindow.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o mainwindow.o mainwindow.cpp

routecontainer.o: routecontainer.cpp routecontainer.h \
		route.h \
		line.h \
		dataextractor.h \
		routefactory.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o routecontainer.o routecontainer.cpp

route.o: route.cpp route.h \
		line.h \
		log.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o route.o route.cpp

routefactory.o: routefactory.cpp routefactory.h \
		route.h \
		line.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o routefactory.o routefactory.cpp

line.o: line.cpp line.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o line.o line.cpp

stopdelegate.o: stopdelegate.cpp stopdelegate.h \
		log.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o stopdelegate.o stopdelegate.cpp

dataextractor.o: dataextractor.cpp dataextractor.h \
		log.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o dataextractor.o dataextractor.cpp

log.o: log.cpp log.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o log.o log.cpp

moc_mainwindow.o: moc_mainwindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_mainwindow.o moc_mainwindow.cpp

moc_routecontainer.o: moc_routecontainer.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_routecontainer.o moc_routecontainer.cpp

moc_route.o: moc_route.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_route.o moc_route.cpp

moc_stopdelegate.o: moc_stopdelegate.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_stopdelegate.o moc_stopdelegate.cpp

moc_dataextractor.o: moc_dataextractor.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_dataextractor.o moc_dataextractor.cpp

qrc_common.o: qrc_common.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o qrc_common.o qrc_common.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:
