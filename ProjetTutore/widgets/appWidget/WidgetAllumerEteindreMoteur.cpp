#include "WidgetAllumerEteindreMoteur.h"
#include <QtWidgets>

WidgetAllumerEteindreMoteur::WidgetAllumerEteindreMoteur(bool etat)
{
    //set up du layout principal
    layPrinc= new QHBoxLayout(this);
    this->setLayout(layPrinc);

    //mise en place du bouton on off
    QWidget *wButtAllumeEteints= new QWidget(this);
    QLayout *layButtAllumeEteints=new QHBoxLayout(wButtAllumeEteints);
    wButtAllumeEteints->setLayout(layButtAllumeEteints);

    layPrinc->addWidget(wButtAllumeEteints);

    boutonOnOff = new QRadioButton(this);
    layButtAllumeEteints->addWidget(boutonOnOff);

    //mise en place du label
    QWidget *wLabelAllumeEteints= new QWidget(this);
    QLayout *layLabelAllumeEteints=new QHBoxLayout(wLabelAllumeEteints);
    wLabelAllumeEteints->setLayout(layLabelAllumeEteints);

    layPrinc->addWidget(wLabelAllumeEteints);

    labelOnOff = new QLabel("Moteur éteint",this);
    layLabelAllumeEteints->addWidget(labelOnOff);

    //mise en place des connects
    QWidget::connect(boutonOnOff,SIGNAL(clicked()),this,SLOT(switchEtat()));
    if(etat){
        boutonOnOff->click();
    }
}

void WidgetAllumerEteindreMoteur::switchEtat(){
    if(getEtat()){
        setEtat(false);
        labelOnOff->setText("Moteur éteint");
    }
    else{
        setEtat(true);
        labelOnOff->setText("Moteur allumé");
    }
}
