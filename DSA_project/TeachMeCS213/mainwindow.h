#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <AVLdialog.h>
#include <bstdialog.h>
#include <stackdialog.h>
#include <queuedialog.h>
#include <listdialog.h>
#include <heapdialog.h>
#include <sortdialog.h>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);   //constructor
    ~MainWindow();                              //destructor
    void paintEvent(QPaintEvent *);             //paintevent function provided by Qt which paints on the dialog
    int creditclick;
private slots:

    void on_pushButton_6_clicked();     //slot for pushbutton - AVL

    void on_pushButton_clicked();       //slot for pushbutton - Stack (activate Stack Dialog)

    void on_pushButton_4_clicked();     //slot for pushbutton - BST

    void on_pushButton_2_clicked();     //slot for pushbutton - Queue

    void on_pushButton_3_clicked();     //slot for pushbutton - List

    void on_pushButton_5_clicked();     //slot for pushbutton - Heap

    void on_Credit_clicked();           //slot for pushbutton - Credits

    void on_pushButton_7_clicked();     //slot for pushbutton - Sorting

private:
    Ui::MainWindow *ui;     //pointer to the ui of the mainwindow
    Dialog *AVL;            //pointer to the ui of the AVL dialog
    BSTDialog *BST;         //pointer to the ui of the BST dialog
    StackDialog *S;         //pointer to the ui of the Stack dialog
    QueueDialog *Q;         //pointer to the ui of the Queue dialog
    ListDialog *L;          //pointer to the ui of the List dialog
    heapDialog *H;          //pointer to the ui of the Heap dialog
    SortDialog *Sort;       //pointer to the ui of the Sort dialog
};

#endif // MAINWINDOW_H
