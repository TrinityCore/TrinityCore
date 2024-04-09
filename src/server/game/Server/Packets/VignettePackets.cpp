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

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, VignetteDataSet const& vignetteDataSet)
{
    data << uint32(vignetteDataSet.IDs.size());
    data << uint32(vignetteDataSet.Data.size());
    for (ObjectGuid const& id : vignetteDataSet.IDs)
        data << id;

    for (VignetteData const& vignetteData : vignetteDataSet.Data)
        data << vignetteData;

    return data;
}

WorldPacket const* VignetteUpdate::Write()
{
    _worldPacket.WriteBit(ForceUpdate);
    _worldPacket.WriteBit(InFogOfWar);
    _worldPacket << uint32(Removed.size());
    _worldPacket << Added;
    _worldPacket << Updated;
    for (ObjectGuid const& removed : Removed)
        _worldPacket << removed;

    return &_worldPacket;
}
}
