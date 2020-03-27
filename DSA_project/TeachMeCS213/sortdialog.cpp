#include "sortdialog.h"
#include "ui_sortdialog.h"
#include<iostream>

using namespace std;

SortDialog::SortDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SortDialog)
{
    ui->setupUi(this);
    i=0;
}

SortDialog::~SortDialog()
{
    delete ui;
}

void SortDialog::paintEvent(QPaintEvent *)
{   update();       //erase everything and redraws

    painthelp(v);


}
void SortDialog:: Insort_step()
{
    int j;
    if (i < v.size())
    {
        int temp =  v[i].e;
        cout<<"#"<<temp<<"#";
        for (j=i;j> 0 && temp <v[j-1].e;j--)
        {
            v[j].e = v[j-1].e;
            v[j].col=v[j-1].col='r';            //inner loop of standard insort algo
        }
        v[j].e= temp;
        cout<<j<<"->"<<v[j].e<<";";

    }
}



void SortDialog::on_Input_clicked()
{
    S s;
    s.e=ui->lineedit->text().toInt();   //input the elements into the vector
    s.col='#';
    v.push_back(s);
}

void SortDialog::on_Next_clicked()
{
    i++;
    Insort_step();          //increment the outer loop's i & call the inner loop of insertion sort algo
    for(int i=0;i<v.size();i++)
        cout<<v[i].e<<"*";

    //painthelp(v);
}

void SortDialog::painthelp(vector<S> v)     //help function for the paintevent function
{
    QPainter painter;
    int j = 0;
    painter.begin(this);
    painter.setPen(Qt:: black);
    painter.setFont(QFont("Arial", 20));
   //int j;
    int x =200,y =100;
     update();
    for (j = 0; j < v.size();j++)
    {   //cout<<v[i]<<" ";

        QRect rect(x,y,50,50) ;
        painter.drawRect(rect);         //draws the current state of the vector stored as private data member
        if(v[j].col=='r')
        {
            painter.fillRect(rect,Qt::gray);
        }
        painter.drawText(rect,Qt::AlignCenter,QString("%1").arg(v[j].e),0);
        x = x +50;
    }
}

void SortDialog::on_pushButton_clicked()
{
    v.clear();
    i=0;        //clear the vector v which stores the inserted elements
}

void SortDialog::on_pushButton_2_clicked()
{

    Selsort_step();
    i++;                    //call the inner loop of selection sort algo and increment the outer loop's i
    for(int i=0;i<v.size();i++)
        cout<<v[i].e<<"*";

}

void SortDialog::Selsort_step()
{
    int j;
    if (i < v.size())
    {
        int min = i;
        cout<<"#"<<min<<"#";
        for (j=i+1;j<v.size();j++)          //inner loop of standard selsort algo
        {
             if(v[j].e < v[min].e)
                 min = j;
        }
        int tmp=v[i].e;
        v[i].e=v[min].e;
        v[min].e=tmp;
        v[i].col=v[min].col='r';
        cout<<j<<"->"<<v[j].e<<";";

    }
}

void SortDialog::on_InSortTheory_clicked()
{
    QString std = "Insertion sort is a simple sorting algorithm that builds the final sorted array (or list) one item at a time. Advantages of insertion sort are: \n";

    QString std1 =        std.append("Simple implementation.\n ");
    QString std2 =         std1.append("Efficient for (quite) small data sets.\n");
    QString std3 =         std2.append("Adaptive (i.e., efficient) for data sets that are already substantially sorted: the time complexity is O(n + d), where d is the number of inversions.\n");
    QString std4 =         std3.append("More efficient in practice than most other simple quadratic (i.e., O(n2)) algorithms such as selection sort or bubble sort; the best case (nearly sorted input) is O(n).\n");
    QString std5 =         std4.append("Stable; i.e., does not change the relative order of elements with equal keys.\n");
    QString std6 =         std5.append("In-place; i.e., only requires a constant amount O(1) of additional memory space.\n");
    QString std7 =         std6.append("Online; i.e., can sort a list as it receives it.\n");

    QString std8 =    std7.append("When humans manually sort something (for example, a deck of playing cards), most use a method that is similar to insertion sort");

    QMessageBox :: information(this,"INSERTION SORT",std8);
}

void SortDialog::on_SelSortTheory_clicked()
{
    QString std = "In computer science, a selection sort is a sorting algorithm, specifically an in-place comparison sort. It has O(n2) time complexity, making it inefficient on large lists, and generally performs worse than the similar insertion sort. ";
    QString std1= std.append("Selection sort is noted for its simplicity, and also has performance advantages over more complicated algorithms in certain situations, particularly where auxiliary memory is limited.\n");

    QString std2 = std1.append("The algorithm is divided into two parts: the sublist of items already sorted, which is built up from left to right and is found at the beginning, and the sublist of items remaining to be sorted, occupying the remainder of the array.");
    QMessageBox :: information(this,"SELECTION SORT",std2);

}
