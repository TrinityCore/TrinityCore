/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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

#include "ItemPackets.h"

WorldPacket const* WorldPackets::Item::SetProficiency::Write()
{
    _worldPacket << ProficiencyMask;
    _worldPacket << ProficiencyClass;

    return &_worldPacket;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Item::ItemBonusInstanceData const& itemBonusInstanceData)
{
    data << itemBonusInstanceData.Context;
    data << uint32(itemBonusInstanceData.BonusListIDs.size());
    for (uint32 bonusID : itemBonusInstanceData.BonusListIDs)
        data << bonusID;

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Item::ItemInstance const& itemInstance)
{
    data << itemInstance.ItemID;
    data << itemInstance.RandomPropertiesSeed;
    data << itemInstance.RandomPropertiesID;
    
    data.WriteBit(itemInstance.ItemBonus.HasValue);
    data.WriteBit(!itemInstance.Modifications.empty());
    data.FlushBits();
    
    if (itemInstance.ItemBonus.HasValue)
        data << itemInstance.ItemBonus.Value;
    
    if (!itemInstance.Modifications.empty())
    {
        data << uint32(itemInstance.Modifications.size() * sizeof(uint32));
        for (uint32 itemMod : itemInstance.Modifications)
            data << itemMod;
    }
}
