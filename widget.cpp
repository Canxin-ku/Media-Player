#include "widget.h"
#include "ui_widget.h"
#include <QScreen>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    width = QGuiApplication::primaryScreen()->geometry().width();
    height = QGuiApplication::primaryScreen()->geometry().height();

    setWindowTitle("播放器");
    move(width*0.2,height*0.2);
    m_MediaPlayer = new QMediaPlayer;   //播放器
    m_VideoWidget = new QVideoWidget(ui->widget_video);   //播放窗口并赋值到UI上
    m_MediaPlayList = new QMediaPlaylist;   //播放列表

    m_MediaPlayer->setPlaylist(m_MediaPlayList);    //播放器添加播放列表
    m_MediaPlayer->setVideoOutput(m_VideoWidget);   //输出到播放窗口

    //按键可用
    ui->btn_stop->setDisabled(true);
    ui->btn_next->setDisabled(true);
    ui->btn_back->setDisabled(true);

    //设置焦点
    ui->btn_back->setFocusPolicy(Qt::ClickFocus);
    ui->btn_filePath->setFocusPolicy(Qt::ClickFocus);
    ui->btn_fullScreen->setFocusPolicy(Qt::ClickFocus);
    ui->btn_next->setFocusPolicy(Qt::ClickFocus);
    ui->btn_play->setFocusPolicy(Qt::ClickFocus);
    ui->btn_stop->setFocusPolicy(Qt::ClickFocus);
    ui->btn_volume->setFocusPolicy(Qt::ClickFocus);
    ui->slider_allTime->setFocusPolicy(Qt::ClickFocus);
    ui->slider_volume->setFocusPolicy(Qt::ClickFocus);
    ui->widget_operate->setFocusPolicy(Qt::ClickFocus);
    ui->widget_tab->setFocusPolicy(Qt::ClickFocus);
    ui->listWidget_play->setFocusPolicy(Qt::ClickFocus);
    ui->widget_video->setFocusPolicy(Qt::ClickFocus);
    ui->widget_operate->setFocusPolicy(Qt::ClickFocus);
    ui->listWidget_play->setFocusPolicy(Qt::ClickFocus);

    //绑定信号槽
    connect(ui->btn_filePath,&QPushButton::clicked,this,&Widget::btn_open_clicked);
    connect(ui->btn_play,&QPushButton::clicked,this,&Widget::btn_play_pause_clicked);
    connect(ui->btn_back,&QPushButton::clicked,this,&Widget::btn_backV_clicked);
    connect(ui->btn_stop,&QPushButton::clicked,this,&Widget::btn_stop_clicked);
    connect(ui->btn_next,&QPushButton::clicked,this,&Widget::btn_nextV_clicked);
    connect(ui->btn_volume,&QPushButton::clicked,this,&Widget::voice_play_mute_Cliced);
    connect(ui->btn_fullScreen,&QPushButton::clicked,this,&Widget::btn_fullscreen_clicked);

    //进度条
    m_SliderHover = false;

}

Widget::~Widget()
{
    delete ui;
}

//设置播放窗口大小
void Widget::resizeEvent(QResizeEvent *event)
{
    m_VideoWidget->resize(ui->widget_video->size());
}

//选取文件夹并扫描该文件夹下的视频文件
void Widget::btn_open_clicked()
{
    m_MediaPlayList->clear();   //播放器的播放列表清空
    m_StrList.clear();          //列表变量清空

    QDir fileDir = QFileDialog::getExistingDirectory(this,"保存","/");
    QStringList nameFilters;
    QString strDir = fileDir.absolutePath();
    nameFilters<<"*.mp4"<<"*.avi"<<"*.mkv";
    QStringList files = fileDir.entryList(nameFilters,QDir::Files|QDir::Readable,QDir::Name);

    foreach(QString const& arg, files)
    {
        QString str = strDir+"/"+arg;
        QUrl url(str);
        m_MediaPlayList->addMedia(url);
    }
    ui->listWidget_play->clear();   //清空ui播放列表
    ui->listWidget_play->insertItems(0,files);  //插入列表
    connect(ui->listWidget_play,&QListWidget::doubleClicked,this,&Widget::listWidget_doubleCliked);
}

//双击播放列表的视频
void Widget::listWidget_doubleCliked(const QModelIndex &index)
{
    int i = index.row();    //获取选中行
    m_MediaPlayList->setCurrentIndex(i);
    ui->btn_stop->setDisabled(false);
    m_VideoWidget->resize(ui->widget_video->size());
    disableBtn_next_back();
    btn_play_pause_clicked();

    connect(m_MediaPlayer,SIGNAL(durationChanged(qint64)),this,SLOT(getDuration(qint64)));
    connect(m_MediaPlayer,SIGNAL(positionChanged(qint64)),this,SLOT(getPosition(qint64)));
}


//播放/暂停
void Widget::btn_play_pause_clicked()
{
    if(m_MediaPlayList->mediaCount()==0)
    {
        return;
    }
    if(!playing)
    {
        m_State = QMediaPlayer::PlayingState;
        m_MediaPlayer->play();
        ui->btn_play->setIcon(QIcon(":/iamge/icon/pause.png"));
    }
    else
    {
        m_State = QMediaPlayer::PausedState;
        m_MediaPlayer->pause();
        ui->btn_play->setIcon(QIcon(":/iamge/icon/play.png"));
    }
    playing = !playing;
}

//停止播放
void Widget::btn_stop_clicked()
{
    m_State = QMediaPlayer::StoppedState;
    m_MediaPlayer->stop();
    playing = false;
    ui->btn_play->setIcon(QIcon(":/iamge/icon/play.png"));
}

//静音
void Widget::voice_play_mute_Cliced()
{
   if(!mute)
   {
       m_MediaPlayer->setVolume(0);
   }
   else
   {
       m_MediaPlayer->setVolume(50);
   }
   mute = !mute;
}

//音量
void Widget::voice_control_valueChanged(int value)
{
    m_MediaPlayer->setVolume(value);
}

//全屏
void Widget::btn_fullscreen_clicked()
{
    if(fullScreen)
    {
        move(width*0.2,height*0.2);
        resize(800,600);
    }
    else
    {
        showMaximized();
    }
    fullScreen = !fullScreen;
}

//快捷键
void Widget::keyPressEvent(QKeyEvent *event)
{
    if(Qt::Key_Escape==event->key())
    {
        if(fullScreen)
        {
            resize(800,600);
        }
    }

    if(Qt::Key_Space==event->key())
    {
        if(m_State == QMediaPlayer::PlayingState)
        {
            m_State = QMediaPlayer::PausedState;
            m_MediaPlayer->pause();
        }
        else if(m_State == QMediaPlayer::PausedState)
        {
            m_State = QMediaPlayer::PlayingState;
            m_MediaPlayer->play();
        }
    }
}

//双击
void Widget::mouseDoubleClickEvent(QMouseEvent *event)
{ 
    if(ui->widget_video->hasFocus())
    {
        if(fullScreen)
        {
            resize(800,600);
        }
        else
        {
            showMaximized();
        }
        fullScreen = !fullScreen;
    }
}

//鼠标单击
void Widget::mousePressEvent(QMouseEvent *event)
{
    if(ui->widget_video->hasFocus())
    {
        if(Qt::LeftButton==event->button())
        {
            btn_play_pause_clicked();
        }
    }
}

//计算上下视频是否生效
void Widget::disableBtn_next_back()
{
    int index = m_MediaPlayList->currentIndex();
    int num = m_MediaPlayList->mediaCount();
    if(index==0)
    {
        ui->btn_back->setDisabled(true);
    }
    else
    {
        ui->btn_back->setDisabled(false);
    }
    if(index == num-1)
    {
        ui->btn_next->setDisabled(true);
    }
    else
    {
        ui->btn_next->setDisabled(false);
    }
}

//上一视频
void Widget::btn_backV_clicked()
{
    m_MediaPlayList->previous();
    m_MediaPlayer->play();
    disableBtn_next_back();
}

//下一视频
void Widget::btn_nextV_clicked()
{
    m_MediaPlayList->next();
    m_MediaPlayer->play();
    disableBtn_next_back();
}

//总时长
void Widget::getDuration(qint64 playTime)
{
    playTime = m_MediaPlayer->duration();
    setget_MediaTime(playTime);
}

//当前播放时长
void Widget::getPosition(qint64 playTime)
{
    if(!m_SliderHover)
    {
        playTime = m_MediaPlayer->position();
        setget_CurrentTime(playTime);
    }
}

//设置总时长ui
void Widget::setget_MediaTime(qint64 mediaTime)
{
    mediaTime /= 1000;
    ui->slider_allTime->setMinimum(0);
    ui->slider_allTime->setMaximum(mediaTime);
    m_hour = mediaTime/3600;
    m_minute = (mediaTime - m_hour*3600)/60;
    m_second = mediaTime - m_hour*3600 - m_minute*60;

    QString time = QString("%1:%2:%3").arg(m_hour).arg(m_minute).arg(m_second);
    ui->label_allTime->setText(time);
}

//当前播放时间ui
void Widget::setget_CurrentTime(qint64 currentTime)
{
    currentTime /= 1000;
    setTimeSlider(currentTime);

    int h,m,s;
    h = currentTime/3600;
    m = (currentTime - h*3600)/60;
    s = currentTime - h*3600 - m*60;
    QString time = QString("%1:%2:%3").arg(h).arg(m).arg(s);
    ui->label_currentTime->setText(time);
}

//设置进度条
void Widget::setTimeSlider(qint64 playTime)
{
    if(!m_SliderHover)
    {
        ui->slider_allTime->setValue(playTime);
    }
}
