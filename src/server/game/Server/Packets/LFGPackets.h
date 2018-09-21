/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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
#include "PacketUtilities.h"
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
        class DFJoin final : public ClientPacket
        {
        public:
            DFJoin(WorldPacket&& packet) : ClientPacket(CMSG_DF_JOIN, std::move(packet)) { }

            void Read() override;

            bool QueueAsGroup = false;
            bool Unknown = false;       // Always false in 7.2.5
            uint8 PartyIndex = 0;
            uint32 Roles = 0;
            Array<uint32, 50> Slots;
        };

        class DFLeave final : public ClientPacket
        {
        public:
            DFLeave(WorldPacket&& packet) : ClientPacket(CMSG_DF_LEAVE, std::move(packet)) { }

            void Read() override;

            RideTicket Ticket;
        };

        class DFProposalResponse final : public ClientPacket
        {
        public:
            DFProposalResponse(WorldPacket&& packet) : ClientPacket(CMSG_DF_PROPOSAL_RESPONSE, std::move(packet)) { }

            void Read() override;

            RideTicket Ticket;
            uint64 InstanceID = 0;
            uint32 ProposalID = 0;
            bool Accepted = false;
        };

        class DFSetRoles final : public ClientPacket
        {
        public:
            DFSetRoles(WorldPacket&& packet) : ClientPacket(CMSG_DF_SET_ROLES, std::move(packet)) { }

            void Read() override;

            uint32 RolesDesired = 0;
            uint8 PartyIndex = 0;
        };

        class DFBootPlayerVote final : public ClientPacket
        {
        public:
            DFBootPlayerVote(WorldPacket&& packet) : ClientPacket(CMSG_DF_BOOT_PLAYER_VOTE, std::move(packet)) { }

            void Read() override;

            bool Vote = false;
        };

        class DFTeleport final : public ClientPacket
        {
        public:
            DFTeleport(WorldPacket&& packet) : ClientPacket(CMSG_DF_TELEPORT, std::move(packet)) { }

            void Read() override;

            bool TeleportOut = false;
        };

        class DFGetSystemInfo final : public ClientPacket
        {
        public:
            DFGetSystemInfo(WorldPacket&& packet) : ClientPacket(CMSG_DF_GET_SYSTEM_INFO, std::move(packet)) { }

            void Read() override;

            uint8 PartyIndex = 0;
            bool Player = false;
        };

        class DFGetJoinStatus final : public ClientPacket
        {
        public:
            DFGetJoinStatus(WorldPacket&& packet) : ClientPacket(CMSG_DF_GET_JOIN_STATUS, std::move(packet)) { }

            void Read() override { }
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
            uint32 Mask = 0;                                            // Roles required for this reward, only used by ShortageReward in SMSG_LFG_PLAYER_INFO
            int32 RewardMoney = 0;                                      // Only used by SMSG_LFG_PLAYER_INFO
            int32 RewardXP = 0;
            std::vector<LfgPlayerQuestRewardItem> Item;
            std::vector<LfgPlayerQuestRewardCurrency> Currency;         // Only used by SMSG_LFG_PLAYER_INFO
            std::vector<LfgPlayerQuestRewardCurrency> BonusCurrency;    // Only used by SMSG_LFG_PLAYER_INFO
            Optional<int32> RewardSpellID;                              // Only used by SMSG_LFG_PLAYER_INFO
            Optional<int32> Unused1;
            Optional<uint64> Unused2;
            Optional<int32> Honor;                                      // Only used by SMSG_REQUEST_PVP_REWARDS_RESPONSE
        };

        struct LfgPlayerDungeonInfo
        {
            uint32 Slot = 0;
            int32 CompletionQuantity = 0;
            int32 CompletionLimit = 0;
            int32 CompletionCurrencyID = 0;
            int32 SpecificQuantity = 0;
            int32 SpecificLimit = 0;
            int32 OverallQuantity = 0;
            int32 OverallLimit = 0;
            int32 PurseWeeklyQuantity = 0;
            int32 PurseWeeklyLimit = 0;
            int32 PurseQuantity = 0;
            int32 PurseLimit = 0;
            int32 Quantity = 0;
            uint32 CompletedMask = 0;
            uint32 EncounterMask = 0;
            bool FirstReward = false;
            bool ShortageEligible = false;
            LfgPlayerQuestReward Rewards;
            std::vector<LfgPlayerQuestReward> ShortageReward;
        };

        class LfgPlayerInfo final : public ServerPacket
        {
        public:
            LfgPlayerInfo() : ServerPacket(SMSG_LFG_PLAYER_INFO) { }

            WorldPacket const* Write() override;

            LFGBlackList BlackList;
            std::vector<LfgPlayerDungeonInfo> Dungeon;
        };

        class LfgPartyInfo final : public ServerPacket
        {
        public:
            LfgPartyInfo() : ServerPacket(SMSG_LFG_PARTY_INFO) { }

            WorldPacket const* Write() override;

            std::vector<LFGBlackList> Player;
        };

        class LFGUpdateStatus final : public ServerPacket
        {
        public:
            LFGUpdateStatus() : ServerPacket(SMSG_LFG_UPDATE_STATUS) { }

            WorldPacket const* Write() override;

            RideTicket Ticket;
            uint8 SubType = 0;
            uint8 Reason = 0;
            std::vector<uint32> Slots;
            uint32 RequestedRoles = 0;
            std::vector<ObjectGuid> SuspendedPlayers;
            bool NotifyUI = false;
            bool IsParty = false;
            bool Joined = false;
            bool LfgJoined = false;
            bool Queued = false;
            bool Unused = false;
        };

        class RoleChosen final : public ServerPacket
        {
        public:
            RoleChosen() : ServerPacket(SMSG_ROLE_CHOSEN, 16 + 4 + 1) { }

            WorldPacket const* Write() override;

            ObjectGuid Player;
            uint32 RoleMask = 0;
            bool Accepted = false;
        };

        struct LFGRoleCheckUpdateMember
        {
            LFGRoleCheckUpdateMember() { }
            LFGRoleCheckUpdateMember(ObjectGuid guid, uint32 rolesDesired, uint8 level, bool roleCheckComplete)
                : Guid(guid), RolesDesired(rolesDesired), Level(level), RoleCheckComplete(roleCheckComplete) { }

            ObjectGuid Guid;
            uint32 RolesDesired = 0;
            uint8 Level = 0;
            bool RoleCheckComplete = false;
        };

        class LFGRoleCheckUpdate final : public ServerPacket
        {
        public:
            LFGRoleCheckUpdate() : ServerPacket(SMSG_LFG_ROLE_CHECK_UPDATE) { }

            WorldPacket const* Write() override;

            uint8 PartyIndex = 0;
            uint8 RoleCheckStatus = 0;
            std::vector<uint32> JoinSlots;
            uint64 BgQueueID = 0;
            int32 GroupFinderActivityID = 0;
            std::vector<LFGRoleCheckUpdateMember> Members;
            bool IsBeginning = false;
            bool IsRequeue = false;
        };

        struct LFGJoinBlackListSlot
        {
            LFGJoinBlackListSlot() { }
            LFGJoinBlackListSlot(int32 slot, int32 reason, int32 subReason1, int32 subReason2)
                : Slot(slot), Reason(reason), SubReason1(subReason1), SubReason2(subReason2) { }

            int32 Slot = 0;
            int32 Reason = 0;
            int32 SubReason1 = 0;
            int32 SubReason2 = 0;
        };

        struct LFGJoinBlackList
        {
            ObjectGuid Guid;
            std::vector<LFGJoinBlackListSlot> Slots;
        };

        class LFGJoinResult final : public ServerPacket
        {
        public:
            LFGJoinResult() : ServerPacket(SMSG_LFG_JOIN_RESULT) { }

            WorldPacket const* Write() override;

            RideTicket Ticket;
            uint8 Result = 0;
            uint8 ResultDetail = 0;
            std::vector<LFGJoinBlackList> BlackList;
        };

        class LFGQueueStatus final : public ServerPacket
        {
        public:
            LFGQueueStatus() : ServerPacket(SMSG_LFG_QUEUE_STATUS, 16 + 4 + 4 + 4 + 4 + 4 + 4 + 4 * 3 + 3 + 4) { }

            WorldPacket const* Write() override;

            RideTicket Ticket;
            uint32 Slot = 0;
            uint32 AvgWaitTimeMe = 0;
            uint32 AvgWaitTime = 0;
            uint32 AvgWaitTimeByRole[3] = { };
            uint8 LastNeeded[3] = { };
            uint32 QueuedTime = 0;
        };

        struct LFGPlayerRewards
        {
            LFGPlayerRewards() { }
            LFGPlayerRewards(int32 rewardItem, uint32 rewardItemQuantity, int32 bonusCurrency, bool isCurrency)
                : RewardItem(rewardItem), RewardItemQuantity(rewardItemQuantity), BonusCurrency(bonusCurrency), IsCurrency(isCurrency) { }

            int32 RewardItem = 0;
            uint32 RewardItemQuantity = 0;
            int32 BonusCurrency = 0;
            bool IsCurrency = false;
        };

        class LFGPlayerReward final : public ServerPacket
        {
        public:
            LFGPlayerReward() : ServerPacket(SMSG_LFG_PLAYER_REWARD) { }

            WorldPacket const* Write() override;

            uint32 QueuedSlot = 0;
            uint32 ActualSlot = 0;
            int32 RewardMoney = 0;
            int32 AddedXP = 0;
            std::vector<LFGPlayerRewards> Rewards;
        };

        struct LfgBootInfo
        {
            bool VoteInProgress = false;
            bool VotePassed = false;
            bool MyVoteCompleted = false;
            bool MyVote = false;
            ObjectGuid Target;
            uint32 TotalVotes = 0;
            uint32 BootVotes = 0;
            int32 TimeLeft = 0;
            uint32 VotesNeeded = 0;
            std::string Reason;
        };

        class LfgBootPlayer final : public ServerPacket
        {
        public:
            LfgBootPlayer() : ServerPacket(SMSG_LFG_BOOT_PLAYER) { }

            WorldPacket const* Write() override;

            LfgBootInfo Info;
        };

        struct LFGProposalUpdatePlayer
        {
            uint32 Roles = 0;
            bool Me = false;
            bool SameParty = false;
            bool MyParty = false;
            bool Responded = false;
            bool Accepted = false;
        };

        class LFGProposalUpdate final : public ServerPacket
        {
        public:
            LFGProposalUpdate() : ServerPacket(SMSG_LFG_PROPOSAL_UPDATE) { }

            WorldPacket const* Write() override;

            RideTicket Ticket;
            uint64 InstanceID = 0;
            uint32 ProposalID = 0;
            uint32 Slot = 0;
            int8 State = 0;
            uint32 CompletedMask = 0;
            uint32 EncounterMask = 0;
            uint8 Unused = 0;
            bool ValidCompletedMask = false;
            bool ProposalSilent = false;
            bool IsRequeue = false;
            std::vector<LFGProposalUpdatePlayer> Players;
        };

        class LFGDisabled final : public ServerPacket
        {
        public:
            LFGDisabled() : ServerPacket(SMSG_LFG_DISABLED, 0) { }

            WorldPacket const* Write() override { return &_worldPacket; }
        };

        class LFGOfferContinue final : public ServerPacket
        {
        public:
            LFGOfferContinue(uint32 slot) : ServerPacket(SMSG_LFG_OFFER_CONTINUE, 4), Slot(slot) { }

            WorldPacket const* Write() override;

            uint32 Slot = 0;
        };

        class LFGTeleportDenied final : public ServerPacket
        {
        public:
            LFGTeleportDenied(lfg::LfgTeleportResult reason) : ServerPacket(SMSG_LFG_TELEPORT_DENIED, 1), Reason(reason) { }

            WorldPacket const* Write() override;

            lfg::LfgTeleportResult Reason;
        };
    }
}

#endif // LFGPackets_h__
