#-------------------------------------------------
#
# Project created by QtCreator 2018-01-03T20:43:36
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = sfml_implement
TEMPLATE = app

SOURCES += \
    src/agent.cpp \
    src/app.cpp \
    src/ball.cpp \
    src/main.cpp \
    src/mainwindow.cpp \
    src/mycanvas.cpp \
    src/qlearning.cpp \
    src/qsfmlcanvas.cpp

HEADERS  += \
    include/agent.hpp \
    include/app.hpp \
    include/ball.hpp \
    include/mainwindow.h \
    include/mycanvas.h \
    include/qlearning.hpp \
    include/qsfmlcanvas.h

FORMS    += \
    mainwindow.ui

INCLUDEPATH += D:\Downloads\SFML-2.0-sources\SFML-2.0\include\
DEPENDPATH += D:\Downloads\SFML-2.0-sources\SFML-2.0\include\

LIBS += -LD:\Downloads\SFML-2.0-sources\SFML_test\LIBS\

CONFIG(debug, debug|release): LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-main-d -lsfml-network-d -lsfml-system-d -lsfml-window-d
CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-main -lsfml-network -lsfml-system -lsfml-window

DISTFILES +=
