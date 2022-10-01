#include "dragmenu.h"


dragMenu::dragMenu(QWidget *parent) : QWidget(parent)
{

}

dragMenu::~dragMenu()
{

}

void dragMenu::mousePressEvent(QMouseEvent *event)
{

    if(event->button()==Qt::LeftButton)
    {
        m_bDrag=true;
        //记下鼠标起初位置
        mouseStartPoint = event->globalPos();
        //鼠标按下时计时，如果超时则是单击，否则双击
        emit mousePress();
    }
}

void dragMenu::mouseMoveEvent(QMouseEvent *event)
{
    if(m_bDrag)
    {
        QPoint distance = event->globalPos()-mouseStartPoint;
        emit mouseMove(distance);
    }
}

void dragMenu::mouseReleaseEvent(QMouseEvent *event)
{

    m_bDrag = false;
    emit mouseReleased();

}
