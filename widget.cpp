#include "widget.h"
#include "ui_widget.h"
#include <QScreen>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    const int width = QGuiApplication::primaryScreen()->geometry().width();
    const int height = QGuiApplication::primaryScreen()->geometry().height();

    setWindowTitle("播放器");
    move(width*.2,height*.2);
    m_MediaPlayer = new QMediaPlayer;   //播放器
    m_VideoWidget = new QVideoWidget(ui->m_playerWidget);   //播放窗口并赋值到UI上
    m_MediaPlayList = new QMediaPlaylist;   //播放列表

    m_MediaPlayer->setPlaylist(m_MediaPlayList);    //播放器添加播放列表
    m_MediaPlayer->setVideoOutput(m_VideoWidget);   //输出到播放窗口

    //设置焦点
    ui->m_videoTimeBar->setFocusPolicy(Qt::NoFocus);
    ui->m_backBtn->setFocusPolicy(Qt::NoFocus);
    ui->m_nextBtn->setFocusPolicy(Qt::NoFocus);
    ui->m_playBtn->setFocusPolicy(Qt::NoFocus);
    ui->m_stopBtn->setFocusPolicy(Qt::NoFocus);
    ui->m_volumeBar->setFocusPolicy(Qt::NoFocus);
    ui->m_volumeBtn->setFocusPolicy(Qt::NoFocus);
    ui->m_fullScreenBtn->setFocusPolicy(Qt::NoFocus);
    ui->tab_chat->setFocusPolicy(Qt::NoFocus);
    ui->tab_list->setFocusPolicy(Qt::NoFocus);
    ui->tab_menber->setFocusPolicy(Qt::NoFocus);
    ui->m_filePathBtn->setFocusPolicy(Qt::NoFocus);
    ui->m_videoList->setFocusPolicy(Qt::ClickFocus);
    ui->m_playerWidget->setFocusPolicy(Qt::ClickFocus);

    //进度条
    m_SliderHover
}

Widget::~Widget()
{
    delete ui;
}
