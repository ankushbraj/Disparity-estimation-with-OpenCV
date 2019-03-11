QT += core
QT -= gui

TARGET = test
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

INCLUDEPATH += /usr/local/include/opencv
LIBS += -L/usr/local/lib -lopencv_core -lopencv_imgcodecs -lopencv_highgui
LIBS += `pkg-config opencv --libs`


SOURCES += main.cpp






