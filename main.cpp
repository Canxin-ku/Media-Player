#include "widget.h"
#include <QApplication>
#include <QFile>
#include <QTextStream>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QFile file(":/qss/myQss.qss");
    file.open(QIODevice::ReadOnly);
    app.setStyleSheet(file.readAll());

    Widget w;
    w.show();

    return app.exec();
}
