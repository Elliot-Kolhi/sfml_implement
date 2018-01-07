#include "mainwindow.h"
#include "qsfmlcanvas.cpp"
#include "mycanvas.cpp"
#include <QFrame>
#include <QApplication>
#include <QtWidgets>
#include <QObject>
#include <SFML/Graphics.hpp>
#include "ui_mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication App(argc, argv);

    MainWindow* w = new MainWindow;
    w->show();

    QPushButton* pause_button = new QPushButton("Pause", w);
    pause_button->setGeometry(QRect(660, 42, 101, 23));
    pause_button->show();

    QPushButton* reset_button = new QPushButton("Reset", w);
    reset_button->setGeometry(QRect(780, 42, 101, 23));
    reset_button->show();

    QSlider* delay_slider = new QSlider(Qt::Horizontal, w);
    delay_slider->setGeometry(QRect(670, 102, 201, 19));
    delay_slider->show();


    QLabel* epoch = new QLabel("0", w);
    epoch->setGeometry(QRect(770, 128, 201, 19));
    epoch->show();

    QLabel* epsilon = new QLabel("0", w);
    epsilon->setGeometry(QRect(770, 150, 201, 19));
    epsilon->show();

    QLabel* learningRate = new QLabel("0", w);
    learningRate->setGeometry(QRect(770, 170, 201, 19));
    learningRate->show();

    QLabel* score1 = new QLabel("0", w);
    score1->setGeometry(QRect(660, 225, 201, 19));
    score1->show();

    QLabel* score2 = new QLabel("0", w);
    score2->setGeometry(QRect(810, 225, 201, 19));
    score2->show();

    MyCanvas* SFMLView2 = new MyCanvas(w , QPoint(10, 20), QSize(620, 630));
    SFMLView2->show();

    QObject::connect(pause_button,SIGNAL(clicked(bool)),SFMLView2,SLOT(is_paused()));
    QObject::connect(reset_button,SIGNAL(clicked(bool)),SFMLView2,SLOT(is_reset()));
    QObject::connect(delay_slider, SIGNAL(sliderMoved(int)),SFMLView2,SLOT(change_delay(int)));
    QObject::connect(SFMLView2,SIGNAL(setEpochText(int)),epoch,SLOT(setNum(int)));
    QObject::connect(SFMLView2,SIGNAL(setEpsilonText(double)),epsilon,SLOT(setNum(double)));
    QObject::connect(SFMLView2,SIGNAL(setLearningRateText(double)),learningRate,SLOT(setNum(double)));
    QObject::connect(SFMLView2,SIGNAL(setScore1(int)),score1,SLOT(setNum(int)));
    QObject::connect(SFMLView2,SIGNAL(setScore2(int)),score2,SLOT(setNum(int)));

    return App.exec();
}

