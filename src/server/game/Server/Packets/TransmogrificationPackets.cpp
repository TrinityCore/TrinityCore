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

#include "TransmogrificationPackets.h"
#include "PacketOperators.h"

namespace WorldPackets::Transmogrification
{
ByteBuffer& operator>>(ByteBuffer& data, TransmogrifyItem& transmogItem)
{
    data >> transmogItem.ItemModifiedAppearanceID;
    data >> transmogItem.Slot;
    data >> transmogItem.SpellItemEnchantmentID;
    data >> transmogItem.SecondaryItemModifiedAppearanceID;

    return data;
}

void TransmogrifyItems::Read()
{
    _worldPacket >> Size<uint32>(Items);
    _worldPacket >> Npc;
    for (TransmogrifyItem& item : Items)
        _worldPacket >> item;

    _worldPacket >> Bits<1>(CurrentSpecOnly);
}

WorldPacket const* AccountTransmogUpdate::Write()
{
    _worldPacket << Bits<1>(IsFullUpdate);
    _worldPacket << Bits<1>(IsSetFavorite);
    _worldPacket << Size<uint32>(FavoriteAppearances);
    _worldPacket << Size<uint32>(NewAppearances);
    if (!FavoriteAppearances.empty())
        _worldPacket.append(FavoriteAppearances.data(), FavoriteAppearances.size());

    if (!NewAppearances.empty())
        _worldPacket.append(NewAppearances.data(), NewAppearances.size());

    return &_worldPacket;
}
}
