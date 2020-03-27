#include "queuedialog.h"
#include "ui_queuedialog.h"
#include <QtCore>
#include <QtGui>

QueueDialog::QueueDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QueueDialog)
{
    colourcode = 0;
    ui->setupUi(this);      //constructor : initialise colourcode as 0 ie flag status as the general case
}

void QueueDialog::paintEvent(QPaintEvent *)
{

    QPainter painter;
    painter.begin(this);
    painter.setPen(Qt:: black);
    painter.setFont(QFont("Arial", 20));
    list<int> :: iterator it1;
    int x=50,y=350;
    painter.drawLine(50,350,200,350);
    painter.drawLine(50,450,200,450);       //initial stack container structure




    if (colourcode == 1){
        for (it1 = queue.begin(); it1 != queue.end(); it1++){
            update();
            if (it1 == queue.begin()) {
                QRect rect(x,y,50,100);
                painter.drawRect(rect);
                painter.fillRect(rect,Qt::gray);        //colour the front
                painter.drawText(rect,Qt::AlignCenter,QString("%1").arg(*it1),0);    //start filling in the queue container by drawinng rectangles with the values as text in them
                painter.drawLine(x +50,y, x+100,y);
                painter.drawLine(x+50,y+100,x+100,y+100);
                x = x +50;
            }
            else {
                QRect rect(x,y,50,100);
                painter.drawRect(rect);
                painter.drawText(rect,Qt::AlignCenter,QString("%1").arg(*it1),0);   //start filling in the queue container by drawinng rectangles with the values as text in them
                painter.drawLine(x +50,y, x+100,y);
                painter.drawLine(x +50,y, x+100,y);
                painter.drawLine(x+50,y+100,x+100,y+100);
                x = x +50;
            }
        }

    }
    else {
        for (it1 = queue.begin(); it1 != queue.end(); it1++)
        {
            update();           //erase everything and redraws

            QRect rect(x,y,50,100);
            painter.drawRect(rect);
            painter.drawText(rect,Qt::AlignCenter,QString("%1").arg(*it1),0);
            painter.drawLine(x +50,y, x+100,y);
            painter.drawLine(x+50,y+100,x+100,y+100);
            x = x +50;
        }
    }

}

QueueDialog::~QueueDialog()
{
    delete ui;
}

void QueueDialog::on_pushback_clicked()             //on clicking this button
{
    queue.push_back(ui->lineEdit->text().toInt());    //push into the queue of this class the value in lineedit

}

void QueueDialog::on_Pop_clicked()      //on clicking this button
{
    queue.pop_front();                  //pop the front element of the queue

}

void QueueDialog::on_Size_clicked()     //on clicking this button
{
    QString str = "Queue size: ";
    ui->output->setText(str.append(QString("%1").arg(queue.size())));       //display the size

}

void QueueDialog::on_Front_clicked()     //on clicking this button
{
    QString str = "Front Element: ";
    if (colourcode == 0){
        colourcode =1;

    }                   //color/decolorise front element
    else{
        colourcode = 0;
    }


}

void QueueDialog::on_Theory_clicked()
{
    QString std = "A queue is a First-In-First-Out (FIFO) data structure. In a FIFO data structure, the first element added to the queue will be the first one to be removed. This is equivalent to the requirement that once an element is added, all elements that were added before have to be removed before the new element can be invoked. A queue is an example of a linear data structure.\n";

    QString std1="Queues are common in computer programs, where they are implemented as data structures coupled with access routines, as an abstract data structure or in object-oriented languages as classes. Common implementations are circular buffers and linked lists.";
    QMessageBox :: information(this,"QUEUE",std.append(std1));

}
