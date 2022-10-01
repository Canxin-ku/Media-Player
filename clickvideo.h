#ifndef CLICKVIDEO_H
#define CLICKVIDEO_H

#include <QWidget>
#include <QMouseEvent>
#include <QTimer>
#include <QDebug>

namespace Ui {
class ClickVideo;
}

class ClickVideo : public QWidget
{
    Q_OBJECT

public:
    explicit ClickVideo(QWidget *parent = 0);
    ~ClickVideo();

protected:
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseDoubleClickEvent(QMouseEvent *event);

signals:
    void singleClicked();
    void doubleClicked();
    void mouseMoving(QPoint pos);

private slots:
    void mouseClick();  //鼠标单击

private:
    QTimer *timer;
};

#endif // CLICKVIDEO_H
