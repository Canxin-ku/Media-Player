/********************************************************************************
** Form generated from reading UI file 'myslider.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYSLIDER_H
#define UI_MYSLIDER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MySlider
{
public:

    void setupUi(QWidget *MySlider)
    {
        if (MySlider->objectName().isEmpty())
            MySlider->setObjectName(QStringLiteral("MySlider"));
        MySlider->resize(400, 300);

        retranslateUi(MySlider);

        QMetaObject::connectSlotsByName(MySlider);
    } // setupUi

    void retranslateUi(QWidget *MySlider)
    {
        MySlider->setWindowTitle(QApplication::translate("MySlider", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MySlider: public Ui_MySlider {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYSLIDER_H
