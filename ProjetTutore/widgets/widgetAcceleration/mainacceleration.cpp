#include "widgetacceleration.h"
#include <QLabel>
WidgetAcceleration::WidgetAcceleration(int largeur, int hauteur)
{

    //lafenetre = new QWidget();
    //this->resize(largeur,hauteur);

    mainx = new QVBoxLayout();
    this->setLayout(mainx);

    QWidget* wSubMainx = new QWidget;
    subMainx = new QHBoxLayout(wSubMainx);

    QWidget *wVitesse = new QWidget;
    QVBoxLayout* vitesse = new QVBoxLayout(wVitesse);
    QWidget *wTemps = new QWidget;
    QVBoxLayout* temps = new QVBoxLayout(wTemps);

    QLabel* vit = new QLabel("Vitesse à atteindre");
    QLabel* tmp = new QLabel("Temps d'accélération");

    timeValue = new QSpinBox();
    timeValue->setRange(0,1000);

    speedValue = new QLineEdit;
    speedValue->setInputMask("999");

    valid = new QPushButton("Valider");

    vitesse->addWidget(vit);
    vitesse->addWidget(speedValue);
    temps->addWidget(tmp);
    temps->addWidget(timeValue);
    subMainx->addWidget(wVitesse);
    subMainx->addWidget(wTemps);
    mainx->addWidget(wSubMainx);
    mainx->addWidget(valid);

}
