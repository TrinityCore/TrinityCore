/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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

#include "CombatPackets.h"

WorldPacket const* WorldPackets::Combat::ThreatUpdate::Write()
{
    _worldPacket << UnitGUID.WriteAsPacked();
    _worldPacket << uint32(ThreatList.size());
    for (WorldPackets::Combat::ThreatInfo const& threatInfo : ThreatList)
    {
        _worldPacket << threatInfo.UnitGUID.WriteAsPacked();
        _worldPacket << uint32(threatInfo.Threat);
    }

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Combat::HighestThreatUpdate::Write()
{
    _worldPacket << UnitGUID.WriteAsPacked();
    _worldPacket << HighestThreatGUID.WriteAsPacked();
    _worldPacket << int32(ThreatList.size());
    for (WorldPackets::Combat::ThreatInfo const& threatInfo : ThreatList)
    {
        _worldPacket << threatInfo.UnitGUID.WriteAsPacked();
        _worldPacket << uint32(threatInfo.Threat);
    }

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Combat::ThreatRemove::Write()
{
    _worldPacket << UnitGUID.WriteAsPacked();
    _worldPacket << AboutGUID.WriteAsPacked();

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Combat::ThreatClear::Write()
{
    _worldPacket << UnitGUID.WriteAsPacked();
    return &_worldPacket;
}
