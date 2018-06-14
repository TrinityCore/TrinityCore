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

#ifndef ChallengeModePackets_h__
#define ChallengeModePackets_h__

#include "Packet.h"
#include "WorldSession.h"

namespace WorldPackets
{
    namespace ChallengeMode
    {
        class StartRequest final : public ClientPacket
        {
        public:
            StartRequest(WorldPacket&& packet) : ClientPacket(CMSG_START_CHALLENGE_MODE, std::move(packet)) { }

            void Read() override;

            uint8 Bag;
            uint32 Slot;
            ObjectGuid GobGUID;
        };

        class ChangePlayerDifficultyResult final : public ServerPacket
        {
        public:
            ChangePlayerDifficultyResult(uint32 type = 0) : ServerPacket(SMSG_CHANGE_PLAYER_DIFFICULTY_RESULT, 4), Type(type) { }

            WorldPacket const* Write() override;

            uint8 Type;
            uint32 InstanceDifficultyID;
            uint32 DifficultyRecID;
        };

        class Start final : public ServerPacket
        {
        public:
            Start() : ServerPacket(SMSG_CHALLENGE_MODE_START, 33) { }

            WorldPacket const* Write() override;

            uint32 MapId;
            uint32 ChallengeId;
            uint32 ChallengeLevel;

            uint32 unk1 = 0;
            uint32 unk2 = 0;
            uint32 unk3 = 0;
            uint32 unk4 = 0;
            uint32 unk5 = 0;

            uint8 unk = 128;
        };

        class Reset final : public ServerPacket
        {
        public:
            Reset(uint32 mapId = 0) : ServerPacket(SMSG_CHALLENGE_MODE_RESET, 4), MapId(mapId) { }

            WorldPacket const* Write() override;

            uint32 MapId;
        };

        class UpdateDeathCount final : public ServerPacket
        {
        public:
            UpdateDeathCount(uint32 deathCount = 0) : ServerPacket(SMSG_CHALLENGE_MODE_UPDATE_DEATH_COUNT, 4), DeathCount(deathCount) { }

            WorldPacket const* Write() override;

            uint32 DeathCount;
        };

        class Complete final : public ServerPacket
        {
        public:
            Complete() : ServerPacket(SMSG_CHALLENGE_MODE_COMPLETE, 4) { }

            WorldPacket const* Write() override;

            uint32 Duration;
            uint32 MapId;
            uint32 ChallengeId;
            uint32 ChallengeLevel;
            uint8 unk = 128;
        };

        class NewPlayerRecord final : public ServerPacket
        {
        public:
            NewPlayerRecord() : ServerPacket(SMSG_CHALLENGE_MODE_NEW_PLAYER_RECORD, 4) { }

            WorldPacket const* Write() override;

            uint32 MapId;
            uint32 Duration;
            uint32 ChallengeLevel;
        };
    }
}

#endif // ChallengeModePackets_h__
