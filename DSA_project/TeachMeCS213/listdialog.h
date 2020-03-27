#ifndef LISTDIALOG_H
#define LISTDIALOG_H

#include <QDialog>
#include <QRect>
#include <QtGui>
#include <QString>
#include <list>

namespace Ui {
class ListDialog;
}

using namespace std;

struct coordinates{
    int x;
    int y;
};

class ListDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit ListDialog(QWidget *parent = 0);   //constructor
    ~ListDialog();                              //destructor
    void paintEvent(QPaintEvent*);              //paintevent function provided by Qt which paints on the dialog


private slots:

    void on_pushButton_clicked();       //slot for pushbutton - Pushback

    void on_pushButton_2_clicked();     //slot for pushbutton - Pushfront

    void on_pushButton_3_clicked();     //slot for pushbutton - Popback

    void on_pushButton_4_clicked();     //slot for pushbutton - popfront

    void on_pushButton_5_clicked();     //slot for pushbutton - Insert at K

    void on_Theory_clicked();           //slot for pushbutton - Theory


    
private:
    Ui::ListDialog *ui;         //pointer to the ui of this dialog
    list<int> numOne;           //keeps the actual object of the data as a member to the dialog object
    int count;                  //stores size
};

#endif // LISTDIALOG_H
