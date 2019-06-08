
#include <QRegularExpression>

#include "edsparser.h"

EdsParser::EdsParser(QString path)
{
    _edsFile = path;
}

/**
 * @brief parses an eds file and completes an object dictionary
 * @param object dictionary
 */
void EdsParser::parse(OD *od)
{
    bool ok;
    bool isSubIndex;
    uint16_t indexNumber;
    uint8_t accessType;
    uint16_t dataType;
    uint8_t objectType;
    uint8_t subNumber;
    QString accessString;
    QString parameterName;
    Index *index;
    SubIndex *subIndex;
    DataType *data;

    QSettings eds(_edsFile, QSettings::IniFormat);
    QRegularExpression reSub("([0-Z]{4})(sub[0-9]+)");
    QRegularExpression reIndex("([0-Z]{4})");

    foreach (const QString &group, eds.childGroups())
    {
        isSubIndex = false;
        accessType = 0;
        dataType = 0;
        objectType = 0;
        subNumber = 0;
        data = nullptr;

        QRegularExpressionMatch matchSub = reSub.match(group);
        QRegularExpressionMatch matchIndex = reIndex.match(group);

        if (matchSub.hasMatch())
        {
            QString matchedSub = matchSub.captured(1);
            index = od->index(matchedSub.toInt(&ok, 16));
            isSubIndex = true;
        }

        else if (matchIndex.hasMatch())
        {
            QString matchedIndex = matchIndex.captured(0);
            indexNumber = matchedIndex.toInt(&ok, 16);
        }

        else
            continue;

        eds.beginGroup(group);

        foreach (const QString &key, eds.allKeys())
        {
            // TODO check if start with 0x
            if (key == "AccessType")
            {
                accessString = eds.value(key).toString();

                if (accessString == "rw")
                    accessType = OD_ACCESS_READ_WRITE;

                else if (accessString == "wo")
                    accessType = OD_ACCESS_WRITE_ONLY;

                else if (accessString == "ro")
                    accessType = OD_ACCESS_READ_ONLY;

                else if (accessString == "const")
                    accessType = OD_ACCESS_CONST;
            }

            else if (key == "DataType")
                dataType = eds.value(key).toString().toInt(&ok, 16);

            else if (key == "ObjectType")
                objectType = eds.value(key).toString().toInt(&ok, 16);

            else if (key == "ParameterName")
                parameterName = eds.value(key).toString();

            else if (key == "SubNumber")
                subNumber = eds.value(key).toString().toInt(&ok, 10);
        }

        data = readData(eds);
        eds.endGroup();

        if (isSubIndex)
        {
            switch (index->objectType())
            {
            case OD_OBJECT_RECORD:
                subIndex = new SubIndex(dataType, objectType, accessType, parameterName);
                subIndex->addData(data);
                index->addSubIndex(subIndex);
                break;

            case OD_OBJECT_ARRAY:
                index->setDataType(dataType);
                index->setAccessType(accessType);
                index->addData(data);
                break;
            }
        }
        else
        {
            index = new Index(dataType, objectType, accessType, parameterName, indexNumber, subNumber);

            if (objectType == OD_OBJECT_VAR)
                index->addData(data);

            od->addIndex(index);
        }
    }
}

DataType* EdsParser::readData(const QSettings &eds) const
{
    bool ok;
    int16_t dataType = eds.value("DataType").toString().toShort(&ok, 16);

    QString dataString = eds.value("DefaultValue").toString();
    uint8_t base = 10;
    if (dataString.startsWith("0x", Qt::CaseInsensitive))
        base = 16;

    DataType *data = nullptr;
    switch(dataType)
    {
    case OD_TYPE_INTEGER8:
        data = new DataType(dataString.toShort(&ok, base));
        break;

    case OD_TYPE_INTEGER16:
        data = new DataType(dataString.toShort(&ok, base));
        break;

    case OD_TYPE_INTEGER32:
        data = new DataType(dataString.toInt(&ok, base));
        break;

    case OD_TYPE_INTEGER64:
        data = new DataType(dataString.toLong(&ok, base));
        break;

    case OD_TYPE_UNSIGNED8:
        data = new DataType(dataString.toInt(&ok, base));
        break;

    case OD_TYPE_UNSIGNED16:
        data = new DataType(dataString.toUShort(&ok, base));
        break;

    case OD_TYPE_UNSIGNED32:
        data = new DataType(dataString.toUInt(&ok, base));
        break;

    case OD_TYPE_UNSIGNED64:
        data = new DataType(dataString.toULong(&ok, base));
        break;

    case OD_TYPE_REAL32:
        data = new DataType(dataString.toFloat(&ok));
        break;

    case OD_TYPE_REAL64:
        data = new DataType(dataString.toDouble(&ok));
        break;

    case OD_TYPE_VISIBLE_STRING:
        data = new DataType(dataString);
        break;
    }

    return data;
}
