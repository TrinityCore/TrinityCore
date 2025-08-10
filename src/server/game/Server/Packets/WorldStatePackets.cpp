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

#include "WorldStatePackets.h"
#include "PacketOperators.h"

namespace WorldPackets::WorldState
{
WorldPacket const* InitWorldStates::Write()
{
    _worldPacket.reserve(16 + Worldstates.size() * 8);

    _worldPacket << int32(MapID);
    _worldPacket << int32(AreaID);
    _worldPacket << int32(SubareaID);

    _worldPacket << Size<uint32>(Worldstates);
    for (WorldStateInfo const& wsi : Worldstates)
    {
        _worldPacket << int32(wsi.VariableID);
        _worldPacket << int32(wsi.Value);
    }

    return &_worldPacket;
}

WorldPacket const* UpdateWorldState::Write()
{
    _worldPacket << uint32(VariableID);
    _worldPacket << int32(Value);
    _worldPacket << Bits<1>(Hidden);
    _worldPacket.FlushBits();

    return &_worldPacket;
}
}
