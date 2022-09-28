#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QVideoWidget>
#include <QString>
#include <QDebug>
#include <QResizeEvent>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QFileDialog>
#include <QMap>


namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);

    void setget_MediaTime(qint64 mediaTime);    //

    void setget_CurrentTime(qint64 currentTime);    //

    void setTimeSlider(qint64 playTime);    //

    ~Widget();

private slots:
    void btn_open_clicked(); //选文件
    
    void btn_play_pause_clicked(); //播放
    
    void btn_stop_clicked(); //停止
    
    void voice_control_valueChanged(int value);  //音量变化

    void voice_play_mute_Cliced();
    
    void btn_fullscreen_clicked();   //全屏

    void getDuration(qint64 playTime);  //媒体长度

    void getPosition(qint64 playTime);  //媒体播放位置

    void btn_backV_clicked();    //上一个视频

    void btn_nextV_clicked();    //下一个视频

    void listWidget_doubleCliked(const QModelIndex &index);  //播放列表中选择

protected:
    void resizeEvent(QResizeEvent *event); //播放窗口大小

    void keyPressEvent(QKeyEvent* event);   //按键

    void mousePressEvent(QMouseEvent* event);   //鼠标按下

    void mouseDoubleClickEvent(QMouseEvent *event); //双击鼠标

    void disableBtn_next_back();

private:
    Ui::Widget *ui;
    QStringList m_StrList;    //文件列表
    QMediaPlayer *m_MediaPlayer;  //播放器
    QVideoWidget *m_VideoWidget;    //播放窗口
    QMediaPlaylist *m_MediaPlayList;    //播放列表
    QMediaPlayer::State m_State;  //播放状态
    int m_hour; //  时
    int m_minute;   //分
    int m_second;   //秒
    int m_Silder_val;   //进度条值
    bool m_SliderHover; //是否选定进度条
    bool mute = false;  //是否静音
    bool playing = false;   //是否播放
    bool fullScreen = false;
    int width;
    int height;
};

#endif // WIDGET_H
