QT       += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Kitchen-Simulator
TEMPLATE = app


SOURCES += main.cpp\
        kitchen.cpp \
    graphicsscene.cpp

HEADERS  += kitchen.h \
    graphicsscene.h \
    table.h

FORMS    += kitchen.ui
