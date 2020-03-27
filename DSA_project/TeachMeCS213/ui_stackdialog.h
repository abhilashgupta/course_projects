/********************************************************************************
** Form generated from reading UI file 'stackdialog.ui'
**
** Created: Fri Nov 16 05:28:18 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STACKDIALOG_H
#define UI_STACKDIALOG_H

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

class Ui_StackDialog
{
public:
    QPushButton *top;
    QPushButton *sizecall;
    QPushButton *Push;
    QPushButton *Theory;
    QPushButton *pop;
    QLabel *size;
    QLineEdit *lineEdit;

    void setupUi(QDialog *StackDialog)
    {
        if (StackDialog->objectName().isEmpty())
            StackDialog->setObjectName(QString::fromUtf8("StackDialog"));
        StackDialog->resize(653, 531);
        top = new QPushButton(StackDialog);
        top->setObjectName(QString::fromUtf8("top"));
        top->setGeometry(QRect(20, 170, 97, 27));
        sizecall = new QPushButton(StackDialog);
        sizecall->setObjectName(QString::fromUtf8("sizecall"));
        sizecall->setGeometry(QRect(20, 130, 97, 27));
        Push = new QPushButton(StackDialog);
        Push->setObjectName(QString::fromUtf8("Push"));
        Push->setGeometry(QRect(20, 50, 97, 27));
        Theory = new QPushButton(StackDialog);
        Theory->setObjectName(QString::fromUtf8("Theory"));
        Theory->setGeometry(QRect(20, 210, 97, 27));
        pop = new QPushButton(StackDialog);
        pop->setObjectName(QString::fromUtf8("pop"));
        pop->setGeometry(QRect(20, 90, 97, 27));
        size = new QLabel(StackDialog);
        size->setObjectName(QString::fromUtf8("size"));
        size->setGeometry(QRect(10, 240, 331, 71));
        lineEdit = new QLineEdit(StackDialog);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(20, 10, 91, 27));

        retranslateUi(StackDialog);

        QMetaObject::connectSlotsByName(StackDialog);
    } // setupUi

    void retranslateUi(QDialog *StackDialog)
    {
        StackDialog->setWindowTitle(QApplication::translate("StackDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        top->setText(QApplication::translate("StackDialog", "Top", 0, QApplication::UnicodeUTF8));
        sizecall->setText(QApplication::translate("StackDialog", "Size", 0, QApplication::UnicodeUTF8));
        Push->setText(QApplication::translate("StackDialog", "Push", 0, QApplication::UnicodeUTF8));
        Theory->setText(QApplication::translate("StackDialog", "Theory", 0, QApplication::UnicodeUTF8));
        pop->setText(QApplication::translate("StackDialog", "Pop", 0, QApplication::UnicodeUTF8));
        size->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class StackDialog: public Ui_StackDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STACKDIALOG_H
