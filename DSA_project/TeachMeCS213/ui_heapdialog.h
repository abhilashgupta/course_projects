/********************************************************************************
** Form generated from reading UI file 'heapdialog.ui'
**
** Created: Fri Nov 16 05:28:19 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HEAPDIALOG_H
#define UI_HEAPDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_heapDialog
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *maxoutput;
    QLineEdit *lineEdit;
    QPushButton *findmax;
    QPushButton *Theory;

    void setupUi(QDialog *heapDialog)
    {
        if (heapDialog->objectName().isEmpty())
            heapDialog->setObjectName(QString::fromUtf8("heapDialog"));
        heapDialog->resize(749, 569);
        pushButton = new QPushButton(heapDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(20, 40, 101, 21));
        pushButton_2 = new QPushButton(heapDialog);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(20, 70, 97, 27));
        maxoutput = new QLabel(heapDialog);
        maxoutput->setObjectName(QString::fromUtf8("maxoutput"));
        maxoutput->setGeometry(QRect(0, 310, 251, 41));
        lineEdit = new QLineEdit(heapDialog);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(10, 10, 113, 27));
        findmax = new QPushButton(heapDialog);
        findmax->setObjectName(QString::fromUtf8("findmax"));
        findmax->setGeometry(QRect(20, 110, 97, 27));
        Theory = new QPushButton(heapDialog);
        Theory->setObjectName(QString::fromUtf8("Theory"));
        Theory->setGeometry(QRect(20, 150, 98, 27));

        retranslateUi(heapDialog);

        QMetaObject::connectSlotsByName(heapDialog);
    } // setupUi

    void retranslateUi(QDialog *heapDialog)
    {
        heapDialog->setWindowTitle(QApplication::translate("heapDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("heapDialog", "Insert", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("heapDialog", "DeleteMax", 0, QApplication::UnicodeUTF8));
        maxoutput->setText(QString());
        findmax->setText(QApplication::translate("heapDialog", "findmax", 0, QApplication::UnicodeUTF8));
        Theory->setText(QApplication::translate("heapDialog", "Theory", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class heapDialog: public Ui_heapDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HEAPDIALOG_H
