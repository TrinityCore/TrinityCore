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

#include "ArenaPackets.h"
#include "PacketUtilities.h"

WorldPacket const* WorldPackets::Arena::PvpSeason::Write()
{
    _worldPacket << int32(Unk0);
    _worldPacket << int32(Unk1);
    _worldPacket << int32(CurrentArenaSeason);
    _worldPacket << int32(PreviousArenaSeason);
    _worldPacket << int32(CurrentArenaUsesTeams);
    _worldPacket << int32(PreviousArenaUsesTeams);
    _worldPacket << int32(Unk6);
    _worldPacket << Bits<1>(Unk7);
    _worldPacket << Bits<1>(Unk8);
    _worldPacket << Bits<1>(Unk9);
    _worldPacket.FlushBits();

    return &_worldPacket;
}
