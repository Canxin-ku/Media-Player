#include "clickvideo.h"

ClickVideo::ClickVideo(QWidget *parent) :
    QWidget(parent)
{
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(mouseClick()));
    this->setMouseTracking(true);   //设置只要鼠标移动就可以监测事件
}

ClickVideo::~ClickVideo()
{

}

void ClickVideo::mouseMoveEvent(QMouseEvent *event)
{
    emit mouseMoving(event->globalPos());
}

//鼠标按下时计时，如果超时则是单击，否则双击
void ClickVideo::mousePressEvent(QMouseEvent *event)
{
    timer->start(300);
}

void ClickVideo::mouseDoubleClickEvent(QMouseEvent *event)
{
    timer->stop();
    emit doubleClicked();
}

void ClickVideo::mouseClick()
{
    timer->stop();
    emit singleClicked();
}
