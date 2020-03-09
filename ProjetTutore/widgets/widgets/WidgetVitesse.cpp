#include "WidgetVitesse.h"
#include <QtWidgets>

WidgetVitesse::WidgetVitesse()
{
    //set up du layout principal
    layPrinc= new QHBoxLayout();
    this->setLayout(layPrinc);

    //mise en place du label pour voir la vitesse
    QWidget *wLabelVitesse=new QWidget(this);
    QHBoxLayout *layLabelVitesse=new QHBoxLayout(wLabelVitesse);
    wLabelVitesse->setLayout(layLabelVitesse);

    layPrinc->addWidget(wLabelVitesse);

    labelVitesse=new QLabel(QString::number(vitesse),this);
    layLabelVitesse->addWidget(labelVitesse);

    //mise en place de la combo box
    QWidget *wComboBox=new QWidget(this);
    QLayout *layComboBox=new QHBoxLayout(wComboBox);
    wComboBox->setLayout(layComboBox);

    layPrinc->addWidget(wComboBox);

    comboBoxListe=new QComboBox(this);
    comboBoxListe->addItem("tour/secondes");
    comboBoxListe->addItem("tour/minutes");
    comboBoxListe->addItem("tour/heures");
    layLabelVitesse->addWidget(comboBoxListe);

    //mise en place des connects
    QWidget::connect(comboBoxListe,SIGNAL(currentIndexChanged(int)),this,SLOT(changeVitesse(int)));
}

void WidgetVitesse::changeVitesse(int index){
    labelVitesse->clear();

    //faire une classe convertisseur a faire par les gens du modèle
    switch(index){
        case 0: labelVitesse->setText(QString::number(vitesse)); break;
        case 1: labelVitesse->setText(QString::number(vitesse/60)); break;
        case 2: labelVitesse->setText(QString::number(vitesse/3600)); break;
    }
}

