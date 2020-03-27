#ifndef SORTDIALOG_H
#define SORTDIALOG_H

#include <QDialog>
#include<QtCore>
#include <QtGui>
#include<vector>
#include<iostream>
using namespace std;

namespace Ui {
class SortDialog;
}

struct S
{
    int e;
    char col;       //Struct of int and char to store the ints to be sorted and the coloor code so as to show the coloring
};

class SortDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit SortDialog(QWidget *parent = 0);       //constructor
    ~SortDialog();                                  //destructor
    void paintEvent(QPaintEvent *);                 //paintevent function provided by Qt which paints on the dialog
    void Insort_step();
    void Selsort_step();
    void painthelp(vector<S> v);
private slots:
    void on_Input_clicked();        //slot for pushbutton - Input

    void on_Next_clicked();         //slot for pushbutton - Insort_Next_Step

    void on_pushButton_clicked();   //slot for pushbutton - Clear/Refresh

    void on_pushButton_2_clicked(); //slot for pushbutton - Selsort_Next_Step

    void on_InSortTheory_clicked(); //slot for pushbutton - Insort Theory

    void on_SelSortTheory_clicked();    //slot for pushbutton - Selsort Theory

private:
    Ui::SortDialog *ui;     //pointer to the ui of this dialog
    vector<S> v;            //keeps the actual object of the data as a member to the dialog object
    int i;                  //keeps the value of i for every execution of any sort step ie i of the outer loop in da sort algo
};

#endif // SORTDIALOG_H
