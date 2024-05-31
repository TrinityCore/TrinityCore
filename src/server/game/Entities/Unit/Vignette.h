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

#ifndef TRINITYCORE_VIGNETTE_H
#define TRINITYCORE_VIGNETTE_H

#include "ObjectGuid.h"
#include "Position.h"
#include <memory>

struct VignetteEntry;
class Player;
class WorldObject;

namespace WorldPackets::Vignette
{
struct VignetteDataSet;
}

namespace Vignettes
{
struct VignetteData
{
    ObjectGuid Guid;
    ObjectGuid Object;
    ::Position Position;
    VignetteEntry const* Data;
    uint32 ZoneID = 0;
    uint32 WMOGroupID = 0;
    uint32 WMODoodadPlacementID = 0;
    bool NeedUpdate = false;

    void FillPacket(WorldPackets::Vignette::VignetteDataSet& dataSet) const;
};

std::unique_ptr<VignetteData> Create(VignetteEntry const* vignetteData, WorldObject const* owner);
void Update(VignetteData& vignette, WorldObject const* owner);
void Remove(VignetteData& vignette, WorldObject const* owner);

bool CanSee(Player const* player, VignetteData const& vignette);
}

#endif // TRINITYCORE_VIGNETTE_H
