#include "Maye.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    qDebug() << "你好visual studio";
    Maye window;
    window.show();
    return app.exec();
}
