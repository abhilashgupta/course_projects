#include "bstdialog.h"
#include "ui_bstdialog.h"

BSTDialog::BSTDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BSTDialog)
{
    ui->setupUi(this);
}
void BSTDialog:: paintEvent(QPaintEvent*)
{

        update();       //erase everything and redraws
        print(b.root());
}
void BSTDialog:: print(TreeNode *v)
{
    QPainter painter;
    painter.begin(this);        //helper function for the paintevent function
                                //follows the same algorithm as preorder traversal,
                                //only that on every visit draws the rectangle assosciated with the node
    painter.setPen(Qt::black);
    painter.setFont(QFont("Arial", 20));
    if(v==NULL)
        return;

    else if(v->left==NULL && v->right==NULL)
    {
        QRect rect(v->x,v->y,50,50);
        painter.drawRect(rect);
        if(v->color=='r')
            painter.fillRect(rect,Qt::red);
        if(v->color=='g')
            painter.fillRect(rect,Qt::green);
        painter.drawText(rect,Qt::AlignCenter,QString("%1").arg(v->nodeval),0);
        if(v->h>0)
        {
            if(v->nodeval<=v->parent->nodeval)
                painter.drawLine(v->parent->x,v->parent->y+25,v->x+25,v->y);
            else
                painter.drawLine(v->parent->x+50,v->parent->y+25,v->x+25,v->y);

        }
        return;

    }
    else if(v->left==NULL)
    {
        QRect rect(v->x,v->y,50,50);
        painter.drawRect(rect);
        if(v->color=='r')
            painter.fillRect(rect,Qt::red);
        if(v->color=='g')
            painter.fillRect(rect,Qt::green);
        painter.drawText(rect,Qt::AlignCenter,QString("%1").arg(v->nodeval),0);
        if(v->h>0)
        {
            if(v->nodeval<=v->parent->nodeval)
                painter.drawLine(v->parent->x,v->parent->y+25,v->x+25,v->y);
            else
                painter.drawLine(v->parent->x+50,v->parent->y+25,v->x+25,v->y);
        }
        print(v->right);
    }
    else if(v->right==NULL)
    {

        QRect rect(v->x,v->y,50,50);
        painter.drawRect(rect);
        if(v->color=='r')
            painter.fillRect(rect,Qt::red);
        if(v->color=='g')
            painter.fillRect(rect,Qt::green);
        painter.drawText(rect,Qt::AlignCenter,QString("%1").arg(v->nodeval),0);
        if(v->h>0)
        {
            if(v->nodeval<=v->parent->nodeval)
                painter.drawLine(v->parent->x,v->parent->y+25,v->x+25,v->y);
            else
                painter.drawLine(v->parent->x+50,v->parent->y+25,v->x+25,v->y);
        }
        print(v->left);

    }
    else
    {

        QRect rect(v->x,v->y,50,50);
        painter.drawRect(rect);
        if(v->color=='r')
            painter.fillRect(rect,Qt::red);
        if(v->color=='g')
            painter.fillRect(rect,Qt::green);
        painter.drawText(rect,Qt::AlignCenter,QString("%1").arg(v->nodeval),0);
        if(v->h>0)
        {
            if(v->nodeval<=v->parent->nodeval)
                painter.drawLine(v->parent->x,v->parent->y+25,v->x+25,v->y);
            else
                painter.drawLine(v->parent->x+50,v->parent->y+25,v->x+25,v->y);
        }
        print(v->left);
        print(v->right);
    }
}
BSTDialog::~BSTDialog()
{
    delete ui;
}

void BSTDialog::on_pushButton_clicked()     //on pushing this button
{
    b.Insert(ui->lineEdit->text().toInt());     //insert node wid value equal to value of lineedit
}

void BSTDialog::on_pushButton_2_clicked()       //on pushing this button
{
     b.Search(ui->lineEdit_2->text().toInt());      //search for node with value equal to value of lineedit
}

void BSTDialog::on_pushButton_4_clicked()       //on pushing this button
{
    b.refresh();                                //decolorises all nodes
}

void BSTDialog::on_pushButton_3_clicked()       //on pushing this button
{
    b.Delete(ui->lineEdit_3->text().toInt());   //delete the node wid value equal to value of lineedit_3
}

void BSTDialog::on_Theory_clicked()
{
    QString std = "In computer science, a binary search tree (BST), which may sometimes also be called an ordered or sorted binary tree, is a node-based binary tree data structure which has the following properties:\n";

    QString std1 =     std.append("The left subtree of a node contains only nodes with keys less than the node's key.\n");
    QString std2 =     std1.append("The right subtree of a node contains only nodes with keys greater than the node's key.\n");
    QString std3 =     std2.append("Both the left and right subtrees must also be binary search trees.\n");
    QString std4 =     std3.append("There must be no duplicate nodes.");

    QMessageBox :: information(this,"BINARY SEARCH TREE",std4);
}
