/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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

WorldPacket const* WorldPackets::Transmogrification::TransmogCollectionUpdate::Write()
{
    _worldPacket.WriteBit(IsFullUpdate);
    _worldPacket.WriteBit(IsSetFavorite);
    _worldPacket << uint32(FavoriteAppearances.size());
    if (!FavoriteAppearances.empty())
        _worldPacket.append(FavoriteAppearances.data(), FavoriteAppearances.size());

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Transmogrification::OpenTransmogrifier::Write()
{
    _worldPacket << Guid;

    return &_worldPacket;
}
