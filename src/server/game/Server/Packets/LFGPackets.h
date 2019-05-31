/*
 * Copyright (C) 2008-2019 TrinityCore <http://www.trinitycore.org/>
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

#ifndef LFGPackets_h__
#define LFGPackets_h__

#include "Packet.h"
#include "LFGPacketsCommon.h"
#include "Optional.h"

namespace lfg
{
    enum LfgTeleportResult : uint8;
}

namespace WorldPackets
{
    namespace LFG
    {
        class LFGJoin final : public ClientPacket
        {
        public:
            LFGJoin(WorldPacket&& packet) : ClientPacket(CMSG_LFG_JOIN, std::move(packet)) { }

            void Read() override;

            uint32 Roles = 0;
            std::string Comment;
            Array<uint32, 50> Slots;
        };

        class LFGLeave final : public ClientPacket
        {
        public:
            LFGLeave(WorldPacket&& packet) : ClientPacket(CMSG_LFG_LEAVE, std::move(packet)) { }

            void Read() override;

            RideTicket Ticket;
        };

        class LFGProposalResponse final : public ClientPacket
        {
        public:
            LFGProposalResponse(WorldPacket&& packet) : ClientPacket(CMSG_LFG_PROPOSAL_RESULT, std::move(packet)) { }

            void Read() override;

            RideTicket Ticket;
            uint64 InstanceID = 0;
            uint32 ProposalID = 0;
            bool Accepted = false;
        };

        class LFGSetRoles final : public ClientPacket
        {
        public:
            LFGSetRoles(WorldPacket&& packet) : ClientPacket(CMSG_LFG_SET_ROLES, std::move(packet)) { }

            void Read() override;

            uint32 RolesDesired = 0;
        };

        class LFGSetComment final : public ClientPacket
        {
        public:
            LFGSetComment(WorldPacket&& packet) : ClientPacket(CMSG_LFG_SET_COMMENT, std::move(packet)) { }

            void Read() override;

            std::string Comment;
        };

        class LFGBootPlayerVote final : public ClientPacket
        {
        public:
            LFGBootPlayerVote(WorldPacket&& packet) : ClientPacket(CMSG_LFG_SET_BOOT_VOTE, std::move(packet)) { }

            void Read() override;

            bool Vote = false;
        };

        class LFGTeleport final : public ClientPacket
        {
        public:
            LFGTeleport(WorldPacket&& packet) : ClientPacket(CMSG_LFG_TELEPORT, std::move(packet)) { }

            void Read() override;

            bool TeleportOut = false;
        };

        class LFGGetSystemInfo final : public ClientPacket
        {
        public:
            LFGGetSystemInfo(WorldPacket&& packet) : ClientPacket(CMSG_LFG_LOCK_INFO_REQUEST, std::move(packet)) { }

            void Read() override;

            bool Player = false;
        };

        struct LFGBlackListSlot
        {
            LFGBlackListSlot() { }
            LFGBlackListSlot(uint32 slot, uint32 reason, int32 subReason1, int32 subReason2)
                : Slot(slot), Reason(reason), SubReason1(subReason1), SubReason2(subReason2) { }

            uint32 Slot = 0;
            uint32 Reason = 0;
            int32 SubReason1 = 0;
            int32 SubReason2 = 0;
        };

        struct LFGBlackList
        {
            Optional<ObjectGuid> PlayerGuid;
            std::vector<LFGBlackListSlot> Slot;
        };

        struct LfgPlayerQuestRewardItem
        {
            LfgPlayerQuestRewardItem() { }
            LfgPlayerQuestRewardItem(int32 itemId, int32 quantity) : ItemID(itemId), Quantity(quantity) { }

            int32 ItemID = 0;
            int32 Quantity = 0;
        };

        struct LfgPlayerQuestRewardCurrency
        {
            LfgPlayerQuestRewardCurrency() { }
            LfgPlayerQuestRewardCurrency(int32 currencyID, int32 quantity) : CurrencyID(currencyID), Quantity(quantity) { }

            int32 CurrencyID = 0;
            int32 Quantity = 0;
        };

        struct LfgPlayerQuestReward
        {
            int32 RewardMoney = 0;                                      // Only used by SMSG_LFG_PLAYER_INFO
            int32 RewardXP = 0;
            std::vector<LfgPlayerQuestRewardItem> Item;
            std::vector<LfgPlayerQuestRewardCurrency> Currency;         // Only used by SMSG_LFG_PLAYER_INFO
            Optional<int32> Honor;                                      // Only used by SMSG_REQUEST_PVP_REWARDS_RESPONSE
        };

        struct LfgPlayerDungeonInfo
        {
            uint32 Slot = 0;
            uint32 CompletionQuantity = 0;
            uint32 CompletionLimit = 0;
            uint32 CompletionCurrencyID = 0;
            uint32 SpecificQuantity = 0;
            uint32 SpecificLimit = 0;
            uint32 OverallQuantity = 0;
            uint32 OverallLimit = 0;
            uint32 PurseWeeklyQuantity = 0;
            uint32 PurseWeeklyLimit = 0;
            uint32 PurseQuantity = 0;
            uint32 PurseLimit = 0;
            uint32 Quantity = 0;
            uint32 CompletedMask = 0;
            uint32 ShortageRoleMask = 0;
            bool ShortageEligible = false;
            bool FirstReward = false;
            LfgPlayerQuestReward Rewards;
            LfgPlayerQuestReward ShortageReward;
        };

        class LFGPlayerInfo final : public ServerPacket
        {
        public:
            LFGPlayerInfo() : ServerPacket(SMSG_LFG_PLAYER_INFO) { }

            WorldPacket const* Write() override;

            LFGBlackList BlackList;
            std::vector<LfgPlayerDungeonInfo> Dungeon;
        };

        class LFGPartyInfo final : public ServerPacket
        {
        public:
            LFGPartyInfo() : ServerPacket(SMSG_LFG_PARTY_INFO) { }

            WorldPacket const* Write() override;
            std::vector<LFGBlackList> Player;
        };

        class LFGUpdateStatus final : public ServerPacket
        {
        public:
            LFGUpdateStatus() : ServerPacket(SMSG_LFG_UPDATE_STATUS) { }

            WorldPacket const* Write() override;

            RideTicket Ticket;
            uint8 Reason = 0;
            std::vector<uint32> Slots;
            uint32 RequestedRoles = 0;
            std::vector<ObjectGuid> SuspendedPlayers;
            std::string Comment;
            bool IsParty = false;
            bool Joined = false;
            bool LfgJoined = false;
            bool Queued = false;
        };
    }
}

#endif // LFGPackets_h__
