/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

WorldPackets::WorldState::InitWorldStates::InitWorldStates()
    : ServerPacket(SMSG_INIT_WORLD_STATES, 16) { }

WorldPacket const* WorldPackets::WorldState::InitWorldStates::Write()
{
    _worldPacket.reserve(16 + Worldstates.size() * 8);

    _worldPacket << uint32(MapID);
    _worldPacket << uint32(AreaID);
    _worldPacket << uint32(SubareaID);

    std::sort(Worldstates.begin(), Worldstates.end());

    _worldPacket << uint32(Worldstates.size());
    for (WorldStateInfo const& wsi : Worldstates)
    {
        _worldPacket << uint32(wsi.VariableID);
        _worldPacket << int32(wsi.Value);
    }

    return &_worldPacket;
}

WorldPackets::WorldState::UpdateWorldState::UpdateWorldState()
    : ServerPacket(SMSG_UPDATE_WORLD_STATE, 9) { }

WorldPacket const* WorldPackets::WorldState::UpdateWorldState::Write()
{
    _worldPacket << uint32(VariableID);
    _worldPacket << int32(Value);
    _worldPacket.WriteBit(Hidden);
    _worldPacket.FlushBits();

    return &_worldPacket;
}
