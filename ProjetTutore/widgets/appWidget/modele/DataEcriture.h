#ifndef DATAECRITURE_H
#define DATAECRITURE_H
#include "Data.h"

class DataEcriture: public Data
{
public:
    DataEcriture(const Node& node): Data(node){}
    DataEcriture(const DataEcriture&);
    DataEcriture& operator=(const DataEcriture data);
    void requeteEcriture();
};

#endif // DATAECRITURE_H
