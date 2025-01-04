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

#include "AzeritePackets.h"
#include "Util.h"

WorldPacket const* WorldPackets::Azerite::PlayerAzeriteItemGains::Write()
{
    _worldPacket << ItemGUID;
    _worldPacket << uint64(XP);

    return &_worldPacket;
}

void WorldPackets::Azerite::AzeriteEssenceUnlockMilestone::Read()
{
    _worldPacket >> AzeriteItemMilestonePowerID;
}

void WorldPackets::Azerite::AzeriteEssenceActivateEssence::Read()
{
    _worldPacket >> AzeriteEssenceID;
    _worldPacket >> Slot;
}

WorldPacket const* WorldPackets::Azerite::ActivateEssenceFailed::Write()
{
    _worldPacket.WriteBits(AsUnderlyingType(Reason), 4);
    _worldPacket.WriteBit(Slot.has_value());
    _worldPacket << int32(Arg);
    _worldPacket << int32(AzeriteEssenceID);
    if (Slot)
        _worldPacket << uint8(*Slot);

    return &_worldPacket;
}

void WorldPackets::Azerite::AzeriteEmpoweredItemViewed::Read()
{
    _worldPacket >> ItemGUID;
}

void WorldPackets::Azerite::AzeriteEmpoweredItemSelectPower::Read()
{
    _worldPacket >> ContainerSlot;
    _worldPacket >> Slot;
    _worldPacket >> Tier;
    _worldPacket >> AzeritePowerID;
}

WorldPacket const* WorldPackets::Azerite::PlayerAzeriteItemEquippedStatusChanged::Write()
{
    _worldPacket.WriteBit(IsHeartEquipped);
    _worldPacket.FlushBits();

    return &_worldPacket;
}
