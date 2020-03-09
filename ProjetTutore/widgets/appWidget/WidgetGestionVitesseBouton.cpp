#include "WidgetGestionVitesseBouton.h"
#include <QtWidgets>

WidgetGestionVitesseBouton::WidgetGestionVitesseBouton()
{
        //set up du layout principal
        layPrinc= new QHBoxLayout();
        this->setLayout(layPrinc);

        //mise en place du bouton -
        QWidget *wButtMoins= new QWidget(this);
        QLayout *layButtMoins=new QHBoxLayout(wButtMoins);
        wButtMoins->setLayout(layButtMoins);

        layPrinc->addWidget(wButtMoins);

        boutonMoins = new QPushButton("-",this);
        layButtMoins->addWidget(boutonMoins);


        //mise en place de l'afficheur
        QWidget *wNombre= new QWidget(this);
        QLayout *layNombre=new QHBoxLayout(wNombre);
        wNombre->setLayout(layNombre);

        layPrinc->addWidget(wNombre);

        labelAffich = new QLabel(QString::number(getPas()),this);
        layNombre->addWidget(labelAffich);


        //mise en place du bouton +
        QWidget *wButtPlus= new QWidget(this);
        QLayout *layButtPlus=new QHBoxLayout(wButtPlus);
        wButtPlus->setLayout(layButtPlus);

        layPrinc->addWidget(wButtPlus);

        boutonPlus = new QPushButton("+",this);
        layButtPlus->addWidget(boutonPlus);


        //mise en place des connects
        QWidget::connect(boutonMoins,SIGNAL(clicked()),this,SLOT(decrement()) ) ;
        QWidget::connect(boutonPlus,SIGNAL(clicked()),this,SLOT(increment()) ) ;
}

void WidgetGestionVitesseBouton::increment(){
    setPas(getPas()+1);
    labelAffich->setText(QString::number(getPas()));
}

void WidgetGestionVitesseBouton::decrement(){
    if(getPas()==0){
        return;
    }
    setPas(getPas()-1);
    labelAffich->setText(QString::number(getPas()));
}
