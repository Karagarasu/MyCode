/********************************************************************************
** Form generated from reading UI file 'Maye.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAYE_H
#define UI_MAYE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MayeClass
{
public:

    void setupUi(QWidget *MayeClass)
    {
        if (MayeClass->objectName().isEmpty())
            MayeClass->setObjectName("MayeClass");
        MayeClass->resize(600, 400);

        retranslateUi(MayeClass);

        QMetaObject::connectSlotsByName(MayeClass);
    } // setupUi

    void retranslateUi(QWidget *MayeClass)
    {
        MayeClass->setWindowTitle(QCoreApplication::translate("MayeClass", "Maye", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MayeClass: public Ui_MayeClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAYE_H
