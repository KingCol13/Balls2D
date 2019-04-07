TEMPLATE = app
TARGET = BallGUI2D

QT = core gui

CONFIG+= c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

HEADERS += \
    ball.h \
    container.h \
    simulation.h \
    window.h \
    renderarea.h \
    worker.h

SOURCES += \
    ball.cpp \
    container.cpp \
    simulation.cpp \
    window.cpp \
    guimain.cpp \
    renderarea.cpp \
    worker.cpp
