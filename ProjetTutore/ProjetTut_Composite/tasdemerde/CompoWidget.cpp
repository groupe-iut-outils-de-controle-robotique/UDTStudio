#include "CompoWidget.h"

CompoWidget::CompoWidget(Index object)
{
    WidgetCanOpen::setObject(object);
}

void CompoWidget::ajouter(WidgetCanOpen composant){
    children.append(composant);
}

void CompoWidget::retirer(WidgetCanOpen composant){
    children.removeOne(composant);
}

WidgetCanOpen CompoWidget::getchildren(int indice){
    return children[indice];
}
