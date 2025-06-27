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

#include "LFGPackets.h"

void WorldPackets::LFG::LFGJoin::Read()
{
    _worldPacket >> Roles;
    _worldPacket >> NoPartialClear;
    _worldPacket >> Achievements;
    Slots.resize(_worldPacket.read<uint8>());
    for (uint32& slot : Slots)
        _worldPacket >> slot;

    _worldPacket.read_skip<uint8>(); // Needs count, hardcoded to 3 in client
    for (uint8& needs : Needs)
        _worldPacket >> needs;

    _worldPacket >> Comment;
}
