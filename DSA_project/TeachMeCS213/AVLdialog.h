#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "AVL.h"
#include<QPaintEvent>
#include <QRect>
#include <QtGui>
#include <QString>

namespace Ui {
    class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);   //constructor
    ~Dialog();                              //destructor
    void paintEvent(QPaintEvent*);          //paintevent function provided by Qt which paints on the dialog
    void print(AVLNode *v);                 //helper function for the paintevent function to facilitate recursive drawing for a tree structure


private slots:
    void on_pushButton_clicked();   //slot for pushbutton - Insert

    void on_Theory_clicked();       //slot for pushbutton - Theory

private:
    Ui::Dialog *ui;         //pointer to the ui of this dialog
    AVL a;                  //keeps the actual object of the data as a member to the dialog object
};

#endif // DIALOG_H
