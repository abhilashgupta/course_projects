#ifndef BSTDIALOG_H
#define BSTDIALOG_H

#include <QDialog>
#include "BinaryTree.h"
#include<QPaintEvent>
#include <QRect>
#include <QtGui>
#include <QString>

namespace Ui {
class BSTDialog;
}

class BSTDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit BSTDialog(QWidget *parent = 0);    //constructor
    ~BSTDialog();                               //destructor
    void paintEvent(QPaintEvent*);              //paintevent function provided by Qt which paints on the dialog
    void print(TreeNode *v);                    //helper function for the paintevent function to facilitate recursive drawing for a tree structure

private slots:

    void on_pushButton_clicked();       //slot for pushbutton - Insert

    void on_pushButton_2_clicked();     //slot for pushbutton - Search

    void on_pushButton_4_clicked();     //slot for pushbutton - Refresh

    void on_pushButton_3_clicked();     //slot for pushbutton - Delete

    void on_Theory_clicked();           //slot for pushbutton - Theory

private:

    BinaryTree b;           //keeps the actual object of the data as a member to the dialog object
    Ui::BSTDialog *ui;      //pointer to the ui of this dialog
};

#endif // BSTDIALOG_H
