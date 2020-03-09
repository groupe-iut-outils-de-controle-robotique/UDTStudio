#ifndef COMPOSITE_H
#define COMPOSITE_H
#include "Index.h"
#include <QList>
#include <QObject>


class Conteneur : public Index
{

public:
    Conteneur();
    Conteneur(const Node& node);
    Conteneur(const Conteneur&);
    Conteneur& operator=(const Conteneur&);
    void ajouter(const Index& composant);
    void retirer(const Index& composant);
    Index& getchildren(const int& indice);

private:
    QList<Index> children;
};

#endif // COMPOSITE_H
