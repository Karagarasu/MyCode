/********************************************************************************
** Form generated from reading UI file 'ILoveYou.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ILOVEYOU_H
#define UI_ILOVEYOU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ILoveYouClass
{
public:

    void setupUi(QWidget *ILoveYouClass)
    {
        if (ILoveYouClass->objectName().isEmpty())
            ILoveYouClass->setObjectName("ILoveYouClass");
        ILoveYouClass->resize(600, 400);

        retranslateUi(ILoveYouClass);

        QMetaObject::connectSlotsByName(ILoveYouClass);
    } // setupUi

    void retranslateUi(QWidget *ILoveYouClass)
    {
        ILoveYouClass->setWindowTitle(QCoreApplication::translate("ILoveYouClass", "ILoveYou", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ILoveYouClass: public Ui_ILoveYouClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ILOVEYOU_H
