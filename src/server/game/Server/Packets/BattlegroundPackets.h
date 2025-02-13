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

#ifndef BattlegroundPackets_h__
#define BattlegroundPackets_h__

#include "Packet.h"
#include "ObjectGuid.h"
#include "Optional.h"
#include "Position.h"
#include <array>
#include <variant>

namespace WorldPackets
{
    namespace Battleground
    {
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

        class AreaSpiritHealerTime final : public ServerPacket
        {
        public:
            AreaSpiritHealerTime() : ServerPacket(SMSG_AREA_SPIRIT_HEALER_TIME, 8 + 4) { }

            WorldPacket const* Write() override;

            ObjectGuid HealerGuid;
            int32 TimeLeft = 0;
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
            PVPLogDataRequest(WorldPacket&& packet) : ClientPacket(MSG_PVP_LOG_DATA, std::move(packet)) { }

            void Read() override { }
        };

        struct PVPLogData_RatingData
        {
            std::array<int32,2 > Prematch = { };
            std::array<int32,2 > Postmatch = { };
            std::array<int32,2 > PrematchMMR = { };
        };

        struct PVPLogData_Arena
        {
            PVPLogData_RatingData Ratings;
            std::array<std::string_view, 2> TeamName;
        };

        struct PVPLogData_Honor
        {
            uint32 HonorKills = 0;
            uint32 Deaths = 0;
            uint32 ContributionPoints = 0;
        };

        struct PVPLogData_Player
        {
            ObjectGuid PlayerGUID;
            uint32 Kills = 0;
            std::variant<PVPLogData_Honor, uint8> HonorOrFaction;
            uint32 DamageDone = 0;
            uint32 HealingDone = 0;
            std::vector<uint32> Stats;
        };

        class PVPMatchStatistics final : public ServerPacket
        {
        public:
            PVPMatchStatistics() : ServerPacket(MSG_PVP_LOG_DATA, 0) { }

            WorldPacket const* Write() override;

            Optional<uint8> Winner;
            std::vector<PVPLogData_Player> Players;
            Optional<PVPLogData_Arena> Arena;
        };

        struct BattlefieldStatusHeader
        {
            uint32 QueueSlot = 0;
            uint64 QueueID = 0;
            uint8 RangeMin = 0;
            uint8 RangeMax = 0;
            uint32 InstanceID = 0;
            bool RegisteredMatch = false;
        };

        class BattlefieldStatusNone final : public ServerPacket
        {
        public:
            BattlefieldStatusNone() : ServerPacket(SMSG_BATTLEFIELD_STATUS, 4 + 8) { }

            WorldPacket const* Write() override;

            uint32 QueueSlot = 0;
        };

        class BattlefieldStatusNeedConfirmation final : public ServerPacket
        {
        public:
            BattlefieldStatusNeedConfirmation() : ServerPacket(SMSG_BATTLEFIELD_STATUS, 4 + 4 + sizeof(BattlefieldStatusHeader) + 8) { }

            WorldPacket const* Write() override;

            uint32 Timeout = 0;
            uint32 Mapid = 0;
            BattlefieldStatusHeader Hdr;
            uint64 RandomQueueID = 0;
        };

        class BattlefieldStatusActive final : public ServerPacket
        {
        public:
            BattlefieldStatusActive() : ServerPacket(SMSG_BATTLEFIELD_STATUS, sizeof(BattlefieldStatusHeader) + 4 + 1 + 4 + 4 + 8) { }

            WorldPacket const* Write() override;

            BattlefieldStatusHeader Hdr;
            uint32 ShutdownTimer = 0;
            uint8 ArenaFaction = 0;
            uint32 StartTimer = 0;
            uint32 Mapid = 0;
            uint64 RandomQueueID = 0;
        };

        class BattlefieldStatusQueued final : public ServerPacket
        {
        public:
            BattlefieldStatusQueued() : ServerPacket(SMSG_BATTLEFIELD_STATUS, 4 + sizeof(BattlefieldStatusHeader) + 4) { }

            WorldPacket const* Write() override;

            uint32 AverageWaitTime = 0;
            BattlefieldStatusHeader Hdr;
            uint32 WaitTime = 0;
        };

        class GroupJoinedBattleground final : public ServerPacket
        {
        public:
            GroupJoinedBattleground() : ServerPacket(SMSG_GROUP_JOINED_BATTLEGROUND, 8 + 4) { }

            WorldPacket const* Write() override;

            ObjectGuid ClientID;
            int32 Reason = 0;
        };

        using BattlefieldStatusFailed = GroupJoinedBattleground;

        class BattlemasterJoin final : public ClientPacket
        {
        public:
            BattlemasterJoin(WorldPacket&& packet) : ClientPacket(CMSG_BATTLEMASTER_JOIN, std::move(packet)) { }

            void Read() override;

            ObjectGuid BattlemasterGuid;
            uint32 BattlemasterListID = 0;
            uint32 InstanceID = 0;
            bool JoinAsGroup = false;
        };

        class BattlemasterJoinArena final : public ClientPacket
        {
        public:
            BattlemasterJoinArena(WorldPacket&& packet) : ClientPacket(CMSG_BATTLEMASTER_JOIN_ARENA, std::move(packet)) { }

            void Read() override;

            ObjectGuid BattlemasterGuid;
            uint8 TeamSizeIndex = 0;
            bool JoinAsGroup = false;
            bool IsRated = false;
        };

        class BattlefieldLeave final : public ClientPacket
        {
        public:
            BattlefieldLeave(WorldPacket&& packet) : ClientPacket(CMSG_LEAVE_BATTLEFIELD, std::move(packet)) { }

            void Read() override;

            uint64 QueueID = 0;
        };

        class BattlefieldPort final : public ClientPacket
        {
        public:
            BattlefieldPort(WorldPacket&& packet) : ClientPacket(CMSG_BATTLEFIELD_PORT, std::move(packet)) { }

            void Read() override;

            uint64 QueueID = 0;
            bool AcceptedInvite = false;
        };

        class BattlefieldListRequest final : public ClientPacket
        {
        public:
            BattlefieldListRequest(WorldPacket&& packet) : ClientPacket(CMSG_BATTLEFIELD_LIST, std::move(packet)) { }

            void Read() override;

            int32 ListID = 0;
            bool PvpAnywhere = false;
            bool NoXpGain = false;
        };

        class BattlefieldList final : public ServerPacket
        {
        public:
            BattlefieldList() : ServerPacket(SMSG_BATTLEFIELD_LIST, 8 + 1 + 4 + 1 + 1 + 1 + 4 + 4 + 4 + 1 + 1 + 4 + 4 + 4 + 4) { }

            WorldPacket const* Write() override;

            ObjectGuid BattlemasterGuid;
            int32 BattlemasterListID = 0;
            uint8 MinLevel = 0;
            uint8 MaxLevel = 0;
            std::set<uint32> const* Battlefields = nullptr;
            bool PvpAnywhere = false;
            bool HasHolidayWinToday = false;
            uint32 HolidayWinHonorCurrencyBonus = 0;
            uint32 HolidayFirstWinArenaCurrencyBonus = 0;
            uint32 HolidayLossHonorCurrencyBonus = 0;
            bool HasRandomWinToday = false;
            uint32 RandomWinHonorCurrencyBonus = 0;
            uint32 RandomFirstWinArenaCurrencyBonus = 0;
            uint32 RandomLossHonorCurrencyBonus = 0;
        };

        class RequestBattlefieldStatus final : public ClientPacket
        {
        public:
            RequestBattlefieldStatus(WorldPacket&& packet) : ClientPacket(CMSG_BATTLEFIELD_STATUS, std::move(packet)) { }

            void Read() override { }
        };

        class ReportPvPPlayerAFK final : public ClientPacket
        {
        public:
            ReportPvPPlayerAFK(WorldPacket&& packet) : ClientPacket(CMSG_REPORT_PVP_AFK, std::move(packet)) { }

            void Read() override;

            ObjectGuid Offender;
        };

        class ReportPvPPlayerAFKResult final : public ServerPacket
        {
        public:
            ReportPvPPlayerAFKResult() : ServerPacket(SMSG_REPORT_PVP_AFK_RESULT, 8 + 1 + 1 + 1) { }

            WorldPacket const* Write() override;

            enum ResultCode : uint8
            {
                PVP_REPORT_AFK_SUCCESS = 0,
                PVP_REPORT_AFK_GENERIC_FAILURE = 1, // there are more error codes but they are impossible to receive without modifying the client
                PVP_REPORT_AFK_SYSTEM_ENABLED = 5,
                PVP_REPORT_AFK_SYSTEM_DISABLED = 6
            };

            ObjectGuid Offender;
            uint8 NumPlayersIHaveReported = 0;
            uint8 NumBlackMarksOnOffender = 0;
            uint8 Result = PVP_REPORT_AFK_GENERIC_FAILURE;
        };

        class BattlegroundPlayerPositionsRequest final : public ClientPacket
        {
        public:
            BattlegroundPlayerPositionsRequest(WorldPacket&& packet) : ClientPacket(MSG_BATTLEGROUND_PLAYER_POSITIONS, std::move(packet)) { }

            void Read() override { }
        };

        struct BattlegroundPlayerPosition
        {
            BattlegroundPlayerPosition() { }
            BattlegroundPlayerPosition(ObjectGuid const& guid, TaggedPosition<Position::XY> const& pos) : Guid(guid), Pos(pos) { }

            ObjectGuid Guid;
            TaggedPosition<Position::XY> Pos;
        };

        class BattlegroundPlayerPositions final : public ServerPacket
        {
        public:
            BattlegroundPlayerPositions() : ServerPacket(MSG_BATTLEGROUND_PLAYER_POSITIONS, 4 + 4) { }

            WorldPacket const* Write() override;

            std::vector<BattlegroundPlayerPosition> Players;
            std::vector<BattlegroundPlayerPosition> FlagCarriers;
        };

        class BattlegroundPlayerJoined final : public ServerPacket
        {
        public:
            BattlegroundPlayerJoined() : ServerPacket(SMSG_BATTLEGROUND_PLAYER_JOINED, 8) { }

            WorldPacket const* Write() override;

            ObjectGuid Guid;
        };

        class BattlegroundPlayerLeft final : public ServerPacket
        {
        public:
            BattlegroundPlayerLeft() : ServerPacket(SMSG_BATTLEGROUND_PLAYER_LEFT, 8) { }

            WorldPacket const* Write() override;

            ObjectGuid Guid;
        };

        class DestroyArenaUnit final : public ServerPacket
        {
        public:
            DestroyArenaUnit() : ServerPacket(SMSG_ARENA_UNIT_DESTROYED, 8) { }

            WorldPacket const* Write() override;

            ObjectGuid Guid;
        };
    }
}

#endif // BattlegroundPackets_h__
