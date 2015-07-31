#-------------------------------------------------
#
# Project created by QtCreator 2014-11-08T13:35:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FileOblivion
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    filedeleter.cpp \
    about.cpp \
    filedialog.cpp \
    catalogdialog.cpp

HEADERS  += mainwindow.h \
    filedeleter.h \
    about.h \
    filedialog.h \
    catalogdialog.h

FORMS    += mainwindow.ui \
    about.ui \
    filedialog.ui \
    catalogdialog.ui

RESOURCES += \
    resource.qrc
