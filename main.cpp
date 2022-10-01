#include "widget.h"
#include <QApplication>
#include <QFile>
#include <QTextStream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFile file(":/qss/qss/myQss.qss");
    file.open(QIODevice::ReadOnly);
    a.setStyleSheet(file.readAll());

    Widget w;
    w.show();

    return a.exec();
}
