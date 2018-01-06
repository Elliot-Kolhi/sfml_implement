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
    main.cpp \
    mainwindow.cpp \
    mycanvas.cpp \
    qsfmlcanvas.cpp \
    agent.cpp \
    app.cpp \
    ball.cpp \
    button.cpp \
    qlearning.cpp \
    slider.cpp \
    ui.cpp \
    uielement.cpp \
    old_main.cpp

HEADERS  += \
    mainwindow.h \
    mycanvas.h \
    qsfmlcanvas.h \
    agent.hpp \
    app.hpp \
    ball.hpp \
    button.hpp \
    qlearning.hpp \
    slider.hpp \
    ui.hpp \
    uielement.hpp

FORMS    += \
    mainwindow.ui

INCLUDEPATH += D:\Downloads\SFML-2.0-sources\SFML-2.0\include\
DEPENDPATH += D:\Downloads\SFML-2.0-sources\SFML-2.0\include\

LIBS += -LD:\Downloads\SFML-2.0-sources\SFML_test\LIBS\

CONFIG(debug, debug|release): LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-main-d -lsfml-network-d -lsfml-system-d -lsfml-window-d
CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-main -lsfml-network -lsfml-system -lsfml-window

DISTFILES +=
