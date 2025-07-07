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

#include "ToyPackets.h"
#include "PacketOperators.h"

namespace WorldPackets::Toy
{
void AddToy::Read()
{
    _worldPacket >> Guid;
}

void UseToy::Read()
{
    _worldPacket >> Cast;
}

WorldPacket const* AccountToyUpdate::Write()
{
    _worldPacket << Bits<1>(IsFullUpdate);
    _worldPacket.FlushBits();

    // all lists have to have the same size
    _worldPacket << Size<uint32>(*Toys); // ids
    _worldPacket << Size<uint32>(*Toys); // favorites
    _worldPacket << Size<uint32>(*Toys); // fanfare

    for (auto const& [itemId, _] : *Toys)
        _worldPacket << uint32(itemId);

    for (auto const& [_, flags] : *Toys)
        _worldPacket << Bits<1>(flags.HasFlag(ToyFlags::Favorite));

    for (auto const& [_, flags] : *Toys)
        _worldPacket << Bits<1>(flags.HasFlag(ToyFlags::HasFanfare));

    _worldPacket.FlushBits();

    return &_worldPacket;
}

void ToyClearFanfare::Read()
{
    _worldPacket >> ItemID;
}
}
