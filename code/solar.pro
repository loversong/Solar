#-------------------------------------------------
#
# Project created by QtCreator 2016-05-18T17:37:31
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

LIBS += -lGLU

TARGET = solar
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mywidget.cpp \
    planet.cpp \
    material.cpp \
    light.cpp

HEADERS  += mainwindow.h \
    data.h \
    mywidget.h \
    planet.h \
    material.h \
    light.h

FORMS    += mainwindow.ui

