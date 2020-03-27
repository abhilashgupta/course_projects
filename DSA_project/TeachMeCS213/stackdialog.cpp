#include "stackdialog.h"
#include "ui_stackdialog.h"
#include<QtCore>
#include<QtGui>

StackDialog::StackDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StackDialog)
{
    ui->setupUi(this);
    colourcode =0;          //constructor : initialise colourcode and inserted as 0 ie flag status as the general case
    inserted= 0;
}

StackDialog::~StackDialog()
{
    delete ui;
}

void StackDialog::paintEvent(QPaintEvent *)
{
    //list<int> stack;

    QPainter painter;

    painter.begin(this);
    painter.setPen(Qt:: black);
    painter.setFont(QFont("Arial", 20));
    list<int> :: iterator it1;
    list<int> :: iterator it2;
    for (it2 = stack.begin(); it2 != stack.end(); it2++);
    it2--;
    int x=300,y=400;        //starting coordinates
    painter.drawLine(300,450,400,450);
    painter.drawLine(300,450,300,200);      //initial stack container structure
    painter.drawLine(400,450,400,200);




    if (colourcode == 0){
        for (it1 = stack.begin(); it1 != stack.end(); it1++){
            update();           //erase everything and redraws
            QRect rect(x,y,100,50);
            painter.drawRect(rect);
            painter.drawText(rect,Qt::AlignCenter,QString("%1").arg(*it1),0);  //start filling in the stack container by drawinng rectangles with the values as text in them
            painter.drawLine(x,y,x,y-50);
            painter.drawLine(x+100,y,x+100,y-50);
            y = y -50;

        }
    }
    else{
        for (it1 = stack.begin(); it1 != stack.end(); it1++){
            update();           //erase everything and redraws
            if ( it1 == it2) {
                QRect rect(x,y,100,50);
                painter.drawRect(rect);
                painter.fillRect(rect,Qt:: gray);
                painter.drawText(rect,Qt::AlignCenter,QString("%1").arg(*it1),0);
                painter.drawLine(x,y,x,y-50);
                painter.drawLine(x+100,y,x+100,y-50);
                y = y -50;
            }
            else {
                QRect rect(x,y,100,50);
                painter.drawRect(rect);
                painter.drawText(rect,Qt::AlignCenter,QString("%1").arg(*it1),0);
                painter.drawLine(x,y,x,y-50);
                painter.drawLine(x+100,y,x+100,y-50);
                y = y -50;
            }
        }
    }

}


void StackDialog::on_Push_clicked()         //on pushing this button :
{
    stack.push_back(ui->lineEdit->text().toInt());      //lineEdit value inserted in the stack list
    inserted = 1;

}

void StackDialog::on_pop_clicked()
{
    stack.pop_back();

}

void StackDialog::on_sizecall_clicked()
{   QString str = "Stack size: ";
    ui->size->setText(str.append(QString("%1").arg(stack.size())));
}

void StackDialog::on_top_clicked()
{   if (colourcode == 0){
    colourcode = 1;

    }
    else {
        colourcode = 0;

    }
}

void StackDialog::on_Theory_clicked()
{
    QString std = "A stack is a Last-In-First-Out (FIFO) data structure. In a LIFO data structure, the last element added to the stack will be the first one to be removed. This is equivalent to the requirement that once an element is added, that element has to be removed before the previous elements can be invoked. ";

    QString std1="Stacks are common in computer programs, where they are implemented as data structures coupled with access routines, as an abstract data structure or in object-oriented languages as classes. Common implementations are circular buffers and linked lists.";
    QMessageBox :: information(this,"STACK",std.append(std1));
}
