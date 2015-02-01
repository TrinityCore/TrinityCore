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

#ifndef TRINITYCORE_INSPECT_PACKETS_H
#define TRINITYCORE_INSPECT_PACKETS_H

#include "Packet.h"
#include "ObjectGuid.h"
#include "TalentPackets.h"
#include <bitset>

class Item;

namespace WorldPackets
{
    namespace Inspect
    {
        class Inspect final : public ClientPacket
        {
        public:
            explicit Inspect(WorldPacket&& packet) : ClientPacket(CMSG_INSPECT, std::move(packet)) { }

            void Read() override;

            ObjectGuid Target;
        };

        struct InspectItemData
        {
            InspectItemData(::Item const* item);

            ObjectGuid CreatorGUID;
            uint32 ItemID = 0;
            uint32 RandomPropertiesSeed = 0;
            int16 RandomPropertiesID = 0;
            std::bitset<12> EnchantSlots;
            std::vector<uint16> Enchants;
        };

        class InspectResult final : public ServerPacket
        {
        public:
            explicit InspectResult() : ServerPacket(SMSG_INSPECT_TALENT, 8 + 71 * (4 + 1) + 19 * (4 + 2 + 2 + 2 + 1 + 4)) { }

            WorldPacket const* Write() override;

            ObjectGuid InspecteeGUID;
            std::bitset<19> ItemSlots;
            std::vector<InspectItemData> Items;
            Talent::TalentInfoUpdate TalentInfo;
        };

        class RequestHonorStats final : public ClientPacket
        {
        public:
            explicit RequestHonorStats(WorldPacket&& packet) : ClientPacket(MSG_INSPECT_HONOR_STATS, std::move(packet)) { }

            void Read() override;

            ObjectGuid TargetGUID;
        };

        class InspectHonorStats final : public ServerPacket
        {
        public:
            explicit InspectHonorStats() : ServerPacket(MSG_INSPECT_HONOR_STATS, 8 + 1 + 2 + 2 + 4 + 4 + 4) { }

            WorldPacket const* Write() override;

            ObjectGuid PlayerGUID;
            uint8 LifetimeMaxRank = 0;
            uint16 TodayHonorableKills = 0;
            uint16 YesterdayHonorableKills = 0;
            uint32 TodayContribution = 0;
            uint32 YesterdayContribution = 0;
            uint32 LifetimeHonorableKills = 0;
        };

        class QueryInspectAchievements final : public ClientPacket
        {
        public:
            explicit QueryInspectAchievements(WorldPacket&& packet) : ClientPacket(CMSG_QUERY_INSPECT_ACHIEVEMENTS, std::move(packet)) { }

            void Read() override;

            ObjectGuid Guid;
        };
    }
}

#endif // TRINITYCORE_INSPECT_PACKETS_H
