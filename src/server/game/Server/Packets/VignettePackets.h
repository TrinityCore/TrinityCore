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

#ifndef TRINITYCORE_VIGNETTE_PACKETS_H
#define TRINITYCORE_VIGNETTE_PACKETS_H

#include "ObjectGuid.h"
#include "Packet.h"
#include "Position.h"

namespace WorldPackets::Vignette
{
struct VignetteData
{
    ObjectGuid ObjGUID;
    TaggedPosition<Position::XYZ> Position;
    int32 VignetteID = 0;
    uint32 ZoneID = 0;
    uint32 WMOGroupID = 0;
    uint32 WMODoodadPlacementID = 0;
};

struct VignetteDataSet
{
    std::vector<ObjectGuid> IDs;
    std::vector<VignetteData> Data;
};

class VignetteUpdate final : public ServerPacket
{
public:
    VignetteUpdate() : ServerPacket(SMSG_VIGNETTE_UPDATE, 200) { }

    WorldPacket const* Write() override;

    VignetteDataSet Added;
    VignetteDataSet Updated;
    std::vector<ObjectGuid> Removed;
    bool ForceUpdate = false;
    bool InFogOfWar = false;
};
}

#endif // TRINITYCORE_VIGNETTE_PACKETS_H
