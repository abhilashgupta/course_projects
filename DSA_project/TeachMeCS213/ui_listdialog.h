/********************************************************************************
** Form generated from reading UI file 'listdialog.ui'
**
** Created: Fri Nov 16 05:28:18 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LISTDIALOG_H
#define UI_LISTDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ListDialog
{
public:
    QLineEdit *lineEdit_2;
    QPushButton *pushButton_4;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QPushButton *Theory;
    QPushButton *pushButton_5;

    void setupUi(QDialog *ListDialog)
    {
        if (ListDialog->objectName().isEmpty())
            ListDialog->setObjectName(QString::fromUtf8("ListDialog"));
        ListDialog->resize(735, 510);
        lineEdit_2 = new QLineEdit(ListDialog);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(390, 40, 58, 27));
        pushButton_4 = new QPushButton(ListDialog);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(110, 40, 111, 27));
        lineEdit = new QLineEdit(ListDialog);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(330, 10, 211, 27));
        pushButton = new QPushButton(ListDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(110, 10, 98, 27));
        pushButton_3 = new QPushButton(ListDialog);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(10, 40, 98, 27));
        pushButton_2 = new QPushButton(ListDialog);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(210, 10, 101, 27));
        Theory = new QPushButton(ListDialog);
        Theory->setObjectName(QString::fromUtf8("Theory"));
        Theory->setGeometry(QRect(10, 10, 97, 27));
        pushButton_5 = new QPushButton(ListDialog);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(230, 40, 158, 27));

        retranslateUi(ListDialog);

        QMetaObject::connectSlotsByName(ListDialog);
    } // setupUi

    void retranslateUi(QDialog *ListDialog)
    {
        ListDialog->setWindowTitle(QApplication::translate("ListDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("ListDialog", "Remove Before", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("ListDialog", "InsertAfter", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("ListDialog", "Remove After", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("ListDialog", "Insert Before", 0, QApplication::UnicodeUTF8));
        Theory->setText(QApplication::translate("ListDialog", "Theory", 0, QApplication::UnicodeUTF8));
        pushButton_5->setText(QApplication::translate("ListDialog", "Insert at k=", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ListDialog: public Ui_ListDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LISTDIALOG_H
