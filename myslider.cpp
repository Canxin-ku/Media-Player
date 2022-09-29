#include "myslider.h"

MySlider::MySlider(QWidget *parent) : QSlider(parent)
{

}

MySlider::~MySlider()
{

}

void MySlider::mousePressEvent(QMouseEvent *event)
{
    QSlider::mousePressEvent(event);
    emit mousePress();    
}

void MySlider::mouseReleaseEvent(QMouseEvent *event)
{
    QSlider::mouseReleaseEvent(event);
    //获取鼠标相对于slider的位置
    int relativePos = event->pos().x();
    //判断鼠标是否脱离进度条范围
    if(event->pos().y()>this->height()||event->pos().y()<0)
    {
        qDebug()<<"超出进度条范围";
        emit mouseRelease(-1000);
        return;
    }
    //百分比
    double persent = relativePos*1.0 / this->width();

    int value = persent * this->maximum();
    qDebug()<<"进度："<<value;
    emit mouseRelease(value);
}

//void MySlider::mouseMoveEvent(QMouseEvent *event)
//{
//    if(event->pos().y()>this->pos().y()+this->height()||event->pos().y()<this->pos().y())
//    {
//        return;
//    }
//}
