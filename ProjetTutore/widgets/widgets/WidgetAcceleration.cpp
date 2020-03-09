#include "WidgetAcceleration.h"
#include "WidgetGestionVitesseBouton.h"
#include <QtWidgets>
#include <QLabel>

WidgetAcceleration::WidgetAcceleration(int vitesse)
{
    setVitesse(vitesse);

    //set up du layout principal
    layPrinc= new QVBoxLayout();
    this->setLayout(layPrinc);

    QWidget* wSubMainx = new QWidget(this);
    subMainx = new QHBoxLayout(wSubMainx);

    QWidget *wVitesse = new QWidget(this);
    QVBoxLayout* layVitesse = new QVBoxLayout(wVitesse);
    QWidget *wTemps = new QWidget(this);
    QVBoxLayout* temps = new QVBoxLayout(wTemps);

    QLabel* vit = new QLabel("Vitesse à atteindre");
    QLabel* tmp = new QLabel("Temps d'accélération");

    timeValue = new QSpinBox(this);
    timeValue->setRange(0,1000);

    speedValue = new QLineEdit(this);
    speedValue->setInputMask("999");

    valid = new QPushButton("Valider");

    layVitesse->addWidget(vit);
    layVitesse->addWidget(speedValue);
    temps->addWidget(tmp);
    temps->addWidget(timeValue);
    subMainx->addWidget(wVitesse);
    subMainx->addWidget(wTemps);
    layPrinc->addWidget(wSubMainx);
    layPrinc->addWidget(valid);

    //speedValue->setText(WigetCanOpen.vitesse)

    //QWidget::connect(valid,SIGNAL(clicked()),this,SLOT(switchEtat()));
}
