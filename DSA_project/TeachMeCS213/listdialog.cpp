#include "listdialog.h"
#include "ui_listdialog.h"
#include <QObject>
#include <iostream>

ListDialog::ListDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ListDialog)
{
    count=0;
    numOne.clear();
    ui->setupUi(this);  //constructor : initialise count(size) as 0 and clear the list
}


void ListDialog:: paintEvent(QPaintEvent*)
{

    list<int> ::iterator it=numOne.begin();

    int i=0;
    QPainter painter;
    painter.begin(this);
    painter.setPen(Qt::black);
    painter.setFont(QFont("Arial", 20));


    coordinates d_k,p_k;
    d_k.x=d_k.y=0;
    p_k.x=p_k.y=0;

    while(it!=numOne.end()){
        update();                       //erase everything and redraws
        QRect data_rect((100+50*i),100,50,50) ;
        QBrush brush;
        brush.setColor(Qt::black);
        brush.setStyle(Qt::SolidPattern);

        painter.drawRect (data_rect);
        painter.drawText(data_rect,Qt::AlignCenter,QString("%1").arg(*it),0);
        painter.drawLine(100 +50*(i+1),125,100+50*(i+2),125);
        QPolygon triangle;
        triangle <<  QPoint (100 + 50*(i+2),125);
        triangle <<  QPoint (100 + 50*(i+2)-10,115);
        triangle <<  QPoint (100 + 50*(i+2)- 10,135);
        painter.drawPolygon(triangle);
        QPainterPath path;
        path.addPolygon(triangle);          //adding triangle infront of a line to make an arrow
        painter.fillPath(path,brush);
        it++;
        i = i+2;
        d_k.x = data_rect.x();
        d_k.y = data_rect.y();


    }


    QRect ptr_rect(100 + 50*i,100,50,50);
    painter.drawRect (ptr_rect);
    painter.drawText(ptr_rect,Qt::AlignCenter,tr("null"),0);       //Creating the hypothetical NULL Node
    p_k.x = ptr_rect.x();
    p_k.y = ptr_rect.y();


}
ListDialog::~ListDialog()
{
    delete ui;
}

void ListDialog::on_pushButton_clicked()        //on clicking this button
{
    numOne.push_back(ui->lineEdit->text().toInt());     //push after into the list the value in lineedit
    count++;            //increase the size variable by 1
    cout<<count;
}



void ListDialog::on_pushButton_2_clicked()      //on clicking this button
{
    numOne.push_front(ui->lineEdit->text().toInt());   //push before into the list the value in lineedit
    count++;        //increase the size variable by 1
    cout<<count;
}

void ListDialog::on_pushButton_3_clicked()      //on clicking this button
{
    numOne.pop_back();
    count--;        //pop the last element
    cout<<count;
}

void ListDialog::on_pushButton_4_clicked()
{
    numOne.pop_front();
    count--;        //pop the first element
    cout<<count;
}

void ListDialog::on_pushButton_5_clicked()
{
    list<int>::iterator it=numOne.begin();
    for(int i=0;((i<ui->lineEdit_2->text().toInt())&&(it!=numOne.end()));i++)   // insert after k(from lineedit2)
        it++;
    numOne.insert(it,ui->lineEdit->text().toInt());
}

void ListDialog::on_Theory_clicked()
{
    QString std = "In computer science, a list or sequence is an abstract data type that implements an ordered collection of values, where the same value may occur more than once. Each instance of a value in the list is usually called an item, entry, or element of the list; if the same value occurs multiple times, each occurrence is considered a distinct item.";

    QMessageBox :: information(this,"LIST",std);
}
