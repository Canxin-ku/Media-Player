/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QTabWidget *m_tabWidget;
    QWidget *tab_menber;
    QWidget *tab_list;
    QListWidget *listWidget;
    QPushButton *pushButton;
    QWidget *tab_chat;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(800, 600);
        m_tabWidget = new QTabWidget(Widget);
        m_tabWidget->setObjectName(QStringLiteral("m_tabWidget"));
        m_tabWidget->setGeometry(QRect(600, 0, 200, 600));
        tab_menber = new QWidget();
        tab_menber->setObjectName(QStringLiteral("tab_menber"));
        m_tabWidget->addTab(tab_menber, QString());
        tab_list = new QWidget();
        tab_list->setObjectName(QStringLiteral("tab_list"));
        listWidget = new QListWidget(tab_list);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(0, 1, 194, 500));
        pushButton = new QPushButton(tab_list);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(60, 520, 71, 41));
        QIcon icon;
        icon.addFile(QStringLiteral(":/iamge/icon/filePath.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);
        pushButton->setIconSize(QSize(22, 22));
        m_tabWidget->addTab(tab_list, QString());
        tab_chat = new QWidget();
        tab_chat->setObjectName(QStringLiteral("tab_chat"));
        m_tabWidget->addTab(tab_chat, QString());

        retranslateUi(Widget);

        m_tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        m_tabWidget->setTabText(m_tabWidget->indexOf(tab_menber), QApplication::translate("Widget", "\346\210\220\345\221\230", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Widget", "\351\200\211\346\213\251", Q_NULLPTR));
        m_tabWidget->setTabText(m_tabWidget->indexOf(tab_list), QApplication::translate("Widget", "\346\222\255\346\224\276\345\210\227\350\241\250", Q_NULLPTR));
        m_tabWidget->setTabText(m_tabWidget->indexOf(tab_chat), QApplication::translate("Widget", "\350\201\212\345\244\251", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
