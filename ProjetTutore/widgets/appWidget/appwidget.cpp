#include "appwidget.h"
#include "windowwidgetpopup.h"

AppWidget::AppWidget(int x, int y)
{
    this->resize(x,y);
    mainx = new QHBoxLayout();
    this->setLayout(mainx);

    pushAddWidget = new QPushButton("Add Widget",this);

    widgetTable = new  QVBoxLayout();

    mainx->addWidget(pushAddWidget,1);
    mainx->addLayout(widgetTable,7);

    QWidget::connect(pushAddWidget,SIGNAL(clicked()),this,SLOT(openPopup()));

}

void AppWidget::openPopup()
{
    WindowWidgetPopup *accel = new WindowWidgetPopup(300,600);
    accel->show();
}

