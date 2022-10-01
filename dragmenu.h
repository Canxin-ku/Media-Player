#ifndef DRAGMENU_H
#define DRAGMENU_H

#include <QWidget>
#include <QDebug>
#include <QMouseEvent>

namespace Ui {
class dragMenu;
}

class dragMenu : public QWidget
{
    Q_OBJECT

public:
    explicit dragMenu(QWidget *parent = 0);
    ~dragMenu();

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);


signals:
    void mousePress();
    void mouseMove(QPoint pos);
    void mouseReleased();

private:
    bool m_bDrag = false;
    QPoint mouseStartPoint;
};

#endif // DRAGMENU_H
