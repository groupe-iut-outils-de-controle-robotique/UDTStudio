﻿/**
 ** This file is part of the UDTStudio project.
 ** Copyright 2019 UniSwarm sebastien.caux@uniswarm.eu
 **
 ** This program is free software: you can redistribute it and/or modify
 ** it under the terms of the GNU General Public License as published by
 ** the Free Software Foundation, either version 3 of the License, or
 ** (at your option) any later version.
 **
 ** This program is distributed in the hope that it will be useful,
 ** but WITHOUT ANY WARRANTY; without even the implied warranty of
 ** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 ** GNU General Public License for more details.
 **
 ** You should have received a copy of the GNU General Public License
 ** along with this program. If not, see <http://www.gnu.org/licenses/>.
 **/

#ifndef SUBINDEX_H
#define SUBINDEX_H

#include "od_global.h"

#include<QList>
#include<QString>

class OD_EXPORT SubIndex
{
public:
    SubIndex(const uint8_t subIndex);
    SubIndex(const SubIndex &other);
    ~SubIndex();

    // ============== Access type =================
     enum Access
     {
         READ = 0x01,
         WRITE = 0x02,
         TPDO = 0x04,
         RPDO = 0x08
     };

     enum Limit
     {
         LOW = 0x01,
         HIGH = 0x02
     };

    uint8_t accessType() const;
    void setAccessType(const uint8_t &accessType);

    uint8_t subIndex() const;
    void setSubIndex(const uint8_t &subIndex);

    const QString &name() const;
    void setName(const QString &name);

    const QVariant &lowLimit() const;
    void setLowLimit(const QVariant &lowLimit);

    const QVariant &highLimit() const;
    void setHighLimit(const QVariant &highLimit);

    uint8_t flagLimit() const;
    void setFlagLimit(const uint8_t &flagLimit);

    bool hasNodeId() const;
    void setHasNodeId(bool hasNodeId);

    const QVariant &value() const;
    void setValue(const QVariant &value);

    // =============== Data type ==================
    enum Type
    {
        BOOLEAN = 0x0001,
        INTEGER8 = 0x0002,
        INTEGER16 = 0x0003,
        INTEGER32 = 0x0004,
        UNSIGNED8 = 0x0005,
        UNSIGNED16 = 0x0006,
        UNSIGNED32 = 0x0007,
        REAL32 = 0x0008,
        VISIBLE_STRING = 0x0009,
        OCTET_STRING = 0x000A,
        UNICODE_STRING = 0x000B,
        TIME_OF_DAY = 0x000C,
        TIME_DIFFERENCE = 0x000D,
        DDOMAIN = 0x000F,
        INTEGER24 = 0x0010,
        REAL64 = 0x0011,
        INTEGER40 = 0x0012,
        INTEGER48 = 0x0013,
        INTEGER56 = 0x0014,
        INTEGER64 = 0x0015,
        UNSIGNED24 = 0x0016,
        UNSIGNED40 = 0x0018,
        UNSIGNED48 = 0x0019,
        UNSIGNED56 = 0x001A,
        UNSIGNED64 = 0x001B
    };

    uint16_t dataType() const;
    void setDataType(const uint16_t &dataType);
    static QString dataTypeStr(const uint16_t &dataType);

    int length() const;

protected:
    uint8_t _accessType;
    uint8_t _subIndex;
    QString _name;

    QVariant _value;
    uint16_t _dataType;

    uint8_t _flagLimit;
    QVariant _lowLimit;
    QVariant _highLimit;

    bool _hasNodeId;
};

#endif // SUBINDEX_H
