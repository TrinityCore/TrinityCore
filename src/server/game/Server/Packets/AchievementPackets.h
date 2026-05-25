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

#ifndef TRINITYCORE_ACHIEVEMENT_PACKETS_H
#define TRINITYCORE_ACHIEVEMENT_PACKETS_H

#include "ObjectGuid.h"
#include "Packet.h"
#include "WowTime.h"

namespace WorldPackets
{
    namespace Achievement
    {
        struct EarnedAchievement
        {
            uint32 Id = 0;
            WowTime Date;
        };

        struct CriteriaProgress
        {
            uint32 Id = 0;
            uint64 Quantity = 0;
            ObjectGuid Player;
            uint32 Flags = 0;
            WowTime Date;
            uint32 TimeFromStart = 0;
            uint32 TimeFromCreate = 0;
        };

        struct AllAchievements
        {
            std::vector<EarnedAchievement> Earned;
            std::vector<CriteriaProgress> Progress;
        };

        class AllAchievementData final : public ServerPacket
        {
        public:
            explicit AllAchievementData() : ServerPacket(SMSG_ALL_ACHIEVEMENT_DATA) { }

            WorldPacket const* Write() override;

            AllAchievements Data;
        };

        class RespondInspectAchievements final : public ServerPacket
        {
        public:
            explicit RespondInspectAchievements() : ServerPacket(SMSG_RESPOND_INSPECT_ACHIEVEMENTS) { }

            WorldPacket const* Write() override;

            ObjectGuid Player;
            AllAchievements Data;
        };

        class CriteriaUpdate final : public ServerPacket
        {
        public:
            CriteriaUpdate() : ServerPacket(SMSG_CRITERIA_UPDATE, 4 + 8 + 8 + 4 + 4 + 4 + 4) { }

            WorldPacket const* Write() override;

            uint32 CriteriaID = 0;
            uint64 Quantity = 0;
            ObjectGuid PlayerGUID;
            uint32 Flags = 0;
            WowTime CurrentTime;
            uint32 ElapsedTime = 0;
            uint32 CreationTime = 0;
        };

        class AchievementEarned final : public ServerPacket
        {
        public:
            AchievementEarned() : ServerPacket(SMSG_ACHIEVEMENT_EARNED, 8 + 4 + 4 + 4) { }

            WorldPacket const* Write() override;

            ObjectGuid Earner;
            uint32 AchievementID = 0;
            WowTime Time;
            bool Initial = false;
        };
    }
}

#endif // TRINITYCORE_ACHIEVEMENT_PACKETS_H
