#include <QtGui/QApplication>
#include "delta.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    delta w;
    w.show();

    return a.exec();
}
