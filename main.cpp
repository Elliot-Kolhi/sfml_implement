#include "mainwindow.h"
#include "qsfmlcanvas.cpp"
#include "mycanvas.cpp"
#include <QFrame>
#include <QApplication>
#include <SFML/Graphics.hpp>


int main(int argc, char *argv[])
{
    QApplication App(argc, argv);

    MainWindow w;
    w.show();

    // Create the main frame
    QFrame* MainFrame = new QFrame;
    MainFrame->setWindowTitle("Qt SFML");
    MainFrame->resize(900, 700);
    MainFrame->show();

    // Create a SFML view inside the main frame
    MyCanvas* SFMLView = new MyCanvas(MainFrame, QPoint(20, 20), QSize(620, 400));
    SFMLView->show();

    //MyCanvas* SFMLView2 = new MyCanvas(MainFrame, QPoint(20, 500), QSize(100, 100));
    //SFMLView2->show();

    //MyCanvas* SFMLView3 = new MyCanvas(MainFrame, QPoint(120, 500), QSize(100, 100));
    //SFMLView3->show();

    //w.setCentralWidget(SFMLView);
    return App.exec();
}

