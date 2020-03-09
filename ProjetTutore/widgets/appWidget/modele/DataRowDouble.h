#ifndef DATAROWDOUBLE_H
#define DATAROWDOUBLE_H
#include "DataRow.h"


class DataRowDouble : public DataRow
{
public:
    DataRowDouble();
    DataRowDouble(const double& drdouble);
    DataRowDouble(const DataRowDouble&);
    DataRowDouble& operator=(const DataRowDouble& drdouble);
};

#endif // DATAROWDOUBLE_H
