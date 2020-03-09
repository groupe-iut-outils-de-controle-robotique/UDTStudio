#include "widgetvitessespinbox.h"
#include <QLabel>
WidgetVitesseSpinbox::WidgetVitesseSpinbox(int largeur, int hauteur)
{

    lafenetre = new QWidget();
    this->resize(largeur,hauteur);

    mainx = new QVBoxLayout();
    //this->setLayout(mainx);

    QWidget* wSubMainx = new QWidget;
    subMainx = new QHBoxLayout(wSubMainx);

    QWidget *wStepVBox = new QWidget;
    QVBoxLayout* stepVBox = new QVBoxLayout(wStepVBox);

    step = new QLineEdit;
    step->setInputMask("99");

    minus = new QPushButton("-");
    plus = new QPushButton("+");

    stepVBox->addWidget(new QLabel("Step") );
    stepVBox->addWidget(step);

    subMainx->addWidget(minus);
    subMainx->addWidget(wStepVBox);
    subMainx->addWidget(plus);

    mainx->addWidget(wSubMainx);
}
