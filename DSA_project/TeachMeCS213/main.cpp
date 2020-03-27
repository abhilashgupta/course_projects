#include <QtGui/QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;       //make a mainwindow object
    w.resize(600,600);
    w.show();

    return a.exec();    //starts execution
}
