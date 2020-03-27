/********************************************************************************
** Form generated from reading UI file 'queuedialog.ui'
**
** Created: Fri Nov 16 05:28:18 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUEUEDIALOG_H
#define UI_QUEUEDIALOG_H

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

class Ui_QueueDialog
{
public:
    QPushButton *Pop;
    QLabel *output;
    QLineEdit *lineEdit;
    QPushButton *pushback;
    QPushButton *Front;
    QPushButton *Size;
    QPushButton *Theory;

    void setupUi(QDialog *QueueDialog)
    {
        if (QueueDialog->objectName().isEmpty())
            QueueDialog->setObjectName(QString::fromUtf8("QueueDialog"));
        QueueDialog->resize(623, 538);
        Pop = new QPushButton(QueueDialog);
        Pop->setObjectName(QString::fromUtf8("Pop"));
        Pop->setGeometry(QRect(30, 100, 97, 27));
        output = new QLabel(QueueDialog);
        output->setObjectName(QString::fromUtf8("output"));
        output->setGeometry(QRect(150, 150, 331, 41));
        lineEdit = new QLineEdit(QueueDialog);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(30, 20, 113, 27));
        pushback = new QPushButton(QueueDialog);
        pushback->setObjectName(QString::fromUtf8("pushback"));
        pushback->setGeometry(QRect(30, 60, 97, 27));
        Front = new QPushButton(QueueDialog);
        Front->setObjectName(QString::fromUtf8("Front"));
        Front->setGeometry(QRect(30, 180, 97, 27));
        Size = new QPushButton(QueueDialog);
        Size->setObjectName(QString::fromUtf8("Size"));
        Size->setGeometry(QRect(30, 140, 97, 27));
        Theory = new QPushButton(QueueDialog);
        Theory->setObjectName(QString::fromUtf8("Theory"));
        Theory->setGeometry(QRect(30, 210, 97, 27));

        retranslateUi(QueueDialog);

        QMetaObject::connectSlotsByName(QueueDialog);
    } // setupUi

    void retranslateUi(QDialog *QueueDialog)
    {
        QueueDialog->setWindowTitle(QApplication::translate("QueueDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        Pop->setText(QApplication::translate("QueueDialog", "pop", 0, QApplication::UnicodeUTF8));
        output->setText(QString());
        pushback->setText(QApplication::translate("QueueDialog", "Pushback", 0, QApplication::UnicodeUTF8));
        Front->setText(QApplication::translate("QueueDialog", "Front", 0, QApplication::UnicodeUTF8));
        Size->setText(QApplication::translate("QueueDialog", "Size", 0, QApplication::UnicodeUTF8));
        Theory->setText(QApplication::translate("QueueDialog", "Theory", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class QueueDialog: public Ui_QueueDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUEUEDIALOG_H
