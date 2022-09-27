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
    void on_btn_open_clicked(); //
    
    void on_btn_play_clicked(); //
    
    void on_btn_pasuse_clicked();   //
    
    void on_btn_stop_clicked(); //
    
    void on_voice_control_valueChanged(int value);  //
    
    void on_btn_fullscreen_clicked();   //
    
    void getDuration(qint64 playTime);  //

    void getPosition(qint64 playTime);  //

    void on_btn_backV_clicked();    //

    void on_btn_nextV_clicked();    //

    void on_listWidget_doubleCliked(const QModelIndex &index);

protected:
    void resizeEvent(QResizeEvent* event);

    void keyPressEvent(QKeyEvent* event);

    void mousePressEvent(QMouseEvent* event);

    void mouseDoubleClickEvent(QMouseEvent* event);

private:
    Ui::Widget *ui;
    QStringList m_StrList;    //文件列表
    QMediaPlayer *m_MediaPlayer;  //播放器
    QVideoWidget *m_VideoWidget;    //播放窗口
    QMediaPlaylist *m_MediaPlayList;    //播放列表
    QMediaPlayer::State m_State;  //播放状态
    int m_hour; //
    int m_minute;   //
    int m_second;   //
    bool m_SliderHover; //
    int m_Silder_val;   //
};

#endif // WIDGET_H
