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
        mouseStartPoint = event->globalPos();
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
