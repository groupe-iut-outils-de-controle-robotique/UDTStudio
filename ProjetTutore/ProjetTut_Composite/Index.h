#ifndef INDEX_H
#define INDEX_H
#include "Node.h"
#include "Type.h"
#include <QObject>
#include <QList>


class Index : public QObject
{
    Q_OBJECT
    Q_PROPERTY("node" Node GETTER Node getNode() SETTER void setNode(const Node&) SIGNAL changed )

public:
    Index();
    Index(const Node& node){
        this->node=node;
    }

    Index(const Index& index)
        :Index(index.node)
    {

    }
    Index& operator=(const Index& index);
    virtual ~Index();

    void ajouter(Index composant);

    void retirer(Index composant);

    Index getchildren(int indice);

    const Node& getNode() const{
        return this->node;
    }

    void setNode(const Node& node){
        this->node = node;
        changed();
    }

private:
    QList<Index> children;
    Node node;

signals:
    void changed();

};




#endif // INDEX_H
