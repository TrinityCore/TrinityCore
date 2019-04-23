/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
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

#include "PetBattlePackets.h"

ByteBuffer& operator>>(ByteBuffer& data, WorldPackets::PetBattle::PetBattleLocation& petBattleLocation)
{
    data >> petBattleLocation.LocationResult;
    data >> petBattleLocation.BattleOrigin;
    data >> petBattleLocation.BattleFacing;

    for (uint8 i = 0; i < 2; ++i)
        data >> petBattleLocation.PlayerPositions[i];

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::PetBattle::PetBattleLocation& petBattleLocation)
{
    data << petBattleLocation.LocationResult;
    data << petBattleLocation.BattleOrigin;
    data << petBattleLocation.BattleFacing;

    for (uint8 i = 0; i < 2; ++i)
        data << petBattleLocation.PlayerPositions[i];

    return data;
}

void WorldPackets::PetBattle::RequestWild::Read()
{
    _worldPacket >> TargetGUID;
    _worldPacket >> Location;
}

WorldPacket const* WorldPackets::PetBattle::RequestFailed::Write()
{
    _worldPacket << uint8(Reason);
    return &_worldPacket;
}

WorldPacket const* WorldPackets::PetBattle::FinalizeLocation::Write()
{
    _worldPacket << Location;
    return &_worldPacket;
}

WorldPacket const* WorldPackets::PetBattle::InitialUpdate::Write()
{
    /*for (var i = 0; i < 2; ++i)
        ReadPetBattlePlayerUpdate(packet, idx, "Players", i);

    for (var i = 0; i < 3; ++i)
        ReadPetBattleEnviroUpdate(packet, idx, "Enviros", i);

    packet.ReadInt16("WaitingForFrontPetsMaxSecs", idx);
    packet.ReadInt16("PvpMaxRoundTime", idx);

    packet.ReadInt32("CurRound", idx);
    packet.ReadInt32("NpcCreatureID", idx);
    packet.ReadInt32("NpcDisplayID", idx);

    packet.ReadByte("CurPetBattleState", idx);
    packet.ReadByte("ForfeitPenalty", idx);

    packet.ReadPackedGuid128("InitialWildPetGUID", idx);

    packet.ReadBit("IsPVP", idx);
    packet.ReadBit("CanAwardXP", idx);*/

    return &_worldPacket;
}
