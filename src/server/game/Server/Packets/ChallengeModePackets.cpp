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

#include "ChallengeModePackets.h"

void WorldPackets::ChallengeMode::StartRequest::Read()
{
    _worldPacket >> Bag;
    _worldPacket >> Slot;
    _worldPacket >> GobGUID;
}

WorldPacket const* WorldPackets::ChallengeMode::ChangePlayerDifficultyResult::Write()
{
    _worldPacket.WriteBits(Type, 4);

    switch (Type)
    {
        case 5:
        {
            _worldPacket.WriteBit(false);
            _worldPacket << uint32(2766309915);
            break;
        }
        case 11:
        {
            _worldPacket << InstanceDifficultyID;
            _worldPacket << DifficultyRecID;
            break;
        }
    }

    return &_worldPacket;
}

WorldPacket const* WorldPackets::ChallengeMode::Start::Write()
{
    _worldPacket << (uint32)MapId;
    _worldPacket << (uint32)ChallengeId;
    _worldPacket << (uint32)ChallengeLevel;

    _worldPacket << (uint32)unk1;
    _worldPacket << (uint32)unk2;
    _worldPacket << (uint32)unk3;
    _worldPacket << (uint32)unk4;
    _worldPacket << (uint32)unk5;

    _worldPacket << (int8)unk;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::ChallengeMode::Reset::Write()
{
    _worldPacket << (uint32)MapId;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::ChallengeMode::UpdateDeathCount::Write()
{
    _worldPacket << (uint32)DeathCount;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::ChallengeMode::Complete::Write()
{
    _worldPacket << (uint32)Duration;
    _worldPacket << (uint32)MapId;
    _worldPacket << (uint32)ChallengeId;
    _worldPacket << (uint32)ChallengeLevel;

    _worldPacket << (uint8)unk;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::ChallengeMode::NewPlayerRecord::Write()
{
    _worldPacket << (uint32)MapId;
    _worldPacket << (uint32)Duration;
    _worldPacket << (uint32)ChallengeLevel;

    return &_worldPacket;
}
