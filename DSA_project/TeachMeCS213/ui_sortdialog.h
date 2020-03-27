/********************************************************************************
** Form generated from reading UI file 'sortdialog.ui'
**
** Created: Fri Nov 16 19:41:12 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SORTDIALOG_H
#define UI_SORTDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SortDialog
{
public:
    QLineEdit *lineedit;
    QPushButton *Input;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *Next;
    QPushButton *InSortTheory;
    QPushButton *SelSortTheory;

    void setupUi(QDialog *SortDialog)
    {
        if (SortDialog->objectName().isEmpty())
            SortDialog->setObjectName(QString::fromUtf8("SortDialog"));
        SortDialog->resize(588, 407);
        lineedit = new QLineEdit(SortDialog);
        lineedit->setObjectName(QString::fromUtf8("lineedit"));
        lineedit->setGeometry(QRect(10, 10, 113, 27));
        Input = new QPushButton(SortDialog);
        Input->setObjectName(QString::fromUtf8("Input"));
        Input->setGeometry(QRect(20, 50, 97, 27));
        pushButton = new QPushButton(SortDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(20, 80, 98, 27));
        pushButton_2 = new QPushButton(SortDialog);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(10, 140, 121, 27));
        Next = new QPushButton(SortDialog);
        Next->setObjectName(QString::fromUtf8("Next"));
        Next->setGeometry(QRect(10, 110, 121, 27));
        InSortTheory = new QPushButton(SortDialog);
        InSortTheory->setObjectName(QString::fromUtf8("InSortTheory"));
        InSortTheory->setGeometry(QRect(20, 170, 98, 27));
        SelSortTheory = new QPushButton(SortDialog);
        SelSortTheory->setObjectName(QString::fromUtf8("SelSortTheory"));
        SelSortTheory->setGeometry(QRect(17, 200, 111, 27));

        retranslateUi(SortDialog);

        QMetaObject::connectSlotsByName(SortDialog);
    } // setupUi

    void retranslateUi(QDialog *SortDialog)
    {
        SortDialog->setWindowTitle(QApplication::translate("SortDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        Input->setText(QApplication::translate("SortDialog", "Input", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("SortDialog", "Refresh", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("SortDialog", "Selsort Next Step", 0, QApplication::UnicodeUTF8));
        Next->setText(QApplication::translate("SortDialog", "Insort Next Step", 0, QApplication::UnicodeUTF8));
        InSortTheory->setText(QApplication::translate("SortDialog", "Insort Theory", 0, QApplication::UnicodeUTF8));
        SelSortTheory->setText(QApplication::translate("SortDialog", "Selsort Theory", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SortDialog: public Ui_SortDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SORTDIALOG_H
