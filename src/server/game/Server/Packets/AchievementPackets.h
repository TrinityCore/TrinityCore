/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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

#ifndef game_AchievementPackets_h__
#define game_AchievementPackets_h__

#include "ObjectGuid.h"
#include "Packet.h"

namespace WorldPackets
{
    namespace Achievement
    {
        struct EarnedAchievement
        {
            uint32 Id = 0;
            time_t Date = time_t(0);
            ObjectGuid Owner;
            uint32 VirtualRealmAddress = 0;
            uint32 NativeRealmAddress = 0;
        };

        struct CriteriaProgress
        {
            uint32 Id = 0;
            uint64 Quantity = 0;
            ObjectGuid Player;
            uint32 Flags = 0;
            time_t Date = time_t(0);
            uint32 TimeFromStart = 0;
            uint32 TimeFromCreate = 0;
        };

        class AllAchievements final : public ServerPacket
        {
        public:
            AllAchievements() : ServerPacket(SMSG_ALL_ACHIEVEMENT_DATA) { }

            WorldPacket const* Write() override;

            std::vector<EarnedAchievement> Earned;
            std::vector<CriteriaProgress> Progress;
        };

        class CriteriaUpdate final : public ServerPacket
        {
        public:
            CriteriaUpdate() : ServerPacket(SMSG_CRITERIA_UPDATE, 4 + 8 + 16 + 4 + 4 + 4 + 4) { }

            WorldPacket const* Write() override;

            uint32 CriteriaID = 0;
            uint64 Quantity = 0;
            ObjectGuid PlayerGUID;
            uint32 Flags = 0;
            time_t CurrentTime = time_t(0);
            uint32 ElapsedTime = 0;
            uint32 CreationTime = 0;
        };

        class AchievementEarned final : public ServerPacket
        {
        public:
            AchievementEarned() : ServerPacket(SMSG_ACHIEVEMENT_EARNED, 16 + 4 + 4 + 4 + 4 + 1 + 16) { }

            WorldPacket const* Write() override;

            ObjectGuid Earner;
            uint32 EarnerNativeRealm = 0;
            uint32 EarnerVirtualRealm = 0;
            uint32 AchievementID = 0;
            time_t Time = time_t(0);
            bool Initial = false;
            ObjectGuid Sender;
        };
    }
}

#endif // game_AchievementPackets_h__
