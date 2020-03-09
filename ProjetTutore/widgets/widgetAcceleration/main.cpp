#include <QApplication>
#include "widgetacceleration.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    WidgetAcceleration *accel = new WidgetAcceleration(320,200);

    accel->show();

    return app.exec();
}
