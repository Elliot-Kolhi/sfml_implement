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

    QPushButton reset_button("Reset", w);
    reset_button.setGeometry(QRect(780, 42, 101, 23));
    reset_button.show();

    MyCanvas* SFMLView2 = new MyCanvas(w , QPoint(10, 20), QSize(620, 630));
    SFMLView2->show();

    QObject::connect(pause_button,SIGNAL(clicked(bool)),SFMLView2,SLOT(is_paused()));
    return App.exec();
}

