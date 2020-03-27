#include "delta.h"
#include "ui_delta.h"

delta::delta(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::delta)
{
    ui->setupUi(this);
}

delta::~delta()
{
    delete ui;
}

void delta::paintEvent(QPaintEvent *)
{
}
