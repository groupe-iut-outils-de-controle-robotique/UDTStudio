#ifndef WIDGETCANOPEN_H
#define WIDGETCANOPEN_H
#include "Index.h"
#include <QObject>


class WidgetCanOpen : public QObject
{
    Q_OBJECT

public:
    WidgetCanOpen();
    WidgetCanOpen(const Index& object){
        this->object = object;
    }

    WidgetCanOpen(const WidgetCanOpen& widget)
        :WidgetCanOpen(widget.object)
    {
    }

    WidgetCanOpen& operator=(const WidgetCanOpen& widget);
    virtual ~WidgetCanOpen();
    void ajouter(WidgetCanOpen composant);
    void retirer(WidgetCanOpen composant);
    WidgetCanOpen getchildren(int indice);
    Index getObject();
    void setObject(Index object);

private:
    Index object;
    TypeWid type;
};
#endif // WIDGETCANOPEN_H
