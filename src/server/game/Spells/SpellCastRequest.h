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

#ifndef SpellCastRequest_h__
#define SpellCastRequest_h__

#include "SpellPackets.h"

struct SpellCastRequestItemData
{
    SpellCastRequestItemData(uint8 packSlot, uint8 slot, ObjectGuid castItem) :
        PackSlot(packSlot), Slot(slot), CastItem(castItem) { }

    uint8 PackSlot = 0;
    uint8 Slot = 0;
    ObjectGuid CastItem;
};

struct SpellCastRequest
{
    SpellCastRequest(WorldPackets::Spells::SpellCastRequest&& castRequest, ObjectGuid castingUnitGUID, Optional<SpellCastRequestItemData> itemData = {}) :
        CastRequest(castRequest), CastingUnitGUID(castingUnitGUID), ItemData(itemData) { }

    WorldPackets::Spells::SpellCastRequest CastRequest;
    ObjectGuid CastingUnitGUID;
    Optional<SpellCastRequestItemData> ItemData;
};

#endif // SpellCastRequest_h__
