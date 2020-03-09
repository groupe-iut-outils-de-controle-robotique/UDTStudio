#ifndef DATALECTUREECRITURE_H
#define DATALECTUREECRITURE_H
#include "DataEcriture.h"
#include "DataLecture.h"

class DataLectureEcriture: public DataLecture, public DataEcriture
{
public:
    DataLectureEcriture(const Node& node): DataEcriture(node){}
    DataLectureEcriture(const DataLectureEcriture&);
    DataLectureEcriture& operator=(const DataLectureEcriture&);
};

#endif // DATALECTUREECRITURE_H
