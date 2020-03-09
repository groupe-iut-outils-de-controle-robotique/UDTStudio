#include "Conteneur.h"
//#include <QList>
//#include "QLinkedList"

Conteneur::Conteneur(const Node& node)
{
    Index::setNode(node);
}

    void Conteneur::ajouter(const Index& composant){
        children.append(composant);
    }

    void Conteneur::retirer(const Index& composant){
        children.removeOne(composant);
    }

    Index& Conteneur::getchildren(const int& indice){
        return children[indice];
    }

