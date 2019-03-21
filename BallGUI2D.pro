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
<<<<<<< HEAD
    renderarea.h
=======
>>>>>>> c8d68fb3095c54fee9b9c61c3917cd002dfa2284

SOURCES += \
    ball.cpp \
    container.cpp \
    simulation.cpp \
    window.cpp \
<<<<<<< HEAD
    guimain.cpp \
    renderarea.cpp
=======
    guimain.cpp
>>>>>>> c8d68fb3095c54fee9b9c61c3917cd002dfa2284
