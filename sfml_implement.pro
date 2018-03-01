#-------------------------------------------------
#
# Project created by QtCreator 2018-01-03T20:43:36
#
#-------------------------------------------------

QT       += core gui
QT += widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = sfml_implement
TEMPLATE = app

INCLUDEPATH += "$$PWD/include"
INCLUDEPATH += "$$PWD/src"
INCLUDEPATH += "$$PWD"

SOURCES += \
    src/agent.cpp \
    src/ball.cpp \
    src/main.cpp \
    src/mainwindow.cpp \
    src/mycanvas.cpp \
    src/qlearning.cpp \
    src/qsfmlcanvas.cpp

HEADERS  += \
    include/agent.hpp \
    include/ball.hpp \
    include/mainwindow.h \
    include/mycanvas.h \
    include/qlearning.hpp \
    include/qsfmlcanvas.h

FORMS    += \
    mainwindow.ui

LIBS += -L$$PWD/SFML/lib

CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-main -lsfml-network -lsfml-window -lsfml-system
CONFIG(debug, debug|release): LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-main-d -lsfml-network-d -lsfml-window-d -lsfml-system-d

INCLUDEPATH += $$PWD/SFML/include
DEPENDPATH += $$PWD/SFML/include
