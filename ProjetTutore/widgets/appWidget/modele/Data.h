#ifndef DATA_H
#define DATA_H
#include "Index.h"

class Data : public Index
{
public:
    Data(const Node& node);
    Data(const Data&);
    Data& operator=(const Data& data);


private:
    Type type;
};

#endif // DATA_H
