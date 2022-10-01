#include "widget.h"
#include "ui_widget.h"
#include <QScreen>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setMouseTracking(true);
    this->setWindowFlags(Qt::Window|Qt::FramelessWindowHint);
    width = QGuiApplication::primaryScreen()->geometry().width();   //获取当前屏幕宽
    height = QGuiApplication::primaryScreen()->geometry().height(); //获取当前屏幕高

    setWindowTitle("播放器");
    move(width*0.2,height*0.2);
    m_MediaPlayer = new QMediaPlayer;   //播放器
    m_VideoWidget = new QVideoWidget(ui->widget_video);   //播放窗口并赋值到UI上
    m_MediaPlayList = new QMediaPlaylist;   //播放列表
    fullScreenTimer = new QTimer(this); //鼠标移动结束计时器

    m_MediaPlayer->setPlaylist(m_MediaPlayList);    //播放器添加播放列表
    m_MediaPlayer->setVideoOutput(m_VideoWidget);   //输出到播放窗口
    m_MediaPlayer->setVolume(50);   //初始化音量为50

    //按键可用
    ui->btn_stop->setDisabled(true);
    ui->btn_next->setDisabled(true);
    ui->btn_back->setDisabled(true);
    ui->btn_icon_appName->setDisabled(true);    //菜单栏标题按钮设置为不可用

    //设置焦点
    ui->btn_back->setFocusPolicy(Qt::NoFocus);
    ui->btn_filePath->setFocusPolicy(Qt::NoFocus);
    ui->btn_fullScreen->setFocusPolicy(Qt::NoFocus);
    ui->btn_next->setFocusPolicy(Qt::NoFocus);
    ui->btn_play->setFocusPolicy(Qt::NoFocus);
    ui->btn_stop->setFocusPolicy(Qt::NoFocus);
    ui->btn_volume->setFocusPolicy(Qt::NoFocus);
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

    connect(m_MediaPlayList,&QMediaPlaylist::currentIndexChanged,this,&Widget::name_changed);
    connect(fullScreenTimer,SIGNAL(timeout()),this,SLOT(fullScreen_mouseMoveEnd_event()));
    connect(ui->widget_video,SIGNAL(singleClicked()),this,SLOT(mouseSingleClick()));
    connect(ui->widget_video,SIGNAL(doubleClicked()),this,SLOT(mouseDoubleClick()));
    connect(ui->widget_video,SIGNAL(mouseMoving(QPoint)),this,SLOT(fullScreen_mouseMove_event(QPoint)));

    connect(ui->slider_allTime,SIGNAL(mousePress()),this,SLOT(slider_time_pressed()));
    connect(ui->slider_allTime,SIGNAL(mouseRelease(int)),this,SLOT(slider_time_released(int)));
    connect(ui->slider_volume,SIGNAL(mousePress()),this,SLOT(slider_volume_pressed()));
    connect(ui->slider_volume,SIGNAL(mouseRelease(int)),this,SLOT(slider_Volume_released(int)));
    connect(ui->widget_menu,SIGNAL(mousePress()),this,SLOT(dragPress()));
    connect(ui->widget_menu,SIGNAL(mouseMove(QPoint)),this,SLOT(dragMove(QPoint)));
    connect(ui->widget_menu,SIGNAL(mouseReleased()),this,SLOT(dragReleased()));
    connect(ui->btn_min,&QPushButton::clicked,this,&Widget::showMinimized);
    connect(ui->btn_max,&QPushButton::clicked,this,&Widget::switch_maxMinWin);
    connect(ui->btn_close,&QPushButton::clicked,this,&Widget::close);

    //控件可见
    ui->label_allTime->setVisible(false);
    ui->label_currentTime->setVisible(false);
    ui->label_slash->setVisible(false);
    ui->slider_allTime->setVisible(false);
    ui->btn_fullScreen->setVisible(false);
    ui->label_title->setVisible(false);


    //初始化时一些值
    ui->btn_icon_appName->setText(tr("同步播放器"));
    ui->slider_volume->setValue(50);
    m_MediaPlayer->setVolume(50);
    ui->btn_play->setWhatsThis("style1");
    ui->btn_volume->setWhatsThis("style1");
    ui->btn_fullScreen->setWhatsThis("style1");
    ui->btn_max->setWhatsThis("style1");
    ui->widget_video->setMouseTracking(true);
    m_VideoWidget->setMouseTracking(true);
}

Widget::~Widget()
{
    delete ui;
}

//切换最大最小化
void Widget::switch_maxMinWin()
{
    if(ismaxsize)
    {
        showNormal();
        this->resize(winSize);
        this->move(winTopleft);      
        ui->btn_max->setWhatsThis("style1");
        refreshUI(ui->btn_max);
    }
    else
    {
        winTopleft = this->frameGeometry().topLeft();
        winSize = this->size();
        showMaximized();
        ui->btn_max->setWhatsThis("style2");
        refreshUI(ui->btn_max);
    }
    ismaxsize = !ismaxsize;
}

//窗口拖动
void Widget::dragPress()
{
    isDrag=true;
    winTopleft = this->frameGeometry().topLeft();
}

void Widget::dragMove(QPoint distance)
{
    this->move(distance+winTopleft);
}

void Widget::dragReleased()
{
    isDrag=false;
}

//音量进度条
void Widget::slider_volume_pressed()
{
    m_SliderHover = true;
    volume_beg_val = ui->slider_volume->value();
}

void Widget::slider_Volume_released(int value)
{
    m_SliderHover = false;
    qDebug()<<value;
    if(-1000!=value)
    {
        volume_beg_val = value;
        if(volume_beg_val<=0)
        {
            mute = true;
            volume_beg_val = 0;
            ui->btn_volume->setWhatsThis("style2");
            refreshUI(ui->btn_volume);
        }
        else
        {
            if(mute)
            {
                ui->btn_volume->setWhatsThis("style1");
                refreshUI(ui->btn_volume);
            }
            if(volume_beg_val > 100)
            {
                volume_beg_val = 100;
            }
        }
        m_MediaPlayer->setVolume(volume_beg_val);
    }
    ui->slider_volume->setValue(volume_beg_val);
}

//时间进度按下
void Widget::slider_time_pressed()
{
    //暂停
    m_MediaPlayer->pause();
    m_SliderHover = true;
    btn_play_pause_clicked();
}

//时间进度松开
void Widget::slider_time_released(int value)
{
    //调整进度并继续播放
    m_SliderHover=false;
    if(-1000!=value)
    {
        m_MediaPlayer->setPosition(value*1000);
        setget_CurrentTime(value);
    }
    btn_play_pause_clicked();
}

//更改媒体名字
void Widget::name_changed()
{
    int getindex = m_MediaPlayList->currentIndex();
    QString name = files.at(getindex);
    ui->label_title->setText(name);
    ui->label_mediaName->setText(name);
    ui->listWidget_play->setCurrentRow(getindex);
}

//设置播放窗口大小
void Widget::resizeEvent(QResizeEvent *event)
{
    QSize changeSize;
    if(!fullScreen)
    {
        changeSize = QSize(ui->widget_video->size().width(),ui->widget_video->size().height()-ui->widget_operate->size().height());
    }
    else
    {
        changeSize=ui->widget_video->size();
    }
    m_VideoWidget->resize(changeSize);
    ui->label_title->resize(ui->widget_video->size().width(),ui->label_title->size().height());
}

//选取文件夹并扫描该文件夹下的视频文件
void Widget::btn_open_clicked()
{
    m_MediaPlayList->clear();   //播放器的播放列表清空
    m_StrList.clear();          //列表变量清空
    files.clear();

    QDir fileDir = QFileDialog::getExistingDirectory(this,"保存","F:/5343");    //选择文件夹
    QStringList nameFilters;
    nameFilters<<"*.mp4"<<"*.avi"<<"*.mkv"<<"*.mp3"; //设置文件搜索规则
    QString strDir = fileDir.absolutePath();    //获取文件夹绝对路径
    files = fileDir.entryList(nameFilters,QDir::Files|QDir::Readable,QDir::Name);   //获取文件下符合规则的文件

    foreach(QString const& arg, files)
    {
        QString str = strDir+"/"+arg;   //拼合成路径
        QUrl url(str);  //转为url
        m_MediaPlayList->addMedia(url);
    }
    ui->listWidget_play->clear();   //清空ui播放列表
    ui->listWidget_play->insertItems(0,files);  //插入列表
    connect(ui->listWidget_play,&QListWidget::doubleClicked,this,&Widget::listWidget_doubleCliked);
    connect(m_MediaPlayer,SIGNAL(durationChanged(qint64)),this,SLOT(getDuration(qint64)));
    connect(m_MediaPlayer,SIGNAL(positionChanged(qint64)),this,SLOT(getPosition(qint64)));
    connect(m_MediaPlayer,SIGNAL(mediaChanged(QMediaContent)),this,SLOT(name_changed()));
}

//双击播放列表的视频
void Widget::listWidget_doubleCliked(const QModelIndex &index)
{
    int i = index.row();    //获取选中行
    m_MediaPlayList->setCurrentIndex(i);    //把当前视频放在播放列表首位
    ui->btn_stop->setDisabled(false);   //停止键可用
    m_VideoWidget->resize(ui->widget_video->size());    //调整视频控件大小
    m_MediaPlayer->play();
    disableBtn_next_back(); //设置上下视频可用性

    //进度时间可见性
    ui->label_allTime->setVisible(true);
    ui->label_currentTime->setVisible(true);
    ui->label_slash->setVisible(true);
    ui->slider_allTime->setVisible(true);
    ui->btn_fullScreen->setVisible(true);
    ui->label_title->raise();
    ui->widget_operate->raise();
}

//播放/暂停
void Widget::btn_play_pause_clicked()
{
    if(m_MediaPlayList->mediaCount()==0)
    {
        return;
    }

    if(m_MediaPlayer->state() == QMediaPlayer::StoppedState)
    {
        m_MediaPlayer->play();
        disableBtn_next_back();
    }
    else
    {
        if(!playing)
        {
            m_State = QMediaPlayer::PlayingState;
            m_MediaPlayer->play();
            ui->btn_play->setWhatsThis("style2");
        }
        else
        {
            m_State = QMediaPlayer::PausedState;
            m_MediaPlayer->pause();
            ui->btn_play->setWhatsThis("style1");
        }
        refreshUI(ui->btn_play);
        playing = !playing;
    }

}

//停止播放
void Widget::btn_stop_clicked()
{
    ui->btn_stop->setDisabled(true);    //停止键不可用
    m_State = QMediaPlayer::StoppedState;   //设置状态
    m_MediaPlayer->stop();  //停止播放
    //设置ui
    ui->btn_play->setIcon(QIcon(":/image/icon/play.png"));
    playing = false;

    ui->label_allTime->setVisible(false);
    ui->label_currentTime->setVisible(false);
    ui->label_slash->setVisible(false);
    ui->slider_allTime->setVisible(false);
    ui->btn_fullScreen->setVisible(false);
}

//静音
void Widget::voice_play_mute_Cliced()
{
   if(!mute)
   {
       volume_beg_val = m_MediaPlayer->volume();
       m_MediaPlayer->setVolume(0);
       ui->btn_volume->setWhatsThis("style2");
       ui->slider_volume->setValue(0);
   }
   else
   {
       if(volume_beg_val==0)
       {
           volume_beg_val = 50;
       }
       m_MediaPlayer->setVolume(volume_beg_val);
       ui->btn_volume->setWhatsThis("style1");
       ui->slider_volume->setValue(volume_beg_val);
   }
   refreshUI(ui->btn_volume);
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
    ui_fullScreen_set();
}

//快捷键
void Widget::keyPressEvent(QKeyEvent *event)
{
    if(!m_SliderHover&&!isDrag)
    {
        if(Qt::Key_Escape==event->key())    //退出全屏
        {
            if(fullScreen)
            {
                ui_fullScreen_set();
            }
        }

        if(Qt::Key_Space==event->key()) //空格-暂停播放
        {
            btn_play_pause_clicked();
        }

        if(Qt::Key_Left==event->key())  //左方向键
        {
            qint64 currentTime = m_MediaPlayer->position()/1000;
            qint64 backPos = currentTime - 5;
            if(backPos<0)
            {
                backPos=0;
            }
            m_MediaPlayer->setPosition(backPos*1000);
            setget_CurrentTime(backPos);
        }

        if(Qt::Key_Right==event->key())
        {
            qint64 currentTime = m_MediaPlayer->position()/1000;
            qint64 nextPos = currentTime + 5;
            if(nextPos>=duration)
            {
                btn_stop_clicked();
            }
            m_MediaPlayer->setPosition(nextPos*1000);
            setget_CurrentTime(nextPos);
        }

        if(Qt::Key_Up==event->key())
        {
            int num = m_MediaPlayer->volume();
            if(num==100)
            {
                return;
            }
            else if(num==0)
            {
                ui->btn_volume->setWhatsThis("style1");
                refreshUI(ui->btn_volume);
                mute = false;
            }
            num += 5;
            if(num>100)
            {
                num=100;
            }
            m_MediaPlayer->setVolume(num);
            ui->slider_volume->setValue(num);
        }

        if(Qt::Key_Down==event->key())
        {
            int num = m_MediaPlayer->volume();
            num -= 5;
            if(num<=0)
            {
                mute = true;
                num = 0;
                ui->btn_volume->setWhatsThis("style2");
                refreshUI(ui->btn_volume);
            }
            m_MediaPlayer->setVolume(num);
            ui->slider_volume->setValue(num);
        }
    }
}

//单击事件
void Widget::mouseSingleClick()
{
    if(m_SliderHover)
    {
        return;
    }
    btn_play_pause_clicked();

}


//双击事件
void Widget::mouseDoubleClick()
{ 
    if(m_SliderHover)
    {
        return;
    }

    ui_fullScreen_set();

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

    playing = true;
    m_State = QMediaPlayer::PlayingState;

    ui->btn_stop->setDisabled(false);
    ui->btn_play->setWhatsThis("style2");
    refreshUI(ui->btn_play);
    ui->label_allTime->setVisible(true);
    ui->label_currentTime->setVisible(true);
    ui->label_slash->setVisible(true);
    ui->slider_allTime->setVisible(true);
    ui->btn_fullScreen->setVisible(true);
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
    playTime = m_MediaPlayer->duration()/1000;
    setget_MediaTime(playTime);
}

//当前播放时长
void Widget::getPosition(qint64 playTime)
{
    if(!m_SliderHover)
    {
        playTime = m_MediaPlayer->position()/1000;
        setget_CurrentTime(playTime);
    }
}

//设置总时长ui
void Widget::setget_MediaTime(qint64 mediaTime)
{
    duration = mediaTime;
    ui->slider_allTime->setMinimum(0);
    ui->slider_allTime->setMaximum(duration);
    m_hour = mediaTime/3600;
    m_minute = (mediaTime - m_hour*3600)/60;
    m_second = mediaTime - m_hour*3600 - m_minute*60;

    QString time = QString("%1:%2:%3").arg(m_hour).arg(m_minute).arg(m_second);
    ui->label_allTime->setText(time);
}

//当前播放时间ui
void Widget::setget_CurrentTime(qint64 currentTime)
{
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

//更新控件
void Widget::refreshUI(QWidget *widget)
{
    style()->unpolish(widget);
    style()->polish(widget);
    widget->repaint();
}

//全屏操作
void Widget::ui_fullScreen_set()
{
    ui->label_title->setVisible(fullScreen);
    ui->widget_tab->setVisible(fullScreen);
    ui->widget_menu->setVisible(fullScreen);
    ui->widget_operate->setVisible(fullScreen);
    ui->widget_video->setCursor(Qt::BlankCursor);//隐藏指针

    fullScreen = !fullScreen;
    if(!fullScreen)
    {
        ui->btn_fullScreen->setWhatsThis("style1");
        showNormal();
        if(ismaxsize)
        {
            showMaximized();
        }
        else
        {

            resize(800,600);
        }
    }
    else
    {
        ui->btn_fullScreen->setWhatsThis("style2");
        showFullScreen();
    }
    refreshUI(ui->btn_fullScreen);
}

void Widget::fullScreen_mouseMove_event(QPoint pos)
{
    //全屏情况下只要鼠标在移动就显示标题和操作栏,并且刷新timer
    if(fullScreen)
    {
        fullScreen_mousePos = pos;
        if(fullScreenTimer->isActive())
        {
            fullScreenTimer->stop();
            fullScreenTimer->start(3000);
        }
        else
        {
            fullScreenTimer->start(3000);
        }
        if(!isMoveShow)
        {
            ui->label_title->setVisible(fullScreen);
            ui->widget_operate->setVisible(fullScreen);
            ui->widget_video->setCursor(Qt::ArrowCursor);
            isMoveShow = true;
        }
    }
}

void Widget::fullScreen_mouseMoveEnd_event()
{
    qDebug()<<"结束鼠标位置："<<fullScreen_mousePos;
    fullScreenTimer->stop();
    //若是一段时间内鼠标没动但是在操作栏范围内，则继续刷新timer,或者正在调整进度条
    QRect com = QRect(0,height-ui->widget_operate->height(),ui->widget_operate->width(),ui->widget_operate->height());  //计算操作栏Rect
    //qDebug()<<com<<"  "<<fullScreen_mousePos;
    if(com.contains(fullScreen_mousePos)||m_SliderHover)
    {
        fullScreenTimer->start(3000);   //重新计算timer
    }
    else
    {
        isMoveShow = false;
        ui->label_title->setVisible(false);
        ui->widget_operate->setVisible(false);
        ui->widget_video->setCursor(Qt::BlankCursor);//隐藏指针
    }
}
