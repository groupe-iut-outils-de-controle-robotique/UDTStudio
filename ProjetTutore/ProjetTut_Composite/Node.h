#ifndef NODE_H
#define NODE_H
#include "Bus.h"
#include "Type.h"
#include <QObject>


class Node : public QObject
{
    Q_OBJECT
public:
    Node();
    Node(const Node&);
    Node& operator=(const Node& node);
    ~Node();
    Type& getType();

private:
    Bus bus;
};

#endif // NODE_H
