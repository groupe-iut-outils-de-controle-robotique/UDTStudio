#ifndef DATALECTURE_H
#define DATALECTURE_H
#include "Data.h"

class DataLecture: public Data
{
public:
    DataLecture();
    DataLecture(const Node& node): Data(node){}
    DataLecture(const DataLecture&);
    DataLecture& operator=(const DataLecture data);
    void/*mettre en place des metatype*/ requeteLecture();
};

#endif // DATALECTURE_H
