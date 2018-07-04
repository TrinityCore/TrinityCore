/*
* Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
*
* This program is free software; you can redistribute it and/or modify it
* under the terms of the GNU General Public License as published by the
* Free Software Foundation; either version 2 of the License, or (at your
* option) any later version.
*
* This program is distributed in the hope that it will be useful, but WITHOUT
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
* FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
* more details.
*
* You should have received a copy of the GNU General Public License along
* with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#include "TaxiPackets.h"

void WorldPackets::Taxi::TaxiNodeStatusQuery::Read()
{
    _worldPacket >> UnitGUID;
}

WorldPacket const* WorldPackets::Taxi::TaxiNodeStatus::Write()
{
    _worldPacket << Unit;
    _worldPacket.WriteBits(Status, 2);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Taxi::ShowTaxiNodes::Write()
{
    _worldPacket.WriteBit(WindowInfo.is_initialized());
    _worldPacket.FlushBits();

    _worldPacket << uint32(CanLandNodes->size());
    _worldPacket << uint32(CanUseNodes->size());

    if (WindowInfo.is_initialized())
    {
        _worldPacket << WindowInfo->UnitGUID;
        _worldPacket << uint32(WindowInfo->CurrentNode);
    }

    _worldPacket.append(CanLandNodes->data(), CanLandNodes->size());
    _worldPacket.append(CanUseNodes->data(), CanUseNodes->size());

    return &_worldPacket;
}

void WorldPackets::Taxi::EnableTaxiNode::Read()
{
    _worldPacket >> Unit;
}

void WorldPackets::Taxi::TaxiQueryAvailableNodes::Read()
{
    _worldPacket >> Unit;
}

void WorldPackets::Taxi::ActivateTaxi::Read()
{
    _worldPacket >> Vendor;
    _worldPacket >> Node;
    _worldPacket >> GroundMountID;
    _worldPacket >> FlyingMountID;
}

WorldPacket const* WorldPackets::Taxi::ActivateTaxiReply::Write()
{
    _worldPacket.WriteBits(Reply, 4);
    _worldPacket.FlushBits();

    return &_worldPacket;
}
