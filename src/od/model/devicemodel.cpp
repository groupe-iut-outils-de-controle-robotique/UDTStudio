/**
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

#include "devicemodel.h"

/**
 * @brief default constructor
 */
DeviceModel::DeviceModel()
{

}

/**
 * @brief default destructor
 */
DeviceModel::~DeviceModel()
{
    qDeleteAll(_indexes);
    _indexes.clear();
}

/**
 * @brief retrun the device model type wich is implemented
 * @return device model type
 */
DeviceModel::Type DeviceModel::type()
{
    return Invalid;
}

/**
 * @brief _fileInfos getter
 * @return a map of strings wich constains some file informations
 */
const QMap<QString, QString> &DeviceModel::fileInfos() const
{
    return _fileInfos;
}

void DeviceModel::setFileInfos(const QMap<QString, QString> &fileInfos)
{
    _fileInfos = fileInfos;
}

/**
 * @brief inserts a new file information with the key key and a value of value
 * @param key
 * @param value
 */
void DeviceModel::setFileInfo(const QString &key, const QString &value)
{
    _fileInfos.insert(key, value);
}

/**
 * @brief _dummyUsages getter
 * @return a map of strings wich contains the dummy usages
 */
const QMap<QString, QString> &DeviceModel::dummyUsages() const
{
    return _dummyUsages;
}

void DeviceModel::setDummyUsages(const QMap<QString, QString> &dummyUsages)
{
    _dummyUsages = dummyUsages;
}

/**
 * @brief inserts a new dummy usage with the key key and a value of value
 * @param key
 * @param value
 */
void DeviceModel::setDummyUsage(const QString &key, const QString &value)
{
    _dummyUsages.insert(key, value);
}

/**
 * @brief _indexes getter
 * @return a map of index wich contains the index of the device model
 */
const QMap<uint16_t, Index *> &DeviceModel::indexes() const
{
    return _indexes;
}

/**
 * @brief returns the value associated with the key index
 * @param index
 * @return an Index*
 */
Index *DeviceModel::index(uint16_t index) const
{
    return _indexes.value(index);
}

/**
 * @brief inserts a new index. If the index already exist, replaces it with the new index
 * @param index
 */
void DeviceModel::addIndex(Index *index)
{
    _indexes.insert(index->index(), index);
}

/**
 * @brief returns the number of index in the map
 * @return number of index
 */
int DeviceModel::indexCount() const
{
    return _indexes.count();
}

/**
 * @brief returns true if the map contains an item with key key; otherwise returns false.
 * @param key
 * @return boolean
 */
bool DeviceModel::indexExist(uint16_t key) const
{
    return _indexes.contains(key);
}

/**
 * @brief return the name of the device file
 * @return string
 */
const QString &DeviceModel::fileName() const
{
    return _fileInfos.value("FileName");
}

/**
 * @brief set the name of the file
 * @param new name
 */
void DeviceModel::setFileName(const QString &name)
{
    _fileInfos.insert("FileName", name);
}
