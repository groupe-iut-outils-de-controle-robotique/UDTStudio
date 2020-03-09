#include <QApplication>
#include "widgetvitessespinbox.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    WidgetVitesseSpinbox *accel = new WidgetVitesseSpinbox(320,200);

    accel->show();

    return app.exec();
}
