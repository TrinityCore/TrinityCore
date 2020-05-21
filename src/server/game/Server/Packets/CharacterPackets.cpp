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

#include "CharacterPackets.h"

void WorldPackets::Character::ShowingCloak::Read()
{
    _worldPacket >> ShowCloak;
}

void WorldPackets::Character::ShowingHelm::Read()
{
    _worldPacket >> ShowHelm;
}

WorldPacket const* WorldPackets::Character::LoginVerifyWorld::Write()
{
    _worldPacket << int32(MapID);
    _worldPacket << Pos;
    return &_worldPacket;
}

WorldPacket const* WorldPackets::Character::LogoutResponse::Write()
{
    _worldPacket << uint32(LogoutResult);
    _worldPacket << uint8(Instant);
    return &_worldPacket;
}

void WorldPackets::Character::PlayedTimeClient::Read()
{
    _worldPacket >> TriggerScriptEvent;
}

WorldPacket const* WorldPackets::Character::PlayedTime::Write()
{
    _worldPacket << uint32(TotalTime);
    _worldPacket << uint32(LevelTime);
    _worldPacket << uint8(TriggerScriptEvent);

    return &_worldPacket;
}
