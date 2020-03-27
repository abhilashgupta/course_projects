#ifndef DELTA_H
#define DELTA_H

#include <QDialog>
#include <QtCore>
#include <QtGui>

namespace Ui {
    class delta;
}

class delta : public QDialog
{
    Q_OBJECT

public:
    explicit delta(QWidget *parent = 0);
    ~delta();
    void paintEvent(QPaintEvent *);

private:
    Ui::delta *ui;
};

#endif // DELTA_H
