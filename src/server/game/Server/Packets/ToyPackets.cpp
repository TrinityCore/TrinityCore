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

void WorldPackets::Toy::AddToy::Read()
{
    _worldPacket >> Guid;
}

void WorldPackets::Toy::UseToy::Read()
{
    _worldPacket >> Cast;
}

WorldPacket const* WorldPackets::Toy::AccountToysUpdate::Write()
{
    _worldPacket.WriteBit(IsFullUpdate);
    _worldPacket.FlushBits();

    // all lists have to have the same size
    _worldPacket << int32(Toys->size()); // ids
    _worldPacket << int32(Toys->size()); // favorites
    _worldPacket << int32(Toys->size()); // fanfare

    for (auto const& toy : *Toys)
        _worldPacket << uint32(toy.first);

    for (auto const& toy : *Toys)
        _worldPacket.WriteBit(toy.second.HasFlag(ToyFlags::Favorite));

    for (auto const& toy : *Toys)
        _worldPacket.WriteBit(toy.second.HasFlag(ToyFlags::HasFanfare));

    _worldPacket.FlushBits();

    return &_worldPacket;
}

void WorldPackets::Toy::ToyClearFanfare::Read()
{
    _worldPacket >> ItemID;
}
