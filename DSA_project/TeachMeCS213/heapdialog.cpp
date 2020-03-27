#include "heapdialog.h"
#include "ui_heapdialog.h"
#include "Heap.h"
#include <QObject>

heapDialog::heapDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::heapDialog)
{
    ui->setupUi(this);
}

void heapDialog:: paintEvent(QPaintEvent*)
{
    vector<Hcoordinates> xy;
    int i =1;

    QPainter painter;
    painter.begin(this);
    painter.setPen(Qt::black);
    painter.setFont(QFont("Arial", 20));
    Hcoordinates k;
    k.x=k.y=0;
    xy.push_back(k);

    int w = 200, q = 3, t = 1 ;
    if (inserted ==1 && colourcode ==1) {
        QString std = "Maximum element: ";
        ui->maxoutput->setText(std.append(QString("%1").arg(h.array[1])));
    }
    else
        ui->maxoutput->setText("");
    while (i != h.currentSize)
    {
        update();       //erase everything and redraws

        int x1= 50,y1 = 400;
        for (int  j=0; j<h.currentSize; j++ ) {

            QRect re(x1,y1,50,50);
            painter.drawRect(re);
            painter.drawText(re, Qt :: AlignCenter,QString("%1").arg(h.array[j],0));
            x1 = x1 +50;
        }

        if (i == 1){

            QRect rect( 475,30,50,50);

            painter.drawRect (rect);
            if (colourcode == 1){
                painter.fillRect(rect,Qt::gray);
            }
            painter.drawText(rect,Qt::AlignCenter,QString("%1").arg(h.array[i]),0);
            k.x = rect.x();
            k.y = rect.y();
            xy.push_back(k);
        }
        else if (i%2 == 0){


            QRect rect2(xy[i/2].x - w + 25,xy[i/2].y + 70 ,50,50);
            painter.drawLine(xy[i/2].x-w +50  ,xy[i/2].y +25 ,xy[i/2].x ,xy[i/2].y +25);
            painter.drawLine(xy[i/2].x-w +50, xy[i/2].y +25,xy[i/2].x-w +50,xy[i/2].y +70);
            painter.drawRect (rect2);
            painter.drawText(rect2,Qt::AlignCenter,QString("%1").arg(h.array[i]),0);
            k.x = rect2.x();
            k.y = rect2.y();
            xy.push_back(k);
        }
        else {
            QRect rect3 (xy[i/2].x + w -25  ,xy[i/2].y + 70,50,50);

            painter.drawLine(xy[i/2].x+50,xy[i/2].y +25,xy[i/2].x+ w ,xy[i/2].y +25);
            painter.drawLine(xy[i/2].x+ w ,xy[i/2].y +25,xy[i/2].x+ w ,xy[i/2].y +70);
            painter.drawRect (rect3);
            painter.drawText(rect3,Qt::AlignCenter,QString("%1").arg(h.array[i]),0);
            k.x = rect3.x();
            k.y = rect3.y();
            xy.push_back(k);

        }
        if (i == q){
            w = w - 70;
            ++t;
            q = pow (2,t) + q;

        }
        i++;

    }
}

heapDialog::~heapDialog()
{
    delete ui;
}

void heapDialog::on_pushButton_clicked()
{

    h.Insert(ui->lineEdit->text().toInt()); //insert into heap on clicking this button
    inserted= 1;

}

void heapDialog::on_pushButton_2_clicked()
{
    h.DeleteMax();      //deletemax on clicking this button
}

void heapDialog::on_findmax_clicked()
{   if (colourcode == 0){
        colourcode = 1;
    }

    else                //coloring done on clicking this button
        colourcode = 0;
}

void heapDialog::on_Theory_clicked()
{
    QString std = "In computer science, a priority queue is an abstract data type which is like a regular queue or stack data structure, but where additionally each element has a 'priority' associated with it.\n";



    QString std1 =     std.append("In a priority queue, an element with high priority is served before an element with low priority.\n");
    QString std2 =     std1.append("If two elements have the same priority, they are served according to their order in the queue.\n");
    QString std3 =     std2.append("Both the left and right subtrees must also be priority queue.\n");
    QString std4 =     std3.append("There must be no duplicate nodes.");

    QMessageBox :: information(this,"PRIORITY QUEUE",std4);
}
