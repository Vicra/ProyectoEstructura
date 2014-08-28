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
    filebase.cpp \
    carpeta.cpp \
    lista.cpp \
    archivo.cpp \
    narchivo.cpp

HEADERS  += mainwindow.h \
    filebase.h \
    carpeta.h \
    lista.h \
    archivo.h \
    narchivo.h

FORMS    += mainwindow.ui \
    narchivo.ui

RESOURCES += \
    MyResources.qrc
