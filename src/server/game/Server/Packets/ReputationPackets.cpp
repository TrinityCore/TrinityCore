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

#include "ReputationPackets.h"

namespace WorldPackets::Reputation
{
ByteBuffer& operator<<(ByteBuffer& data, FactionData const& factionData)
{
    data << uint8(factionData.Flags);
    data << int32(factionData.Standing);

    return data;
}

WorldPacket const* InitializeFactions::Write()
{
    _worldPacket << uint32(Factions.size());

    for (FactionData const& faction : Factions)
        _worldPacket << faction;

    return &_worldPacket;
}
}
