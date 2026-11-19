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

#include "VignettePackets.h"
#include "PacketOperators.h"

namespace WorldPackets::Vignette
{
ByteBuffer& operator<<(ByteBuffer& data, VignetteData const& vignetteData)
{
    data << vignetteData.Position;
    data << vignetteData.ObjGUID;
    data << int32(vignetteData.VignetteID);
    data << uint32(vignetteData.ZoneID);
    data << uint32(vignetteData.WMOGroupID);
    data << uint32(vignetteData.WMODoodadPlacementID);
    data << float(vignetteData.HealthPercent);
    data << uint16(vignetteData.RecommendedGroupSizeMin);
    data << uint16(vignetteData.RecommendedGroupSizeMax);

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, VignetteDataSet const& vignetteDataSet)
{
    data << Size<uint32>(vignetteDataSet.IDs);
    data << Size<uint32>(vignetteDataSet.Data);
    for (ObjectGuid const& id : vignetteDataSet.IDs)
        data << id;

    for (VignetteData const& vignetteData : vignetteDataSet.Data)
        data << vignetteData;

    return data;
}

WorldPacket const* VignetteUpdate::Write()
{
    _worldPacket << Bits<1>(ForceUpdate);
    _worldPacket << Bits<1>(InFogOfWar);
    _worldPacket << Size<uint32>(Removed);
    _worldPacket << Added;
    _worldPacket << Updated;
    for (ObjectGuid const& removed : Removed)
        _worldPacket << removed;

    return &_worldPacket;
}
}
