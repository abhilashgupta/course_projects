#ifndef QUEUEDIALOG_H
#define QUEUEDIALOG_H

#include <QDialog>
#include<list>
#include<QPainter>
using namespace std;

namespace Ui {
class QueueDialog;
}

class QueueDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit QueueDialog(QWidget *parent = 0);  //constructor
    ~QueueDialog();                             //destructor
    void paintEvent(QPaintEvent *);             //paintevent function provided by Qt which paints on the dialog

private slots:
    void on_pushback_clicked();         //slot for pushbutton - Push

    void on_Pop_clicked();              //slot for pushbutton - Pop

    void on_Size_clicked();             //slot for pushbutton - Size

    void on_Front_clicked();            //slot for pushbutton - Front

    void on_Theory_clicked();           //slot for pushbutton - Theory
    
private:
    Ui::QueueDialog *ui;    //pointer to the ui of this dialog
    list<int> queue;        //keeps the actual object of the data as a member to the dialog object
    int colourcode;         //data member to facilitate coloring of front element ie flag element
};

#endif // QUEUEDIALOG_H
