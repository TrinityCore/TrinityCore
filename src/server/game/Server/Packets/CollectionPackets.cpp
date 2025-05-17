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

#include "CollectionPackets.h"
#include "PacketUtilities.h"

namespace WorldPackets::Collections
{
void CollectionItemSetFavorite::Read()
{
    _worldPacket >> As<uint8>(Type);
    _worldPacket >> ID;
    _worldPacket >> Bits<1>(IsFavorite);
}

ByteBuffer& operator<<(ByteBuffer& data, ItemCollectionItemData const& item)
{
    data << int32(item.ID);
    data << uint8(item.Type);
    data << int64(item.Unknown1110);
    data << int32(item.Flags);

    return data;
}

WorldPacket const* AccountItemCollectionData::Write()
{
    _worldPacket << uint32(Unknown1110_1);
    _worldPacket << uint8(Type);
    _worldPacket << uint32(Items.size());

    for (ItemCollectionItemData const& item : Items)
        _worldPacket << item;

    _worldPacket << Bits<1>(Unknown1110_2);
    _worldPacket.FlushBits();

    return &_worldPacket;
}
}
