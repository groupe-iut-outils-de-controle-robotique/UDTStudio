#ifndef COMPOWIDGET_H
#define COMPOWIDGET_H
#include "WidgetCanOpen.h"
#include <QList>
#include <QObject>


class CompoWidget : public WidgetCanOpen
{

public:
    CompoWidget(Index object);
    void ajouter(WidgetCanOpen composant);
    void retirer(WidgetCanOpen composant);
    WidgetCanOpen getchildren(int indice);

private:
    QList<WidgetCanOpen> children;
};

#endif // COMPOWIDGET_H
