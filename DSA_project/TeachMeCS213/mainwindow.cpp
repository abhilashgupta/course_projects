#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    creditclick = 0;
}

void MainWindow :: paintEvent(QPaintEvent *){
    QPainter painter;
    painter.begin(this);        //calling the begin function of the Qpainter object painter with the current object ie the mainwindow as the argument
    update();

    painter.setFont(QFont("Purisa", 50));

    painter.drawText(200,150,"TEACH ME");       //Painting TEACH ME CS 213 in big fonts on the main window paintevent
    painter.drawText(200,250,"CS 213");
    if (creditclick == 1) {
        painter.setFont(QFont("Purisa",20));
        painter.drawText(200, 500,"Abhilash Gupta, 110050058");
        painter.drawText(200, 550,"Sudipto Biswas, 110050048");
    }
}

MainWindow::~MainWindow()
{
    delete ui;          //destructor : delete the pointer to the ui of mainwindow
}

void MainWindow::on_pushButton_6_clicked()      //On pushing this button :
{
    AVL = new Dialog(this);                     //Create a new AVL Dialog
    AVL->show();
    AVL->raise();
    AVL->activateWindow();                      //activate the AVL Dialog
}

void MainWindow::on_pushButton_clicked()        //On pushing this button :
{
    S = new StackDialog(this);                  //Create a new Stack Dialog
    S->show();
    S->raise();
    S->activateWindow();                        //activate the Stack Dialog
}

void MainWindow::on_pushButton_4_clicked()      //On pushing this button :
{
    BST = new BSTDialog(this);                  //Create a new BST Dialog
    BST->show();
    BST->raise();
    BST->activateWindow();                      //activate the BST Dialog
}

void MainWindow::on_pushButton_2_clicked()      //On pushing this button :
{
    Q = new QueueDialog(this);                  //Create a new Queue Dialog
    Q->show();
    Q->raise();
    Q->activateWindow();                        //activate the Queue Dialog
}

void MainWindow::on_pushButton_3_clicked()      //On pushing this button :
{
    L = new ListDialog(this);                   //Create a new List Dialog
    L->show();
    L->raise();
    L->activateWindow();                        //activate the List Dialog
}

void MainWindow::on_pushButton_5_clicked()      //On pushing this button :
{
    H = new heapDialog(this);                   //Create a new Heap Dialog
    H->show();
    H->raise();
    H->activateWindow();                        //activate the Heap Dialog
}

void MainWindow::on_Credit_clicked()            //On pushing this button :
{
    if (creditclick == 1){
        creditclick =0;                         //print the credits if already not printed
    }                                           //if already printed, remove
    else creditclick =1;
}

void MainWindow::on_pushButton_7_clicked()      //On pushing this button :
{
    Sort = new SortDialog(this);                //Create a new Sort Dialog
    Sort->show();
    Sort->raise();
    Sort->activateWindow();                     //activate the Sort Dialog
}
