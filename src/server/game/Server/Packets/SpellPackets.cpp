/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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

#include "SpellPackets.h"

void WorldPackets::Spells::UpdateProjectilePosition::Read()
{
    _worldPacket >> Guid;
    _worldPacket >> Spell;
    _worldPacket >> Count;
    _worldPacket >> Pos.PositionXYZStream();
}

WorldPackets::Spells::SetProjectilePosition::SetProjectilePosition()
    : ServerPacket(SMSG_SET_PROJECTILE_POSITION, 21) { }

WorldPacket const* WorldPackets::Spells::SetProjectilePosition::Write()
{
    _worldPacket << uint64(Guid);
    _worldPacket << uint8(Count);
    _worldPacket << Position::PositionXYZStreamer(Pos);

    return &_worldPacket;
}
