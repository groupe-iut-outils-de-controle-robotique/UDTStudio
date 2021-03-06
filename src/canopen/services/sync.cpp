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

#include "sync.h"

#include "canopenbus.h"

Sync::Sync(CanOpenBus *bus)
    : Service (bus)
{
    _syncTimer = new QTimer();
    connect(_syncTimer, &QTimer::timeout, this, &Sync::sendSync);
}

void Sync::startSync(int ms)
{
    _syncTimer->start(ms);
}

void Sync::stopSync()
{
    _syncTimer->stop();
}

void Sync::sendSync()
{
    QCanBusFrame frameSync;
    frameSync.setFrameId(0x080);
    _bus->canDevice()->writeFrame(frameSync);
}

void Sync::parseFrame(const QCanBusFrame &frame)
{
    if (frame.frameId() == _syncCobId && frame.payload().isEmpty())
        emit syncEmitted();
}
