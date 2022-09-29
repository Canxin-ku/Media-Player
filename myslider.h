#ifndef MYSLIDER_H
#define MYSLIDER_H

#include <QWidget>
#include <QSlider>
#include <QMouseEvent>
#include <QDebug>

class MySlider : public QSlider
{
    Q_OBJECT

public:
    explicit MySlider(QWidget *parent = 0);
    ~MySlider();

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
   // void mouseMoveEvent(QMouseEvent *event);

signals:
    void mousePress();
    void mouseRelease(int val);
};

#endif // MYSLIDER_H
