#include "Data.h"

Data::Data(const Node& node): Index(node)
{
    this->type = Index::getNode().getType();
}
