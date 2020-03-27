#include "AVLdialog.h"
#include "ui_dialog.h"
#include "AVL.h"
#include <QObject>
#include<QtGui>
#include <QtCore>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

void Dialog:: print(AVLNode *v)
{
    QPainter painter;           //helper function for the paintevent function
    painter.begin(this);        //follows the same algorithm as preorder traversal,
                                //only that on every visit draws the rectangle assosciated with the node
    painter.setPen(Qt::black);
    painter.setFont(QFont("Arial", 20));
    if(v==NULL)
        return;

    else if(v->left==NULL && v->right==NULL)
    {
        QRect rect(v->x,v->y,50,50);
        painter.drawRect(rect);
        painter.drawText(rect,Qt::AlignCenter,QString("%1").arg(v->nodeval),0);

        return;

    }
    else if(v->left==NULL)
    {
        QRect rect(v->x,v->y,50,50);
        painter.drawRect(rect);
        painter.drawText(rect,Qt::AlignCenter,QString("%1").arg(v->nodeval),0);
        painter.drawLine(v->x+50,v->y+25,v->right->x+25,v->right->y);
        print(v->right);
    }
    else if(v->right==NULL)
    {

        QRect rect(v->x,v->y,50,50);
        painter.drawRect(rect);
        painter.drawText(rect,Qt::AlignCenter,QString("%1").arg(v->nodeval),0);
        painter.drawLine(v->x,v->y+25,v->left->x+25,v->left->y);

        print(v->left);

    }
    else
    {

        QRect rect(v->x,v->y,50,50);
        painter.drawRect(rect);
        painter.drawText(rect,Qt::AlignCenter,QString("%1").arg(v->nodeval),0);
        painter.drawLine(v->x+50,v->y+25,v->right->x+25,v->right->y);
        painter.drawLine(v->x,v->y+25,v->left->x+25,v->left->y);

        print(v->left);
        print(v->right);
    }
}
void Dialog:: paintEvent(QPaintEvent*)
{
        update();           //erase everything and redraws
        print(a.root());
}
Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()    //on pushing this button
{
    a.Insert(ui->lineEdit->text().toInt()); //does everything inside the slot body ie insert the value in lineedit into the tree
    a.setxy(a.root());
}

void Dialog::on_Theory_clicked()
{
    QString std = "In computer science, an AVL tree is a self-balancing binary search tree, and it was the first such data structure to be invented.\n" ;
    QString std1 =  std.append("In an AVL tree, the heights of the two child subtrees of any node differ by at most one; if at any time they differ by more than one, rebalancing is done to restore this property.\n");
    QString std2 =  std1.append("Lookup, insertion, and deletion all take O(log n) time in both the average and worst cases, where n is the number of nodes in the tree prior to the operation.\n");
    QString std3 =  std2.append("Insertions and deletions may require the tree to be rebalanced by one or more tree rotations.");
    QMessageBox :: information(this,"AVL TREE",std3);
}
