/*
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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

#include "TransmogrificationPackets.h"

ByteBuffer& operator>>(ByteBuffer& data, WorldPackets::Transmogrification::TransmogrifyItem& transmogItem)
{
    data >> transmogItem.ItemModifiedAppearanceID;
    data >> transmogItem.Slot;
    data >> transmogItem.SpellItemEnchantmentID;

    return data;
}

void WorldPackets::Transmogrification::TransmogrifyItems::Read()
{
    Items.resize(_worldPacket.read<uint32>());
    _worldPacket >> Npc;
    for (TransmogrifyItem& item : Items)
        _worldPacket >> item;

    CurrentSpecOnly = _worldPacket.ReadBit();
}

void WorldPackets::Transmogrification::TransmogAppearanceSetFavorite::Read()
{
    _worldPacket >> ItemModifiedAppearanceID;
    IsFavorite = _worldPacket.ReadBit();
}

WorldPacket const* WorldPackets::Transmogrification::TransmogCollectionUpdate::Write()
{
    _worldPacket.WriteBit(IsFullUpdate);
    _worldPacket.WriteBit(IsSetFavorite);
    _worldPacket << uint32(FavoriteAppearances.size());
    for (uint32 itemModifiedAppearanceId : FavoriteAppearances)
        _worldPacket << uint32(itemModifiedAppearanceId);

    return &_worldPacket;
}
