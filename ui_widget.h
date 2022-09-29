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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>
#include <myslider.h>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout;
    QWidget *widget_operate;
    QGridLayout *gridLayout_2;
    MySlider *slider_allTime;
    QHBoxLayout *layout_operate_h;
    QLabel *label_allTime;
    QLabel *label_slash;
    QLabel *label_currentTime;
    QWidget *widget_operate_space;
    QPushButton *btn_stop;
    QPushButton *btn_back;
    QPushButton *btn_play;
    QPushButton *btn_next;
    QPushButton *btn_volume;
    MySlider *slider_volume;
    QWidget *widget_operate_space2;
    QPushButton *btn_fullScreen;
    QTabWidget *widget_tab;
    QWidget *tab_menber;
    QWidget *tab_list;
    QGridLayout *gridLayout_3;
    QListWidget *listWidget_play;
    QPushButton *btn_filePath;
    QWidget *tab_chat;
    QWidget *widget_video;
    QLabel *label_title;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->setWindowModality(Qt::WindowModal);
        Widget->resize(800, 600);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Widget->sizePolicy().hasHeightForWidth());
        Widget->setSizePolicy(sizePolicy);
        Widget->setMinimumSize(QSize(800, 600));
        Widget->setInputMethodHints(Qt::ImhDialableCharactersOnly|Qt::ImhPreferUppercase);
        gridLayout = new QGridLayout(Widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetMaximumSize);
        gridLayout->setHorizontalSpacing(0);
        gridLayout->setVerticalSpacing(10);
        gridLayout->setContentsMargins(5, 0, 0, 0);
        widget_operate = new QWidget(Widget);
        widget_operate->setObjectName(QStringLiteral("widget_operate"));
        widget_operate->setMinimumSize(QSize(0, 100));
        widget_operate->setMaximumSize(QSize(16777215, 120));
        gridLayout_2 = new QGridLayout(widget_operate);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        slider_allTime = new MySlider(widget_operate);
        slider_allTime->setObjectName(QStringLiteral("slider_allTime"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(slider_allTime->sizePolicy().hasHeightForWidth());
        slider_allTime->setSizePolicy(sizePolicy1);
        slider_allTime->setMinimumSize(QSize(550, 25));
        slider_allTime->setMaximumSize(QSize(16777215, 25));
        QFont font;
        font.setKerning(true);
        slider_allTime->setFont(font);
        slider_allTime->setCursor(QCursor(Qt::OpenHandCursor));
        slider_allTime->setMaximum(100);
        slider_allTime->setOrientation(Qt::Horizontal);
        slider_allTime->setInvertedControls(false);
        slider_allTime->setTickPosition(QSlider::NoTicks);

        gridLayout_2->addWidget(slider_allTime, 0, 0, 1, 1);

        layout_operate_h = new QHBoxLayout();
        layout_operate_h->setSpacing(6);
        layout_operate_h->setObjectName(QStringLiteral("layout_operate_h"));
        layout_operate_h->setSizeConstraint(QLayout::SetMinAndMaxSize);
        label_allTime = new QLabel(widget_operate);
        label_allTime->setObjectName(QStringLiteral("label_allTime"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_allTime->sizePolicy().hasHeightForWidth());
        label_allTime->setSizePolicy(sizePolicy2);
        QFont font1;
        font1.setPointSize(12);
        label_allTime->setFont(font1);

        layout_operate_h->addWidget(label_allTime);

        label_slash = new QLabel(widget_operate);
        label_slash->setObjectName(QStringLiteral("label_slash"));
        label_slash->setEnabled(true);
        sizePolicy2.setHeightForWidth(label_slash->sizePolicy().hasHeightForWidth());
        label_slash->setSizePolicy(sizePolicy2);
        label_slash->setFont(font1);
        label_slash->setAlignment(Qt::AlignCenter);

        layout_operate_h->addWidget(label_slash);

        label_currentTime = new QLabel(widget_operate);
        label_currentTime->setObjectName(QStringLiteral("label_currentTime"));
        sizePolicy2.setHeightForWidth(label_currentTime->sizePolicy().hasHeightForWidth());
        label_currentTime->setSizePolicy(sizePolicy2);
        label_currentTime->setFont(font1);

        layout_operate_h->addWidget(label_currentTime);

        widget_operate_space = new QWidget(widget_operate);
        widget_operate_space->setObjectName(QStringLiteral("widget_operate_space"));
        sizePolicy.setHeightForWidth(widget_operate_space->sizePolicy().hasHeightForWidth());
        widget_operate_space->setSizePolicy(sizePolicy);

        layout_operate_h->addWidget(widget_operate_space);

        btn_stop = new QPushButton(widget_operate);
        btn_stop->setObjectName(QStringLiteral("btn_stop"));
        sizePolicy.setHeightForWidth(btn_stop->sizePolicy().hasHeightForWidth());
        btn_stop->setSizePolicy(sizePolicy);
        btn_stop->setMinimumSize(QSize(35, 35));
        btn_stop->setMaximumSize(QSize(50, 50));
        btn_stop->setStyleSheet(QStringLiteral("background-color:transparent;"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/image/icon/stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_stop->setIcon(icon);
        btn_stop->setIconSize(QSize(40, 40));

        layout_operate_h->addWidget(btn_stop);

        btn_back = new QPushButton(widget_operate);
        btn_back->setObjectName(QStringLiteral("btn_back"));
        sizePolicy.setHeightForWidth(btn_back->sizePolicy().hasHeightForWidth());
        btn_back->setSizePolicy(sizePolicy);
        btn_back->setMinimumSize(QSize(35, 35));
        btn_back->setMaximumSize(QSize(50, 50));
        btn_back->setStyleSheet(QStringLiteral("background-color:transparent;"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/image/icon/back.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_back->setIcon(icon1);
        btn_back->setIconSize(QSize(40, 40));

        layout_operate_h->addWidget(btn_back);

        btn_play = new QPushButton(widget_operate);
        btn_play->setObjectName(QStringLiteral("btn_play"));
        sizePolicy.setHeightForWidth(btn_play->sizePolicy().hasHeightForWidth());
        btn_play->setSizePolicy(sizePolicy);
        btn_play->setMinimumSize(QSize(35, 35));
        btn_play->setMaximumSize(QSize(50, 50));
        btn_play->setStyleSheet(QStringLiteral("background-color:transparent;"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/image/icon/play.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_play->setIcon(icon2);
        btn_play->setIconSize(QSize(40, 40));

        layout_operate_h->addWidget(btn_play);

        btn_next = new QPushButton(widget_operate);
        btn_next->setObjectName(QStringLiteral("btn_next"));
        sizePolicy.setHeightForWidth(btn_next->sizePolicy().hasHeightForWidth());
        btn_next->setSizePolicy(sizePolicy);
        btn_next->setMinimumSize(QSize(35, 35));
        btn_next->setMaximumSize(QSize(50, 50));
        btn_next->setStyleSheet(QStringLiteral("background-color:transparent;"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/image/icon/next.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_next->setIcon(icon3);
        btn_next->setIconSize(QSize(40, 40));

        layout_operate_h->addWidget(btn_next);

        btn_volume = new QPushButton(widget_operate);
        btn_volume->setObjectName(QStringLiteral("btn_volume"));
        sizePolicy.setHeightForWidth(btn_volume->sizePolicy().hasHeightForWidth());
        btn_volume->setSizePolicy(sizePolicy);
        btn_volume->setMinimumSize(QSize(35, 35));
        btn_volume->setMaximumSize(QSize(50, 50));
        btn_volume->setStyleSheet(QStringLiteral("background-color:transparent;"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/image/icon/volumePlay.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_volume->setIcon(icon4);
        btn_volume->setIconSize(QSize(40, 40));

        layout_operate_h->addWidget(btn_volume);

        slider_volume = new MySlider(widget_operate);
        slider_volume->setObjectName(QStringLiteral("slider_volume"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(15);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(slider_volume->sizePolicy().hasHeightForWidth());
        slider_volume->setSizePolicy(sizePolicy3);
        slider_volume->setMaximum(100);
        slider_volume->setOrientation(Qt::Horizontal);

        layout_operate_h->addWidget(slider_volume);

        widget_operate_space2 = new QWidget(widget_operate);
        widget_operate_space2->setObjectName(QStringLiteral("widget_operate_space2"));
        sizePolicy.setHeightForWidth(widget_operate_space2->sizePolicy().hasHeightForWidth());
        widget_operate_space2->setSizePolicy(sizePolicy);

        layout_operate_h->addWidget(widget_operate_space2);

        btn_fullScreen = new QPushButton(widget_operate);
        btn_fullScreen->setObjectName(QStringLiteral("btn_fullScreen"));
        sizePolicy.setHeightForWidth(btn_fullScreen->sizePolicy().hasHeightForWidth());
        btn_fullScreen->setSizePolicy(sizePolicy);
        btn_fullScreen->setMinimumSize(QSize(35, 35));
        btn_fullScreen->setMaximumSize(QSize(50, 50));
        btn_fullScreen->setStyleSheet(QStringLiteral("background-color:transparent;"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/image/icon/fullscreen.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_fullScreen->setIcon(icon5);
        btn_fullScreen->setIconSize(QSize(40, 40));

        layout_operate_h->addWidget(btn_fullScreen);


        gridLayout_2->addLayout(layout_operate_h, 1, 0, 1, 1);


        gridLayout->addWidget(widget_operate, 2, 0, 1, 1);

        widget_tab = new QTabWidget(Widget);
        widget_tab->setObjectName(QStringLiteral("widget_tab"));
        sizePolicy.setHeightForWidth(widget_tab->sizePolicy().hasHeightForWidth());
        widget_tab->setSizePolicy(sizePolicy);
        widget_tab->setMinimumSize(QSize(200, 600));
        widget_tab->setMaximumSize(QSize(250, 16777215));
        widget_tab->setStyleSheet(QStringLiteral(""));
        tab_menber = new QWidget();
        tab_menber->setObjectName(QStringLiteral("tab_menber"));
        widget_tab->addTab(tab_menber, QString());
        tab_list = new QWidget();
        tab_list->setObjectName(QStringLiteral("tab_list"));
        gridLayout_3 = new QGridLayout(tab_list);
        gridLayout_3->setSpacing(10);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(10, 0, 10, 0);
        listWidget_play = new QListWidget(tab_list);
        listWidget_play->setObjectName(QStringLiteral("listWidget_play"));
        listWidget_play->setStyleSheet(QStringLiteral(""));

        gridLayout_3->addWidget(listWidget_play, 0, 0, 1, 1);

        btn_filePath = new QPushButton(tab_list);
        btn_filePath->setObjectName(QStringLiteral("btn_filePath"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/image/icon/filePath.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_filePath->setIcon(icon6);
        btn_filePath->setIconSize(QSize(22, 22));

        gridLayout_3->addWidget(btn_filePath, 1, 0, 1, 1);

        widget_tab->addTab(tab_list, QString());
        tab_chat = new QWidget();
        tab_chat->setObjectName(QStringLiteral("tab_chat"));
        widget_tab->addTab(tab_chat, QString());

        gridLayout->addWidget(widget_tab, 0, 1, 3, 1);

        widget_video = new QWidget(Widget);
        widget_video->setObjectName(QStringLiteral("widget_video"));
        sizePolicy.setHeightForWidth(widget_video->sizePolicy().hasHeightForWidth());
        widget_video->setSizePolicy(sizePolicy);
        widget_video->setMinimumSize(QSize(577, 480));
        widget_video->setStyleSheet(QStringLiteral("background:rgb(0, 0, 0)"));
        label_title = new QLabel(widget_video);
        label_title->setObjectName(QStringLiteral("label_title"));
        label_title->setGeometry(QRect(0, 0, 577, 35));
        sizePolicy1.setHeightForWidth(label_title->sizePolicy().hasHeightForWidth());
        label_title->setSizePolicy(sizePolicy1);
        label_title->setMinimumSize(QSize(577, 35));
        QFont font2;
        font2.setPointSize(18);
        label_title->setFont(font2);
        label_title->setStyleSheet(QStringLiteral("background:transparent;color:rgb(255, 255, 255)"));
        label_title->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(widget_video, 1, 0, 1, 1);

        widget_tab->raise();
        widget_operate->raise();
        widget_video->raise();

        retranslateUi(Widget);

        widget_tab->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        label_allTime->setText(QApplication::translate("Widget", "00:00:00", Q_NULLPTR));
        label_slash->setText(QApplication::translate("Widget", "/", Q_NULLPTR));
        label_currentTime->setText(QApplication::translate("Widget", "00:00:00", Q_NULLPTR));
        btn_stop->setText(QString());
        btn_back->setText(QString());
        btn_play->setText(QString());
        btn_next->setText(QString());
        btn_volume->setText(QString());
        btn_fullScreen->setText(QString());
        widget_tab->setTabText(widget_tab->indexOf(tab_menber), QApplication::translate("Widget", "\346\210\220\345\221\230", Q_NULLPTR));
        btn_filePath->setText(QApplication::translate("Widget", " \351\200\211\346\213\251\346\226\207\344\273\266\345\244\271", Q_NULLPTR));
        widget_tab->setTabText(widget_tab->indexOf(tab_list), QApplication::translate("Widget", "\346\222\255\346\224\276\345\210\227\350\241\250", Q_NULLPTR));
        widget_tab->setTabText(widget_tab->indexOf(tab_chat), QApplication::translate("Widget", "\350\201\212\345\244\251", Q_NULLPTR));
        label_title->setText(QApplication::translate("Widget", "text", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
