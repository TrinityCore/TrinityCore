/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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

WorldPacket const* WorldPackets::Reputation::InitializeFactions::Write()
{
    for (uint16 i = 0; i < FactionCount; ++i)
    {
        _worldPacket << uint8(FactionFlags[i]);
        _worldPacket << int32(FactionStandings[i]);
    }

    for (uint16 i = 0; i < FactionCount; ++i)
        _worldPacket.WriteBit(FactionHasBonus[i]);

    _worldPacket.FlushBits();

    return &_worldPacket;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Reputation::ForcedReaction const& forcedReaction)
{
    data << int32(forcedReaction.Faction);
    data << int32(forcedReaction.Reaction);
    return data;
}

WorldPacket const* WorldPackets::Reputation::SetForcedReactions::Write()
{
    _worldPacket.WriteBits(Reactions.size(), 6);
    for (ForcedReaction const& reaction : Reactions)
        _worldPacket << reaction;

    _worldPacket.FlushBits();

    return &_worldPacket;
}
