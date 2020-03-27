#ifndef STACKDIALOG_H
#define STACKDIALOG_H

#include<list>
#include<iostream>
#include<iterator>
#include<QPainter>

using namespace std;

#include <QDialog>

namespace Ui {
class StackDialog;
}

class StackDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit StackDialog(QWidget *parent = 0);  //constructor
    ~StackDialog();                             //destructor
    void paintEvent(QPaintEvent *);             //paintevent function provided by Qt which paints on the dialog

private slots:

    void on_Push_clicked();     //slot for pushbutton - Push

    void on_pop_clicked();      //slot for pushbutton - Pop

    void on_sizecall_clicked();     //slot for pushbutton - Size

    void on_top_clicked();      //slot for pushbutton - Top

    void on_Theory_clicked();   //slot for pushbutton - Theory
    
private:
    Ui::StackDialog *ui;    //pointer to the ui of this dialog
    list<int> stack;        //keeps the actual object of the data as a member to the dialog object
    int colourcode;         //data member to facilitate coloring of top element ie flag element
    int inserted;           //another data member working as a flag element
};

#endif // STACKDIALOG_H
