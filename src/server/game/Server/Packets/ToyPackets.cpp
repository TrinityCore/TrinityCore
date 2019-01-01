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

    // both lists have to have the same size
    _worldPacket << int32(Toys->size());
    _worldPacket << int32(Toys->size());

    for (auto const& item : *Toys)
        _worldPacket << uint32(item.first);

    for (auto const& favourite : *Toys)
        _worldPacket.WriteBit(favourite.second);

    _worldPacket.FlushBits();

    return &_worldPacket;
}
