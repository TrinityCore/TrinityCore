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

#ifndef BattlegroundPackets_h__
#define BattlegroundPackets_h__

#include "ObjectGuid.h"
#include "Packet.h"

namespace WorldPackets
{
    namespace Battleground
    {
        class PVPSeason final : public ServerPacket
        {
        public:
            PVPSeason() : ServerPacket(SMSG_PVP_SEASON, 8) { }

            WorldPacket const* Write() override;

            uint32 PreviousSeason = 0;
            uint32 CurrentSeason = 0;
        };

        class AreaSpiritHealerQuery final : public ClientPacket
        {
        public:
            AreaSpiritHealerQuery(WorldPacket&& packet) : ClientPacket(CMSG_AREA_SPIRIT_HEALER_QUERY, std::move(packet)) { }

            void Read() override;

            ObjectGuid HealerGuid;
        };

        class AreaSpiritHealerQueue final : public ClientPacket
        {
        public:
            AreaSpiritHealerQueue(WorldPacket&& packet) : ClientPacket(CMSG_AREA_SPIRIT_HEALER_QUEUE, std::move(packet)) { }

            void Read() override;

            ObjectGuid HealerGuid;
        };

        class HearthAndResurrect final : public ClientPacket
        {
        public:
            HearthAndResurrect(WorldPacket&& packet) : ClientPacket(CMSG_HEARTH_AND_RESURRECT, std::move(packet)) { }

            void Read() override { }
        };

        class PVPLogDataRequest final : public ClientPacket
        {
        public:
            PVPLogDataRequest(WorldPacket&& packet) : ClientPacket(CMSG_PVP_LOG_DATA, std::move(packet)) { }

            void Read() override { }
        };

        class PVPLogData final : public ServerPacket
        {
        public:
            PVPLogData() : ServerPacket(SMSG_PVP_LOG_DATA, 0) { }

            WorldPacket const* Write() override;

            struct RatingData
            {
                int32 Prematch[2] = { };
                int32 Postmatch[2] = { };
                int32 PrematchMMR[2] = { };
            };

            struct HonorData
            {
                uint32 HonorKills = 0;
                uint32 Deaths = 0;
                uint32 ContributionPoints = 0;
            };

            struct PlayerData
            {
                ObjectGuid PlayerGUID;
                uint32 Kills = 0;
                uint8 Faction = 0;
                bool IsInWorld = false;
                Optional<HonorData> Honor;
                uint32 DamageDone = 0;
                uint32 HealingDone = 0;
                Optional<uint32> PreMatchRating;
                Optional<int32> RatingChange;
                Optional<uint32> PreMatchMMR;
                Optional<int32> MmrChange;
                std::vector<int32> Stats;
                int32 PrimaryTalentTree = 0;
                uint32 PrimaryTalentTreeNameIndex = 0;  // controls which name field from ChrSpecialization.dbc will be sent to lua
            };

            Optional<uint8> Winner;
            std::vector<PlayerData> Players;
            Optional<RatingData> Ratings;
            int8 PlayerCount[2] = { };
        };
    }
}

#endif // BattlegroundPackets_h__
