#include <QApplication>
#include "appwidget.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    AppWidget *accel = new AppWidget(1920,1080);

    accel->show();

    return app.exec();
}
