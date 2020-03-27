#ifndef HEAPDIALOG_H
#define HEAPDIALOG_H

#include <QDialog>
#include <QRect>
#include <QtGui>
#include <QString>
#include <vector>
#include <math.h>
#include "Heap.h"
#include<QPaintEvent>

namespace Ui {
class heapDialog;
}

struct Hcoordinates{
    int x;
    int y;
};

class heapDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit heapDialog(QWidget *parent = 0);   //constructor
    ~heapDialog();                              //destructor
    void paintEvent(QPaintEvent*);              //paintevent function provided by Qt which paints on the dialog

private slots:
    void on_pushButton_clicked();       //slot for pushbutton - Insert

    void on_pushButton_2_clicked();     //slot for pushbutton - DeleteMax

    void on_findmax_clicked();          //slot for pushbutton - FindMax
    
    void on_Theory_clicked();           //slot for pushbutton - Theory

private:
    Ui::heapDialog *ui;     //pointer to the ui of this dialog
    Heap<int> h;            //keeps the actual object of the data as a member to the dialog object
    int colourcode;
    int inserted;
};

#endif // HEAPDIALOG_H
