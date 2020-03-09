#include "WidgetGestionVitesseBouton.h"
#include "WidgetAllumerEteindreMoteur.h"
#include "WidgetVitesse.h"
#include "WidgetAcceleration.h"
#include <QApplication>
#include <QtWidgets>

int main(int argc, char* argv[])
{
    QApplication app(argc,argv);
    WidgetGestionVitesseBouton w1;
    w1.show();

    // Le programme s'est terminé subitement et jsp pk :/
    WidgetAllumerEteindreMoteur w2(true);
    w2.show();

    WidgetVitesse w3;
    w3.show();

    WidgetAcceleration w4(0);
    w4.show();

    return app.exec();
}
