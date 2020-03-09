#include "WindowWidgetPopup.h"

WindowWidgetPopup::WindowWidgetPopup(int x, int y)
{
    this->resize(x,y);
    mainx = new QVBoxLayout;
    this->setLayout(mainx);

    listLayout = new QHBoxLayout;
    leavingButtons = new QHBoxLayout;

    objectListLayout = new QVBoxLayout;
    widgetListLayout = new QVBoxLayout;

    okButton = new QPushButton("Ok");
    cancelButton = new QPushButton("Cancel");

    mainx->addLayout(listLayout,7);
    mainx->addLayout(leavingButtons,1);

    listLayout->addLayout(objectListLayout);
    listLayout->addLayout(widgetListLayout);

    leavingButtons->addWidget(okButton);
    leavingButtons->addWidget(cancelButton);


}
