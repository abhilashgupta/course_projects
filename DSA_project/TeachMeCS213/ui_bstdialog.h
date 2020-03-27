/********************************************************************************
** Form generated from reading UI file 'bstdialog.ui'
**
** Created: Fri Nov 16 05:28:18 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BSTDIALOG_H
#define UI_BSTDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_BSTDialog
{
public:
    QLineEdit *lineEdit_2;
    QPushButton *pushButton;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton_2;
    QPushButton *Theory;

    void setupUi(QDialog *BSTDialog)
    {
        if (BSTDialog->objectName().isEmpty())
            BSTDialog->setObjectName(QString::fromUtf8("BSTDialog"));
        BSTDialog->resize(774, 554);
        lineEdit_2 = new QLineEdit(BSTDialog);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(223, 10, 61, 27));
        pushButton = new QPushButton(BSTDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(73, 10, 98, 27));
        pushButton_4 = new QPushButton(BSTDialog);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(360, 10, 71, 27));
        pushButton_3 = new QPushButton(BSTDialog);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(513, 10, 98, 27));
        lineEdit = new QLineEdit(BSTDialog);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(13, 10, 61, 27));
        lineEdit_3 = new QLineEdit(BSTDialog);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(453, 10, 61, 27));
        pushButton_2 = new QPushButton(BSTDialog);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(290, 10, 71, 27));
        Theory = new QPushButton(BSTDialog);
        Theory->setObjectName(QString::fromUtf8("Theory"));
        Theory->setGeometry(QRect(650, 10, 98, 27));

        retranslateUi(BSTDialog);

        QMetaObject::connectSlotsByName(BSTDialog);
    } // setupUi

    void retranslateUi(QDialog *BSTDialog)
    {
        BSTDialog->setWindowTitle(QApplication::translate("BSTDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("BSTDialog", "Insert", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("BSTDialog", "Refresh", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("BSTDialog", "Delete", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("BSTDialog", "Search", 0, QApplication::UnicodeUTF8));
        Theory->setText(QApplication::translate("BSTDialog", "Theory", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BSTDialog: public Ui_BSTDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BSTDIALOG_H
