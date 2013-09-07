#-------------------------------------------------
#
# Project created by QtCreator 2013-08-31T10:42:43
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PlotWidgetTest
TEMPLATE = app


SOURCES += main.cpp \
    ../../Plot/Plotwidget.cpp \
    mainwindow.cpp \
    ../../Plot/Data.cpp

HEADERS  += \
    ../../Plot/PlotWidget.h \
    mainwindow.h \
    ../../Plot/Data.h
include ("/home/rasmadeus/Programs/Qt/qwt-6.1.0/features/qwt.prf")

FORMS += \
    mainwindow.ui
