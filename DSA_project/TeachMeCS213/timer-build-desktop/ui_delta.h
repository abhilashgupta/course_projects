/********************************************************************************
** Form generated from reading UI file 'delta.ui'
**
** Created: Wed Dec 5 12:20:52 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELTA_H
#define UI_DELTA_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_delta
{
public:

    void setupUi(QDialog *delta)
    {
        if (delta->objectName().isEmpty())
            delta->setObjectName(QString::fromUtf8("delta"));
        delta->resize(400, 300);

        retranslateUi(delta);

        QMetaObject::connectSlotsByName(delta);
    } // setupUi

    void retranslateUi(QDialog *delta)
    {
        delta->setWindowTitle(QApplication::translate("delta", "delta", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class delta: public Ui_delta {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELTA_H
