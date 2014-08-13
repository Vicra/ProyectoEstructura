#-------------------------------------------------
#
# Project created by QtCreator 2014-08-10T10:53:34
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Proyecto
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    lista.cpp \
    nodo.cpp

HEADERS  += mainwindow.h \
    lista.h \
    nodo.h

FORMS    += mainwindow.ui

RESOURCES += \
    MyResources.qrc
